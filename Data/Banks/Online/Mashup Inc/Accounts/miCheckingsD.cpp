#include "miCheckingsD.h"

MASH_str miCheckingsD::RegCheckingsMI::Folder = " ";
MASH_str miCheckingsD::RegCheckingsMI::File = " ";
MASH_json miCheckingsD::RegCheckingsMI::Data;
MASH_b miCheckingsD::RegCheckingsMI::isGlobalData = false;
MASH_b miCheckingsD::RegCheckingsMI::isBankData = false;
MASH_b miCheckingsD::RegCheckingsMI::isAccData = false;

MASH_int64t miCheckingsD::RegCheckingsMI::accNum = 0;
MASH_f miCheckingsD::RegCheckingsMI::Amount = 0.00;

void miCheckingsD::RegCheckingsMI::CreateData()
{
	CreateFolder();
	CreateFile();
	UpdateBankFile();
	UpdateBanksFile();
}

void miCheckingsD::RegCheckingsMI::CreateFolder()
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

void miCheckingsD::RegCheckingsMI::CreateFile()
{
	File = Folder + "/Checking.json";
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

		isAccData = true;
	}

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();
}

void miCheckingsD::RegCheckingsMI::UpdateBankFile()
{
	std::ifstream input(miBankD_O::File);
	input >> miBankD_O::Data;
	input.close();

	if (!isBankData) {
		MASH_json newData = {
			{"Checking", {
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

void miCheckingsD::RegCheckingsMI::UpdateBanksFile()
{
	std::ifstream input(BanksD::File);
	if (MASH_fs::exists(BanksD::File)) {
		std::string fileContents((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());

		if (!fileContents.empty()) {
			try {
				BanksD::Data = MASH_json::parse(fileContents);
				auto element = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Mashup Inc"];

				if (element.contains("Checking")) {
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
			{"Checking", {
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
