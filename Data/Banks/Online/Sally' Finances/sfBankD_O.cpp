#include "sfBankD_O.h"

MASH_str sfBankD_O::Folder = " ";
MASH_str sfBankD_O::File = " ";
MASH_json sfBankD_O::Data;
MASH_b sfBankD_O::isDataInit = false;
MASH_b sfBankD_O::isBankData = false;
MASH_uint sfBankD_O::Counter = 0;

void sfBankD_O::CreateData()
{
	CreateFolder();
	CreateFile();
	AddData();
}

void sfBankD_O::CreateFolder()
{
	Universal u;

	Folder = BanksD_O::Folder + "/Sally's Finances";

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

void sfBankD_O::CreateFile()
{
	File = Folder + "/Bank Data.json";

	if (MASH_fs::exists(File)) {
		isBankData = true;

		std::ifstream input(File);
		input >> Data;
	}
	if (!isBankData) {
		Data = {};

		isBankData = true;
	}
	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();
}

void sfBankD_O::AddData()
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

			isDataInit = true;
		}
	}
	input.close();

	if (!isDataInit) {

		MASH_json newData = {
			{"Sally's Finances", MASH_json::array()}
		};
		BanksD::Data[BanksD::Counter]["Online"].push_back(newData);

		isDataInit = true;
	}

	auto element = BanksD::Data[BanksD::Counter]["Online"];

	for (MASH_uint i = 0; i < element.size(); i++) {
		if (element[i].contains("Sally's Finances")) {
			BanksD_O::Counter = i;

			//break;
		}
		/*else if (element[i].contains("Mashup Inc")) {
			BanksD_O::Counter++;

			break;
		}*/
		break;
	}

	MASH_cout << "The index of BanksD_O for Sally's finances is " << BanksD_O::Counter;

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;
	output.close();
}
