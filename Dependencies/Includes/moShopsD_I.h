#pragma once

#include "usShopsD_I.h"

class moShopsD_I {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_b isData;
	static MASH_uint Counter;
public:
	void CreateFolder();
	void AddGlobalData();
};