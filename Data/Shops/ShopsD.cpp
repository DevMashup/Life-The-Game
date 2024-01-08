#include "ShopsD.h"

MASH_str ShopsD::Folder = " ";
MASH_str ShopsD::File = " ";
MASH_json ShopsD::Data;
MASH_b ShopsD::isData = false;
MASH_uint ShopsD::Counter = 0;

void ShopsD::CreateData()
{
	CreateFolder();
	CreateFile();
}

void ShopsD::CreateFolder()
{
	Universal u;

	Folder = AppD::Folder + "/Shops";

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

void ShopsD::CreateFile()
{
	File = Folder + "/Global.json";

	if (!isData) {
		Data = {};

		isData = true;
	}

	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();
}
