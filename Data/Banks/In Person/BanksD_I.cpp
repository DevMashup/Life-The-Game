#include "BanksD_I.h"

MASH_str BanksD_I::Folder = " ";
MASH_str BanksD_I::File = " ";
MASH_b BanksD_I::isData = false;
MASH_uint BanksD_I::Counter = 0;

void BanksD_I::CreateData()
{
	CreateFolder();
	AddData();
}

void BanksD_I::CreateFolder()
{
	Universal u;

	Folder = BanksD::Folder + "/In Person";

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

void BanksD_I::AddData()
{
	std::ifstream input(BanksD::File);
	input >> BanksD::Data;
	input.close();

	if (!isData) {
		MASH_json newData = {
			{"In Person", MASH_json::array()}
		};

		BanksD::Data.push_back(newData);

		isData = true;
	}

	for (MASH_uint i = 0; i < BanksD::Data.size(); i++) {
		if (BanksD::Data[i].contains("In Person"))
		{
			BanksD::Counter = i;
			break;
		}
		break;
	}

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;
	output.close();
}
