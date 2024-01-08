#include "slmoBanksD_I.h"

MASH_str slmoBanksD_I::Folder = " ";
MASH_str slmoBanksD_I::File = " ";
MASH_b slmoBanksD_I::isData = false;
MASH_json slmoBanksD_I::Data;
MASH_uint slmoBanksD_I::Counter = 0;

void slmoBanksD_I::CreateData()
{
	CreateFolder();
	CreateFile();
}

void slmoBanksD_I::CreateFolder()
{
	Universal u;

	Folder = moBanksD_I::Folder + "/St. Louis";

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

void slmoBanksD_I::CreateFile()
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

void slmoBanksD_I::AddData()
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
			{"St. Louis", MASH_json::array()}
		};

		BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
			["Missouri"].push_back(newData);

		isData = true;
	}

	auto element = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]
		["Missouri"];

	for (MASH_uint i = 0; i < element.size(); i++) {
		if (element[i].contains("St. Louis"))
		{
			moBanksD_I::Counter = i;

		}
		break;
	}

	std::ofstream output(BanksD::File);
	output << std::setw(4) << BanksD::Data << MASH_endl;
	output.close();
}
