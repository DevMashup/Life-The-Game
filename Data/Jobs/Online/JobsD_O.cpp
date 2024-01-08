#include "JobsD_O.h"

MASH_str JobsD_O::Folder = " ";
MASH_str JobsD_O::File = " ";
MASH_b JobsD_O::isDataInit = false;
MASH_uint JobsD_O::Counter = 0;

void JobsD_O::CreateData()
{
	CreateFolder();
	UpdateJobsFile();
}

void JobsD_O::CreateFolder()
{
	Universal u;

	Folder = JobsD::Folder + "/Online";

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

void JobsD_O::UpdateJobsFile()
{
	std::ifstream input(JobsD::File);
	input >> JobsD::Data;
	input.close();

	MASH_json newData = {
		{"Online", MASH_json::array()}
	};

	JobsD::Data.push_back(newData);

}
