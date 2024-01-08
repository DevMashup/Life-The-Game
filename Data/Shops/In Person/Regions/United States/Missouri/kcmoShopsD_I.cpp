#include "kcmoShopsD_I.h"

MASH_str kcmoShopsD_I::Folder = " ";
MASH_b kcmoShopsD_I::isData = false;
MASH_json kcmoShopsD_I::Data;
MASH_str kcmoShopsD_I::File = " ";
MASH_uint kcmoShopsD_I::Counter = 0;

void kcmoShopsD_I::CreateData()
{
	CreateFolder();
	CreateFile();
}

void kcmoShopsD_I::CreateFolder()
{
	Universal u;

	Folder = moShopsD_I::Folder + "/Kansas City";

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

void kcmoShopsD_I::CreateFile()
{
}

void kcmoShopsD_I::AddGlobalData()
{
	std::ifstream input(ShopsD::File);
	input >> ShopsD::Data;
	input.close();

	MASH_json newData = {
		{"Kansas City", MASH_json::array()}
	};

	if (!isData) {
		ShopsD::Data[ShopsD::Counter]["In Person"][ShopsD_I::Counter]["United States"][usShopsD_I::Counter]
			["Missouri"].push_back(newData);

		isData = true;
	}
	auto element = ShopsD::Data[ShopsD::Counter]["In Person"][ShopsD_I::Counter]["United States"]
		[usShopsD_I::Counter]["Missouri"];

	for (MASH_uint i = 0; i < element.size(); i++) {
		if (element[i].contains("Kansas City"))
		{
			moShopsD_I::Counter = i;
		}
		else {
			moShopsD_I::Counter++;
		}
	}

	std::ofstream output(ShopsD::File);
	output << std::setw(4) << ShopsD::Data << MASH_endl;
	output.close();
}
