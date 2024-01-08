#include "JobsD.h"

MASH_str JobsD::Folder = " ";
MASH_str JobsD::File = " ";
MASH_json JobsD::Data;
MASH_b JobsD::isDataInit = false;
MASH_uint JobsD::Counter = 0;
void JobsD::CreateData()
{
	CreateFolder();
	CreateFile();
}

void JobsD::CreateFolder()
{
	Universal u;

	Folder = AppD::Folder + "/Jobs";

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

void JobsD::CreateFile()
{
	File = Folder + "/Global.json";
	MASH_str myFile = File;
	MASH_json myData = Data;



	if (isDataInit) {
		Data = {};
	}
	std::ofstream output(File);
	output << std::setw(4) << Data << MASH_endl;
	output.close();
}
