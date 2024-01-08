#include "afgBankE_I.h"

void afgBankE_I::Create()
{
	Universal u;

	afgBankD_I afgD_Ib;
	afgBankT_I afgT_It;
	afgBankC_I afgC_Ib;

	ReuseO rO;

	MASH_str line;

	afgD_Ib.CreateData();

	MASH_cout << "Welcome to Global Heights Bank " << AppD::User << "!!! We have many accounts to choose from." << MASH_endl;

	u.SV(2);
	afgT_It.CreateTable();
	u.SV();

	MASH_cout << "Which account do you want to open today?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	afgC_Ib.Choice(command);
}
