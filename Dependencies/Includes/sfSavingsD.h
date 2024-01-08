#pragma once

#include "sfBankD_O.h"

class sfSavingsD {
public:
	class RegSavingsSF {
	public:
		void CreateData();

		static MASH_str Folder;
		static MASH_str File;
		static MASH_json Data;
		static MASH_b isGlobalData;

		static MASH_int64t accNum;
		static MASH_f Amount;
	private:
		void CreateFolder();
		void CreateFile();
		void UpdateBankFile();
		void UpdateBanksFile();
	};
};
