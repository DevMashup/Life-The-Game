#include "ShopsE.h"

void ShopsE::Create(MASH_str mode)
{
	Universal u;

	ShopsD sD;
	ShopsT sT;
	ShopsC sC;
	ReuseO rO;

	MASH_str line;

	sD.CreateData();

	if (RandomO::YoB > 1959 && RandomO::BCorAD == "A.D") { //Done
		MASH_cout << "Hello " + AppD::User + "!!! We have two modes you can choose from" << MASH_endl;

		u.SV(2);
		sT.CreateTable();
		u.SV();

		MASH_cout << "What mode would you perfer?: ";
		getline(MASH_cin, line);
		MASH_vec<MASH_str> command = rO.Split(line, " ");
		u.SV();

		sC.Choice(command, mode);
	}
	/*else if (RandomO::YoB < 1960 || RandomO::BCorAD == "B.C") {
		BanksE_I bE_i;

		bE_i.Create();
	}*/
}
