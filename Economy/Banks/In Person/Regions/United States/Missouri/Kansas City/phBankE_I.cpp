#include "phBankE_I.h"

void phBankE_I::Create()
{
	Universal u;

	phBankD_I phD_Ib;
	phBankT_I phT_It;
	phBankC_I phC_Ib;

	ReuseO rO;

	MASH_str line;

	phD_Ib.CreateData();

	MASH_cout << "Welcome to Summit Prairie Bank " << AppD::User << "!!! We have many accounts to choose from." << MASH_endl;

	u.SV(2);
	phT_It.CreateTable();
	u.SV();

	MASH_cout << "Which account do you want to open today?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	phC_Ib.Choice(command);
}
