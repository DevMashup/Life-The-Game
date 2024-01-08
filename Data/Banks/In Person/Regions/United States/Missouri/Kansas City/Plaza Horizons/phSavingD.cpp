#include "phSavingsD.h"

MASH_str phSavingsD::RegSavingsPH::Folder = " ";
MASH_str phSavingsD::RegSavingsPH::File = " ";
MASH_json phSavingsD::RegSavingsPH::Data;
MASH_b phSavingsD::RegSavingsPH::isData = false;

MASH_f phSavingsD::RegSavingsPH::Amount = 0.00;
MASH_int64t phSavingsD::RegSavingsPH::accNum = 0;

void phSavingsD::RegSavingsPH::CreateData()
{
	CreateFolder();
	CreateFile();
}

void phSavingsD::RegSavingsPH::CreateFolder()
{
	Universal u;

	Folder = phBankD_I::Folder + "/Accounts";

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

void phSavingsD::RegSavingsPH::CreateFile()
{
	File = Folder + "/Saving.json";

	Data = {
		{"Regular", {
			{"Account Holder", AppD::User},
			{"Bank Name", "Plaza Horizon"},
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

void phSavingsD::RegSavingsPH::UpdateCityFile()
{
}

void phSavingsD::RegSavingsPH::UpdateBanksFile()
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
					["Missouri"][moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]["Plaza Horizon"];

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
					{"Bank Name", "Plaza Horizon"},
					{"Account #", accNum},
					{"Bank Amount", MASH_json::array()}
				}},
			}},
		};
	
		BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
			["Missouri"][moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]["Plaza Horizon"].push_back(newData);
		isData = true;
	}
	auto elementIndex = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
		["Missouri"][moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]["Plaza Horizon"];

	for (MASH_uint i = 0; i < elementIndex.size(); i++) {
		if (elementIndex[i].contains("Saving")) {
			phBankD_I::Counter = i;

		}
		break;
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
