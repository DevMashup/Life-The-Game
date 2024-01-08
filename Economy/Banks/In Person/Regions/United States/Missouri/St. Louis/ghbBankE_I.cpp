#include "ghbBankE_I.h"

void ghbBankE_I::Create()
{
	Universal u;

	ghbBankD_I ghbD_Ib;
	ghbBankT_I ghbT_It;
	ghbBankC_I ghbC_Ib;

	ReuseO rO;

	MASH_str line;

	ghbD_Ib.CreateData();

	MASH_cout << "Welcome to Global Heights Bank " << AppD::User << "!!! We have many accounts to choose from." << MASH_endl;

	u.SV(2);
	ghbT_It.CreateTable();
	u.SV();

	MASH_cout << "Which account do you want to open today?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	ghbC_Ib.Choice(command);
}
