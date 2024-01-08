#pragma once

#include "moBanksD_I.h"

class slmoBanksD_I {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_str File;
	static MASH_b isData;
	static MASH_json Data;
	static MASH_uint Counter;

private:
	void CreateFolder();
	void CreateFile();
	void AddData();
};