#include "ShopsD_O.h"

MASH_str ShopsD_O::Folder = " ";
MASH_b ShopsD_O::isData = false;

void ShopsD_O::CreateData()
{
	CreateFolder();
	AddGlobalData();
}

void ShopsD_O::CreateFolder()
{
	Universal u;

	Folder = ShopsD::Folder + "/Online";

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

void ShopsD_O::AddGlobalData()
{
	std::ifstream input(ShopsD::File);
	input >> ShopsD::Data;
	input.close();

	MASH_json newData = {
		{"Online", MASH_json::array()}
	};

	if (!isData) {
		ShopsD::Data.push_back(newData);

		isData = true;
	}

	for (MASH_uint i = 0; i < ShopsD::Data.size(); i++) {
		if (ShopsD::Data[i].contains("Online"))
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
