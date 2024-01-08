#include "usBanksD_I.h"

MASH_str usBanksD_I::Folder = " ";
MASH_str usBanksD_I::File = " ";
MASH_b usBanksD_I::isData = false;
MASH_uint usBanksD_I::Counter = 0;

void usBanksD_I::CreateData()
{
	CreateFolder();
	AddData();
}

void usBanksD_I::CreateFolder()
{
	Universal u;

	Folder = BanksD_I::Folder + "/United States";

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

void usBanksD_I::AddData()
{
	std::ifstream input(BanksD::File);
	input >> BanksD::Data;
	input.close();

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

	if (!isData) {
		MASH_json newData = {
			{"United States", MASH_json::array()}
		};

		BanksD::Data[BanksD::Counter]["In Person"].push_back(newData);

		isData = true;
	}

	auto element = BanksD::Data[BanksD::Counter]["In Person"];

	for (MASH_uint i = 0; i < element.size(); i++) {
		if (element[i].contains("United States"))
		{
			BanksD_I::Counter = i;
		}

		break;
	}

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;
	output.close();
}
