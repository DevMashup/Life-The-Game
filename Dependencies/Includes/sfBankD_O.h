#pragma once

#include "BanksD_O.h"

class sfBankD_O {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_str File;
	static MASH_json Data;
	static MASH_b isBankData;
	static MASH_b isDataInit;
	static MASH_uint Counter;
private:
	void CreateFolder();
	void CreateFile();
	void AddData();
};