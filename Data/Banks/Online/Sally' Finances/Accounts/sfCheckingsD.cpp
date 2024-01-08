#include "sfCheckingsD.h"

MASH_str sfCheckingsD::RegCheckingsSF::Folder = " ";
MASH_str sfCheckingsD::RegCheckingsSF::File = " ";
MASH_json sfCheckingsD::RegCheckingsSF::Data;
MASH_b sfCheckingsD::RegCheckingsSF::isAccData = false;
MASH_b sfCheckingsD::RegCheckingsSF::isGlobalData = false;

MASH_int64t sfCheckingsD::RegCheckingsSF::accNum = 0;
MASH_f sfCheckingsD::RegCheckingsSF::Amount = 0.00;

void sfCheckingsD::RegCheckingsSF::CreateData()
{
	CreateFolder();
	CreateFile();
}

void sfCheckingsD::RegCheckingsSF::CreateFolder()
{
	Universal u;

	Folder = sfBankD_O::Folder + "/Accounts";

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

void sfCheckingsD::RegCheckingsSF::CreateFile()
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
				{"Bank Name", "Sally's Finances"},
				{"Account #", accNum},
				{"Bank Amount", MASH_json::array()}
			}},
		};

		isAccData = true;
	}

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();

	UpdateBankFile();
	UpdateBanksFile();
}

void sfCheckingsD::RegCheckingsSF::UpdateBankFile()
{
	std::ifstream input(sfBankD_O::File);
	input >> sfBankD_O::Data;
	input.close();

	MASH_json newData = {
		{"Checking", {
			{"Regular", {
				{"Account Holder", AppD::User},
				{"Bank Name", "Sally's Finances"},
				{"Account #", accNum},
				{"Bank Amount", MASH_json::array()}
			}},
		}},
	};

	sfBankD_O::Data.push_back(newData);

	std::ofstream output(sfBankD_O::File);
	output << std::setw(4) << sfBankD_O::Data << MASH_endl;;
	input.close();
}

void sfCheckingsD::RegCheckingsSF::UpdateBanksFile()
{
	std::ifstream input(BanksD::File);
	if (MASH_fs::exists(BanksD::File)) {
		std::string fileContents((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());

		if (!fileContents.empty()) {
			try {
				BanksD::Data = MASH_json::parse(fileContents);
				auto element = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"];

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
					{"Bank Name", "Sally's Finances"},
					{"Account #", accNum},
					{"Bank Amount", MASH_json::array()}
				}},
			}},
		};

		BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"].push_back(newData);

		isGlobalData = true;
	}

	BanksD::Counter = 0;
	BanksD_O::Counter = 0;
	sfBankD_O::Counter = 0;

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;;
	input.close();
}
