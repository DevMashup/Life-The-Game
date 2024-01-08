#include "BanksD.h"

MASH_str BanksD::Folder = " ";
MASH_str BanksD::File = " ";
MASH_json BanksD::Data;
MASH_b BanksD::isDataInit = false;
MASH_uint BanksD::Counter = 0;

void BanksD::CreateData()
{
	CreateFolder();
	CreateFile();
}

void BanksD::CreateFolder()
{
	Universal u;

	Folder = AppD::Folder + "/Banks";

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

void BanksD::CreateFile()
{
	File = Folder + "/Global.json";

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

			isDataInit = true;
		}
	}
	input.close();

	if (!isDataInit) {
		Data = {};

		isDataInit = true;
	}

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();
}
