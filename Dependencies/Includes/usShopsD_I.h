#pragma once

#include "ShopsD_I.h"

class usShopsD_I {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_b isData;
	static MASH_uint Counter;
private:
	void CreateFolder();
	void AddGlobalData();
};