#pragma once

#include "JobsD.h"

class JobsD_O {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_str File;
	static MASH_b isDataInit;
	static MASH_uint Counter;
private:
	void CreateFolder();
	void UpdateJobsFile();
};