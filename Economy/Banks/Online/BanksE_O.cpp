#include "BanksE_O.h"

void BanksE_O::Create()
{
	Universal u;

	BanksT_O bT_o;
	BanksD_O bD_o;
	BanksC_O bC_o;
	ReuseO rO;

	MASH_str line;

	bD_o.CreateData();

	MASH_cout << "Welcome to online banking " << AppD::User << "!!! We have many banks available";

	u.SV(2);
	bT_o.CreateTable();
	u.SV();

	MASH_cout << "So, where would you like to go?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	bC_o.Choice(command);
}
