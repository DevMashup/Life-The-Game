#include "AppT.h"

void AppT::CreateTable()
{
	Universal u;

	MASH_vec<MASH_str> items;
	AddItems(items);


	TableNote();
	for (MASH_uint i = 1; i < items.size(); i++) {
		MASH_cout << "    " << items[i];

		if (i % 4 == 3) {
			u.SH(12);
		}

		if (i % 4 == 0) {
			u.SV();
		}
	}
	u.SV();
}

void AppT::TableNote()
{
	Universal u;

	u.MASH_LOG("[IMPORTANT]: You can type the (sub)commands capitialized or not, but DO NOT type the hyphen. Futhermore, you can type any special command anytime the program accepts user input");

	u.SV();
	u.SH(50);
	u.MASH_LOG(" SPECIAL");
	u.SH(50);
	u.MASH_LOG(" COMMANDS");
	u.SH(50);
	u.MASH_LOG("----------");

	//u.SV();
}

void AppT::AddItems(MASH_vec<MASH_str>& items)
{
	items.push_back("NULL    ");
	items.push_back("Bank    "); 
	items.push_back("Shop    ");
	items.push_back("Job     ");
	items.push_back("Wallet  ");
	items.push_back(" -C     ");
	items.push_back(" -B     ");
	items.push_back(" -Care  ");
	items.push_back("Age     ");
	items.push_back(" -I     ");
	items.push_back(" -S     ");
	items.push_back(" -Retail");
	items.push_back("        ");
	items.push_back(" -T     ");
	items.push_back("        ");
	items.push_back("        ");
	items.push_back("        ");
}
