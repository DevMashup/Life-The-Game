#include "kcmoBanksD_I.h"

MASH_str kcmoBanksD_I::Folder = " ";
MASH_str kcmoBanksD_I::File = " ";
MASH_b kcmoBanksD_I::isData = false;
MASH_json kcmoBanksD_I::Data;
MASH_uint kcmoBanksD_I::Counter = 0;

void kcmoBanksD_I::CreateData()
{
	CreateFolder();
	CreateFile();
}

void kcmoBanksD_I::CreateFolder()
{
	Universal u;

	Folder = moBanksD_I::Folder + "/Kansas City";

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

void kcmoBanksD_I::CreateFile()
{
	File = Folder + "/City Banks.json";

	if (!isData) {
		Data = {};
	}

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();

	AddData();
}

void kcmoBanksD_I::AddData()
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
			{"Kansas City", MASH_json::array()}
		};

		BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
			["Missouri"].push_back(newData);

		isData = true;
	}

	auto element = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
		["Missouri"];

	for (MASH_uint i = 0; i < element.size(); i++) {
		if (element[i].contains("Kansas City"))
		{
			moBanksD_I::Counter = i;
		}
		break;
	}

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;
	output.close();
}
