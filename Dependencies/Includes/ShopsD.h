#pragma once

#include "AppD.h"

class ShopsD {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_str File;
	static MASH_json Data;
	static MASH_b isData;
	static MASH_uint Counter;
private:
	void CreateFolder();
	void CreateFile();
};