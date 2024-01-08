#include "sfBankT_O.h"

void sfBankT_O::CreateTable()
{
	Universal u;

	MASH_vec<MASH_str> items;
	AddItems(items);


	TableNote();
	for (MASH_uint i = 1; i < items.size(); i++) {
		MASH_cout << "    " << items[i];

		if (i % 2 == 1) {
			u.SH(12);
		}

		if (i % 2 == 0) {
			u.SV();
		}
	}
	u.SV();
}

void sfBankT_O::TableNote()
{
	Universal u;

	u.MASH_LOG("[IMPORTANT]: You can type the (sub)commands capitialized or not, but DO NOT type the hyphen. Futhermore, you can type any special command anytime the program accepts user input");

	u.SV();
	u.SH(56);
	u.MASH_LOG(" SPECIAL");
	u.SH(56);
	u.MASH_LOG(" COMMANDS");
	u.SH(56);
	u.MASH_LOG("----------");
}

void sfBankT_O::AddItems(MASH_vec<MASH_str>& items)
{
	items.push_back("NULL             ");
	items.push_back("Regular Checkings");
	//items.push_back("Regular Savings  ");
	items.push_back("Wallet           ");
	items.push_back("                 ");
	items.push_back("                 ");
	items.push_back("Age              ");
}
