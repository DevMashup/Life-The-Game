#include "ShopsT.h"

void ShopsT::CreateTable()
{
	Universal u;

	MASH_vec<MASH_str> items;
	AddItems(items);


	TableNote();
	for (MASH_uint i = 1; i < items.size(); i++) {
		MASH_cout << "    " << items[i];

		if (i % 3 == 2) {
			u.SH(12);
		}

		if (i % 3 == 0) {
			u.SV();
		}
	}
	u.SV();
}

void ShopsT::TableNote()
{
	Universal u;

	u.MASH_LOG("[IMPORTANT]: You can type the (sub)commands capitialized or not, but DO NOT type the hyphen. Futhermore, you can type any special command anytime the program accepts user input");

	u.SV();
	u.SH(40);
	u.MASH_LOG(" SPECIAL");
	u.SH(40);
	u.MASH_LOG(" COMMANDS");
	u.SH(40);
	u.MASH_LOG("----------");
}

void ShopsT::AddItems(MASH_vec<MASH_str>& items)
{
	items.push_back("NULL     ");
	items.push_back("Online   ");
	items.push_back("In Person");
	items.push_back("Wallet   ");
	items.push_back("         ");
	items.push_back("         ");
	items.push_back("Age      ");
}
