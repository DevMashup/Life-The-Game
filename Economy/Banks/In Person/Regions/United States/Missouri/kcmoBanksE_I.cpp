#include "kcmoBanksE_I.h"

void kcmoBanksE_I::Create()
{
	Universal u;
	
	kcmoBanksD_I kcmoD_Ib;
	kcmoBanksT_I kcmoT_Ib;
	kcmoBanksC_I kcmoC_Ib;

	ReuseO rO;

	MASH_str line;
	kcmoD_Ib.CreateData();

	MASH_cout << "Welcome to kansas city banking " << AppD::User << "!!! We have plenty of banks here" << MASH_endl;

	u.SV(2);
	kcmoT_Ib.CreateTable();
	u.SV();

	MASH_cout << "Where would you like to go?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	kcmoC_Ib.Choice(command);
}
