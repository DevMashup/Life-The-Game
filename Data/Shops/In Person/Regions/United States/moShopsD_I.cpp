#include "moShopsD_I.h"

MASH_str moShopsD_I::Folder = " ";
MASH_b moShopsD_I::isData = false;
MASH_uint moShopsD_I::Counter = 0;

void moShopsD_I::CreateData()
{
	CreateFolder();
	AddGlobalData();
}

void moShopsD_I::CreateFolder()
{
	Universal u;

	Folder = usShopsD_I::Folder + "/Missouri";

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

void moShopsD_I::AddGlobalData()
{
	std::ifstream input(ShopsD::File);
	input >> ShopsD::Data;
	input.close();

	MASH_json newData = {
		{"Missouri", MASH_json::array()}
	};

	if (!isData) {
		ShopsD::Data[ShopsD::Counter]["In Person"][ShopsD_I::Counter]["United States"].push_back(newData);

		isData = true;
	}
	auto element = ShopsD::Data[ShopsD::Counter]["In Person"][ShopsD_I::Counter]["United States"];

	for (MASH_uint i = 0; i < element.size(); i++) {
		if (element[i].contains("Missouri"))
		{
			usShopsD_I::Counter = i;
		}
		else {
			usShopsD_I::Counter++;
		}
	}

	std::ofstream output(ShopsD::File);
	output << std::setw(4) << ShopsD::Data << MASH_endl;
	output.close();
}
