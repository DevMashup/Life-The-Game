#include "afgCheckingsD.h"

MASH_str afgCheckingsD::RegCheckingsAFG::Folder = " ";
MASH_str afgCheckingsD::RegCheckingsAFG::File = " ";
MASH_json afgCheckingsD::RegCheckingsAFG::Data;
MASH_b afgCheckingsD::RegCheckingsAFG::isData = false;

MASH_f afgCheckingsD::RegCheckingsAFG::Amount = 0.00;
MASH_int64t afgCheckingsD::RegCheckingsAFG::accNum = 0;

void afgCheckingsD::RegCheckingsAFG::CreateData()
{
	CreateFolder();
	CreateFile();
}

void afgCheckingsD::RegCheckingsAFG::CreateFolder()
{
	Universal u;

	Folder = afgBankD_I::Folder + "/Accounts";

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

void afgCheckingsD::RegCheckingsAFG::CreateFile()
{
	File = Folder + "/Checking.json";

	Data = {
		{"Regular", {
			{"Account Holder", AppD::User},
			{"Bank Name", "ArchCity Financial Group"},
			{"Account #", accNum},
			{"Bank Amount", MASH_json::array()}
		}},
	};

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();

	UpdateCityFile();
	UpdateBanksFile();

}

void afgCheckingsD::RegCheckingsAFG::UpdateCityFile()
{
}

void afgCheckingsD::RegCheckingsAFG::UpdateBanksFile()
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

				auto element = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
					["Missouri"][moBanksD_I::Counter]["St. Louis"][slmoBanksD_I::Counter]["ArchCity Financial Group"];

				if (element.contains("Checking")) {
					isData = true;
				}
			}
			catch (const std::exception& e) {
				std::cerr << "Error parsing JSON: " << e.what() << std::endl;
			}
		}
	}
	if (!isData) {
		MASH_json newData = {
		{"Checking", {
				{"Regular", {
					{"Account Holder", AppD::User},
					{"Bank Name", "ArchCity Financial Group"},
					{"Account #", accNum},
					{"Bank Amount", MASH_json::array()}
				}},
			}},
		};

		BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
			["Missouri"][moBanksD_I::Counter]["St. Louis"][slmoBanksD_I::Counter]["ArchCity Financial Group"].push_back(newData);
		isData = true;
	}
	auto elementIndex = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
		["Missouri"][moBanksD_I::Counter]["St. Louis"][slmoBanksD_I::Counter]["ArchCity Financial Group"];

	for (MASH_uint i = 0; i < elementIndex.size(); i++) {
		if (elementIndex[i].contains("Checking")) {
			afgBankD_I::Counter = i;

		}
		break;
	}
	BanksD::Counter = 0;
	BanksD_I::Counter = 0;
	usBanksD_I::Counter = 0;
	moBanksD_I::Counter = 0;
	slmoBanksD_I::Counter = 0;
	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;;
	input.close();
}
