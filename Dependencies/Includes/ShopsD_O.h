#pragma once

#include "ShopsD.h"

class ShopsD_O {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_b isData;
private:
	void CreateFolder();
	void AddGlobalData();
};