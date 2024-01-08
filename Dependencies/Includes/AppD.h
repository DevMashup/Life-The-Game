#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

#include "RandomO.h"
#include "External/nlohmann/json.hpp"

#include "Universal/Universal.h"

class AppD {
public:
	void CreateData();

	static MASH_str Folder;
	static MASH_str File;
	static MASH_json Data;

	//Can be viewed in file
	static MASH_str User;
	static MASH_str Father;
	static MASH_str Mother;
	static MASH_str PoB;
	static MASH_str DoB;
	static MASH_str ToB;
	static MASH_uint Age;
	static MASH_str Currency;
	static MASH_str currentCity;
	static MASH_uint walletAmount;
private:
	void CreateFolder();
	void CreateFile();
public:
	void UpdateData();
};