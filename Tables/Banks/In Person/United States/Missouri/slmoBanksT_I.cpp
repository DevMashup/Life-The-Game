#include "slmoBanksT_I.h"

void slmoBanksT_I::CreateTable()
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

void slmoBanksT_I::TableNote()
{
	Universal u;

	u.MASH_LOG("[IMPORTANT]: You can type the (sub)commands capitialized or not, but DO NOT type the hyphen. Futhermore, you can type any special command anytime the program accepts user input");

	u.SV();
	u.SH(60);
	u.MASH_LOG(" SPECIAL");
	u.SH(60);
	u.MASH_LOG(" COMMANDS");
	u.SH(60);
	u.MASH_LOG("----------");
}

void slmoBanksT_I::AddItems(MASH_vec<MASH_str>& items)
{
	items.push_back("NULL                    ");
	items.push_back("Gateway Heights Bank    ");
	items.push_back("ArchCity Financial Group");
	items.push_back("Wallet                  ");
	items.push_back("                        ");
	items.push_back("                        ");
	items.push_back("Age                     ");
}
