#include "sfSavingsD.h"

MASH_str sfSavingsD::RegSavingsSF::Folder = " ";
MASH_str sfSavingsD::RegSavingsSF::File = " ";
MASH_json sfSavingsD::RegSavingsSF::Data;
MASH_b sfSavingsD::RegSavingsSF::isGlobalData = false;

MASH_int64t sfSavingsD::RegSavingsSF::accNum = 0;;
MASH_f sfSavingsD::RegSavingsSF::Amount = 0.00;

void sfSavingsD::RegSavingsSF::CreateData()
{
	CreateFolder();
	CreateFile();
}

void sfSavingsD::RegSavingsSF::CreateFolder()
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

void sfSavingsD::RegSavingsSF::CreateFile()
{
	File = Folder + "/Saving.json";

	Data = {
		{"Regular", {
			{"Account Holder", AppD::User},
			{"Bank Name", "Sally's Finances"},
			{"Account #", accNum},
			{"Bank Amount", MASH_json::array()}
		}},
	};

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();

	UpdateBankFile();
	UpdateBanksFile();
}

void sfSavingsD::RegSavingsSF::UpdateBankFile()
{
	std::ifstream input(sfBankD_O::File);
	input >> sfBankD_O::Data;
	input.close();

	MASH_json newData = {
		{"Saving", {
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

void sfSavingsD::RegSavingsSF::UpdateBanksFile()
{
	std::ifstream input(BanksD::File);
	
	if (MASH_fs::exists(BanksD::File)) {
		std::string fileContents((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());

		if (!fileContents.empty()) {
			try {
				BanksD::Data = MASH_json::parse(fileContents);
				auto element = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"];

				if (element.contains("Saving")) {
					isGlobalData = true;
				}
			}
			catch (const std::exception& e) {
				std::cerr << "Error parsing JSON: " << e.what() << std::endl;
			}

			isGlobalData = true;
		}
	}
	input.close();

	if(!isGlobalData) {

		MASH_json newData = {
			{"Saving", {
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
