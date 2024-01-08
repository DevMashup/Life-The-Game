#pragma once

#include "moShopsD_I.h"

class kcmoShopsD_I {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_b isData;
	static MASH_json Data;
	static MASH_str File;
	static MASH_uint Counter;
private:
	void CreateFolder();
	void CreateFile();
	void AddGlobalData();
};