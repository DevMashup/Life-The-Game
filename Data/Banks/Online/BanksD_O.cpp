#include "BanksD_O.h"

MASH_str BanksD_O::Folder = " ";
MASH_str BanksD_O::File = " ";
MASH_b BanksD_O::isData = false;
MASH_uint BanksD_O::Counter = 0;

void BanksD_O::CreateData()
{
	CreateFolder();
	AddData();
}

void BanksD_O::CreateFolder()
{
	Universal u;

	Folder = BanksD::Folder + "/Online";

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

void BanksD_O::AddData()
{
	BanksD::File = AppD::Folder + "/Banks/Global.json";
	std::ifstream input(BanksD::File);
	
	if (MASH_fs::exists(BanksD::File)) {
		std::string fileContents((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());

		if (!fileContents.empty()) {
			try {
				BanksD::Data = MASH_json::parse(fileContents);
			}
			catch (const std::exception& e) {
				std::cerr << "Error parsing JSON: " << e.what() << std::endl;
			}

			isData = true;
		}
	}
	//input.close();

	if (!isData) {
		MASH_json newData = {
			{"Online", MASH_json::array()},
		};

		BanksD::Data.push_back(newData);

		isData = true;
	}

	for (MASH_uint i = 0; i < BanksD::Data.size(); i++) {
		if (BanksD::Data[i].contains("Online"))
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
