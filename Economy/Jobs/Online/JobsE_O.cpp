#include "JobsE_O.h"

void JobsE_O::Create()
{
	Universal u;

	JobsT_O bT_o;
	JobsD_O bD_o;
	JobsC_O bC_o;
	ReuseO rO;

	MASH_str line;

	bD_o.CreateData();

	MASH_cout << "Welcome to online banking " << AppD::User << "!!! We have many jobs available";

	u.SV(2);
	bT_o.CreateTable();
	u.SV();

	MASH_cout << "So, where would you like to go?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	bC_o.Choice(command);
}
