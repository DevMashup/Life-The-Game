#pragma once

#include "AppD.h"

class JobsD {
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
};

