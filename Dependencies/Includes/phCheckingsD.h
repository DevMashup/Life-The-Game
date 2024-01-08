#pragma once

#include "phBankD_I.h"

class phCheckingsD {
public:
	class RegCheckingsPH {
	public:
		void CreateData();

		static MASH_str Folder;
		static MASH_str File;
		static MASH_json Data;
		static MASH_b isData;

		static MASH_f Amount;
		static MASH_int64t accNum;

	private:
		void CreateFolder();
		void CreateFile();
		void UpdateCityFile();
		void UpdateBanksFile();
	};
};