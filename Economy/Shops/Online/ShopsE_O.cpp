#include "ShopsE_O.h"

void ShopsE_O::Create(MASH_str mode)
{
	Universal u;

	ShopsT_O sT_o;
	ShopsD_O sD_o;
	ShopsC_O sC_o;
	ReuseO rO;

	MASH_str line;

	sD_o.CreateData();

	MASH_cout << "Welcome to online shopping " << AppD::User << "!!! We have many shops available";

	u.SV(2);
	sT_o.CreateTable();
	u.SV();

	MASH_cout << "So, where would you like to go?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	sC_o.Choice(command, mode);
}
