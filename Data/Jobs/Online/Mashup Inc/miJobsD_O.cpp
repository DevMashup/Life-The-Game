#include "miJobsD_O.h"

MASH_str miJobsD_O::Folder = " ";
MASH_b miJobsD_O::isDataInit = false;
MASH_uint miJobsD_O::Counter = 0;

void miJobsD_O::CreateData()
{
	CreateFolder();
	UpdateJobsFile();
}

void miJobsD_O::CreateFolder()
{
	Universal u;

	Folder = JobsD::Folder + "/Mashup Inc";

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

void miJobsD_O::CreateFile()
{
}


void miJobsD_O::UpdateJobsFile()
{
	std::ifstream input(JobsD::File);
	input >> JobsD::Data;
	input.close();

	if (!isDataInit) {
		MASH_json newData = {
			{"Mashup Inc", MASH_json::array()}
		};

		JobsD::Data[JobsD::Counter]["Online"].push_back(newData);

		isDataInit = true;
	}

	auto elementIndex = JobsD::Data[JobsD::Counter]["Online"];


	for (MASH_uint i = 0; i < elementIndex.size(); i++) {
		if (elementIndex[i].contains("Mashup Inc")) {
			JobsD_O::Counter = i;

			break;
		}
		break;

	}

	MASH_cout << "The index of BanksD_O for Mashup Inc is " << JobsD_O::Counter;

	std::ofstream output(JobsD::File);
	output << std::setw(4) << JobsD::Data << MASH_endl;
	output.close();
}
