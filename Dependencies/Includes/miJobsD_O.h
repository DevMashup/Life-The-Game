#pragma once

#include "JobsD_O.h"

class miJobsD_O {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_str File;
	static MASH_json Data;
	static MASH_b isDataInit;
	static MASH_uint Counter;
private:
	void CreateFolder();
	void CreateFile();
	void UpdateJobsFile();
};