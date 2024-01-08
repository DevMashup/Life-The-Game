#include "spbSavingsD.h"

MASH_str spbSavingsD::RegSavingsSPB::Folder = " ";
MASH_str spbSavingsD::RegSavingsSPB::File = " ";
MASH_json spbSavingsD::RegSavingsSPB::Data;
MASH_b spbSavingsD::RegSavingsSPB::isData = false;

MASH_f spbSavingsD::RegSavingsSPB::Amount = 0;
MASH_int64t spbSavingsD::RegSavingsSPB::accNum = 0;

void spbSavingsD::RegSavingsSPB::CreateData()
{
	CreateFolder();
	CreateFile();
}

void spbSavingsD::RegSavingsSPB::CreateFolder()
{
	Universal u;

	Folder = spbBankD_I::Folder + "/Accounts";

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

void spbSavingsD::RegSavingsSPB::CreateFile()
{
	File = Folder + "/Saving.json";

	Data = {
		{"Regular", {
			{"Account Holder", AppD::User},
			{"Bank Name", "Summit Prairie Bank"},
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

void spbSavingsD::RegSavingsSPB::UpdateCityFile()
{
}

void spbSavingsD::RegSavingsSPB::UpdateBanksFile()
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
					["Missouri"][moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]["Summit Prairie Bank"];

				if (element.contains("Saving")) {
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
		{"Saving", {
			{"Regular", {
					{"Account Holder", AppD::User},
					{"Bank Name", "Summit Prairie Bank"},
					{"Account #", accNum},
					{"Bank Amount", MASH_json::array()}
				}},
			}},
		};
		BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
			["Missouri"][moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]["Summit Prairie Bank"].push_back(newData);

		isData = true;
	}
	auto elementIndex = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
		["Missouri"][moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]["Summit Prairie Bank"];

	if (elementIndex.size() == 0) {
		spbBankD_I::Counter = 0;
	}
	else {
		for (MASH_uint i = 0; i < elementIndex.size(); i++) {
			if (elementIndex[i].contains("Checking")) {
				spbBankD_I::Counter = i;

			}
			break;
		}
	}
	
	BanksD::Counter = 0;
	BanksD_I::Counter = 0;
	usBanksD_I::Counter = 0;
	moBanksD_I::Counter = 0;
	kcmoBanksD_I::Counter = 0;
	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;;
	input.close();
}
