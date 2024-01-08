#include "sfBankE_O.h"

MASH_uint sfBankE_O::accCounter = 0;

void sfBankE_O::Create()
{
	Universal u;

	sfBankD_O sfbD_o;
	sfBankT_O sfbT_o;
	sfBankC_O sfbC_o;
	ReuseO rO;

	MASH_str line;

	sfbD_o.CreateData();
	MASH_cout << "Welcome to Sally's Finances. We have many accounts for you to choose from" << MASH_endl;

	u.SV(2);
	sfbT_o.CreateTable();
	u.SV();

	MASH_cout << "Which account do you want to open?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	sfbC_o.Choice(command);
}
