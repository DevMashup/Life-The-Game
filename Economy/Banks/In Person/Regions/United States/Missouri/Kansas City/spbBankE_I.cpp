#include "spbBankE_I.h"

void spbBankE_I::Create()
{
	Universal u;

	spbBankD_I spbD_Ib;
	spbBankT_I spbT_It;
	spbBankC_I spbC_Ib;

	ReuseO rO;

	MASH_str line;

	spbD_Ib.CreateData();

	MASH_cout << "Welcome to Summit Prairie Bank " << AppD::User << "!!! We have many accounts to choose from." << MASH_endl;

	u.SV(2);
	spbT_It.CreateTable();
	u.SV();

	MASH_cout << "Which account do you want to open today?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	spbC_Ib.Choice(command);
}
