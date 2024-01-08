#include "ghbBankD_I.h"

MASH_str ghbBankD_I::Folder = " ";
MASH_str ghbBankD_I::File = " ";
MASH_b ghbBankD_I::isData = false;
MASH_json ghbBankD_I::Data;
MASH_uint ghbBankD_I::Counter = 0;

void ghbBankD_I::CreateData()
{
	CreateFolder();
	CreateFile();
}

void ghbBankD_I::CreateFolder()
{
	Universal u;

	Folder = slmoBanksD_I::Folder + "/Gateway Heights Bank";

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

void ghbBankD_I::CreateFile()
{
	File = Folder + "/Bank Data.json";

	if (!isData) {
		Data = {};
	}

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();

	UpdateCityFile();
	UpdateBanksFile();
}

void ghbBankD_I::UpdateCityFile()
{
}

void ghbBankD_I::UpdateBanksFile()
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
			{"Gateway Heights Bank", MASH_json::array()}
		};

		BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
			["Missouri"][moBanksD_I::Counter]["St. Louis"].push_back(newData);

		isData = true;
	}

	auto element = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
		["Missouri"][moBanksD_I::Counter]["St. Louis"];

	if (element.size() == 0) {
		slmoBanksD_I::Counter = 0;
	}
	else {
		for (MASH_uint i = 0; i < element.size(); i++) {
			if (element[i].contains("Gateway Heights Bank"))
			{
				slmoBanksD_I::Counter = i;

				break;
			}
			else {
				slmoBanksD_I::Counter++;

				break;
			}
			break;
		}
	}

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;
	output.close();
}
