#include "miBankD_O.h"

MASH_str miBankD_O::Folder;
MASH_str miBankD_O::File = " ";
MASH_json miBankD_O::Data;
MASH_b miBankD_O::isGlobalData = false;
MASH_b miBankD_O::isBankData = false;
MASH_uint miBankD_O::Counter = 0;

void miBankD_O::CreateData()
{
	CreateFolder();
	CreateFile(); 
	AddData();
}

void miBankD_O::CreateFolder()
{
	Universal u;

	Folder = BanksD_O::Folder + "/Mashup Inc";

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

void miBankD_O::CreateFile()
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

void miBankD_O::AddData()
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

			isGlobalData = true;
		}
	}
	input.close();

	if (!isGlobalData) {
		MASH_json newData = {
			{"Mashup Inc", MASH_json::array()}
		};
		
		BanksD::Data[BanksD::Counter]["Online"].push_back(newData);
	
		isGlobalData = true;
	}

	auto elementIndex = BanksD::Data[BanksD::Counter]["Online"];

	
	for (MASH_uint i = 0; i < elementIndex.size(); i++) {
		if (elementIndex[i].contains("Mashup Inc")) {
			BanksD_O::Counter = i;
		}
		break;

	}

	MASH_cout << "The index of BanksD_O for Mashup Inc is " << BanksD_O::Counter;

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;
	output.close();
}
