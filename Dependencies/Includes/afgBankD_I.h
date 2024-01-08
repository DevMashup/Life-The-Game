#pragma once

#include "slmoBanksD_I.h"

class afgBankD_I {
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
	void UpdateCityFile();
	void UpdateBanksFile();
};