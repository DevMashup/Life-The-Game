#include "miSavingsD.h"

MASH_str miSavingsD::RegSavingsMI::Folder = " ";
MASH_str miSavingsD::RegSavingsMI::File = " ";
MASH_json miSavingsD::RegSavingsMI::Data;
MASH_b miSavingsD::RegSavingsMI::isGlobalData = false;
MASH_b miSavingsD::RegSavingsMI::isBankData = false;
MASH_b miSavingsD::RegSavingsMI::isAccData = false;

MASH_int64t miSavingsD::RegSavingsMI::accNum = 0;
MASH_f miSavingsD::RegSavingsMI::Amount = 0.00;

void miSavingsD::RegSavingsMI::CreateData()
{
	CreateFolder();
	CreateFile();
	UpdateBankFile();
	UpdateBanksFile();
}

void miSavingsD::RegSavingsMI::CreateFolder()
{
	Universal u;

	Folder = miBankD_O::Folder + "/Accounts";

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

void miSavingsD::RegSavingsMI::CreateFile()
{
	File = Folder + "/Saving.json";
	std::ifstream input(File);

	if (MASH_fs::exists(File)) {
		std::string fileContents((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());

		if (!fileContents.empty()) {
			try {
				Data = MASH_json::parse(fileContents);
			}
			catch (const std::exception& e) {
				std::cerr << "Error parsing JSON: " << e.what() << std::endl;
			}

			isAccData = true;
		}
	}
	input.close();
	if (!isAccData) {
		Data = {
			{"Regular", {
				{"Account Holder", AppD::User},
				{"Bank Name", "Mashup Inc Banking Division"},
				{"Account #", accNum},
				{"Bank Amount", MASH_json::array()}
			}},
		};
	}

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();
}

void miSavingsD::RegSavingsMI::UpdateBankFile()
{
	std::ifstream input(miBankD_O::File);
	input >> miBankD_O::Data;
	input.close();
	if (!isBankData) {
		MASH_json newData = {
			{"Saving", {
				{"Regular", {
					{"Account Holder", AppD::User},
					{"Bank Name", "Mashup Inc Banking Division"},
					{"Account #", accNum},
					{"Bank Amount", MASH_json::array()}
				}},
			}},
		};

		miBankD_O::Data.push_back(newData);

		isBankData = true;
	}

	std::ofstream output(miBankD_O::File);
	output << std::setw(4) << miBankD_O::Data << MASH_endl;;
	input.close();
}

void miSavingsD::RegSavingsMI::UpdateBanksFile()
{
	std::ifstream input(BanksD::File);
	
	if (MASH_fs::exists(BanksD::File)) {
		std::string fileContents((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());

		if (!fileContents.empty()) {
			try {
				BanksD::Data = MASH_json::parse(fileContents);
				auto element = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Mashup Inc"];
			
				if (element.contains("Saving")) {
					isGlobalData = true;
				}
			}
			catch (const std::exception& e) {
				std::cerr << "Error parsing JSON: " << e.what() << std::endl;
			}
		}
	}
	input.close();
	if (!isGlobalData) {
		MASH_json newData = {
			{"Saving", {
				{"Regular", {
					{"Account Holder", AppD::User},
					{"Bank Name", "Mashup Inc Banking Division"},
					{"Account #", accNum},
					{"Bank Amount", MASH_json::array()}
				}},
			}},
		};

		BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Mashup Inc"].push_back(newData);

		isGlobalData = true;
	}

	BanksD::Counter = 0;
	BanksD_O::Counter = 0;
	miBankD_O::Counter = 0;
	
	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;;
	input.close();
}
