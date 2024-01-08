#include "usShopsD_I.h"

MASH_str usShopsD_I::Folder = " ";
MASH_b usShopsD_I::isData = false;
MASH_uint usShopsD_I::Counter = 0;

void usShopsD_I::CreateData()
{
	CreateFolder();
	AddGlobalData();
}

void usShopsD_I::CreateFolder()
{
	Universal u;

	Folder = ShopsD_I::Folder + "/United States";

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

void usShopsD_I::AddGlobalData()
{
	std::ifstream input(ShopsD::File);
	input >> ShopsD::Data;
	input.close();

	MASH_json newData = {
		{"United States", MASH_json::array()}
	};

	if (!isData) {
		ShopsD::Data[ShopsD::Counter]["In Person"].push_back(newData);

		isData = true;
	}
	auto element = ShopsD::Data[ShopsD::Counter]["In Person"];

	for (MASH_uint i = 0; i < element.size(); i++) {
		if (element[i].contains("United States"))
		{
			ShopsD_I::Counter = i;
		}
		else {
			ShopsD_I::Counter++;
		}
	}

	std::ofstream output(ShopsD::File);
	output << std::setw(4) << ShopsD::Data << MASH_endl;
	output.close();
}
