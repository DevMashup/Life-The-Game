#include "slmoBanksE_I.h"

void slmoBanksE_I::Create()
{
	Universal u;

	slmoBanksD_I slmoD_Ib;
	slmoBanksT_I slmoT_Ib;
	slmoBanksC_I slmoC_Ib;

	ReuseO rO;

	MASH_str line;
	slmoD_Ib.CreateData();

	MASH_cout << "Welcome to kansas city banking " << AppD::User << "!!! We have plenty of banks here" << MASH_endl;

	u.SV(2);
	slmoT_Ib.CreateTable();
	u.SV();

	MASH_cout << "Where would you like to go?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	slmoC_Ib.Choice(command);
}
