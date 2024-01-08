#include "JobsE.h"

void JobsE::Find()
{
	Universal u;

	JobsD bD;
	JobsT bT;
	JobsC bC;
	ReuseO rO;

	MASH_str line;

	bD.CreateData();

	if (RandomO::YoB > 1959 && RandomO::BCorAD == "A.D") { //Done
		MASH_cout << "Hello " + AppD::User + "!!! We have two modes you can choose from" << MASH_endl;

		u.SV(2);
		bT.CreateTable();
		u.SV();

		MASH_cout << "What mode would you perfer?: ";
		getline(MASH_cin, line);
		MASH_vec<MASH_str> command = rO.Split(line, " ");
		u.SV();

		bC.Choice(command);
	}
	else if (RandomO::YoB < 1960 || RandomO::BCorAD == "B.C") {
		BanksE_I bE_i;

		bE_i.Create();
	}
}
