#pragma once

#include "ShopsD.h"

class ShopsD_I {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_b isData;
	static MASH_uint Counter;
private:
	void CreateFolder();
	void UpdateGlobalFile();
};