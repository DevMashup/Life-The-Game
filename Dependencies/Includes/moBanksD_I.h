#pragma once

#include "usBanksD_I.h"

class moBanksD_I {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_str File;
	static MASH_b isData;
	static MASH_uint Counter;

private:
	void CreateFolder();
	void AddData();
};