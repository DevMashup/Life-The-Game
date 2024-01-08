#include "ShopsD_I.h"

MASH_str ShopsD_I::Folder = " ";
MASH_b ShopsD_I::isData = false;
MASH_uint ShopsD_I::Counter = 0;

void ShopsD_I::CreateData()
{
	CreateFolder();
	UpdateGlobalFile();
}

void ShopsD_I::CreateFolder()
{
	Universal u;

	Folder = ShopsD::Folder + "/In Person";

	if (!MASH_fs::exists(Folder)) {
		if (MASH_fs::create_directory(Folder)) {
			u.MASH_LOG("Successfully created directory");
			u.SV(2);
		}
		else
		{
			u.MASH_LOG("[ERROR]: Could not create Directory");
			u.SV(2);
		}
	}
	else
	{
		u.MASH_LOG("[ERROR]: Folder already exists");
		u.SV(2);
	}
}

void ShopsD_I::UpdateGlobalFile()
{

	std::ifstream input(ShopsD::File);
	input >> ShopsD::Data;
	input.close();

	MASH_json newData = {
		{"In Person", MASH_json::array()}
	};

	if (!isData) {
		ShopsD::Data.push_back(newData);

		isData = true;
	}

	for (MASH_uint i = 0; i < ShopsD::Data.size(); i++) {
		if (ShopsD::Data[i].contains("In Person"))
		{
			ShopsD::Counter = i;
		}
		else {
			ShopsD::Counter++;
		}
	}

	std::ofstream output(ShopsD::File);
	output << std::setw(4) << ShopsD::Data << MASH_endl;
	output.close();
}
