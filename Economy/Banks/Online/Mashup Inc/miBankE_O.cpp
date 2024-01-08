#include "miBankE_O.h"

MASH_uint miBankE_O::accCounter = 0;

void miBankE_O::Create()
{
	Universal u;

	miBankD_O miD_oB;
	miBankT_O miT_oB;
	miBankC_O miC_oB;
	ReuseO rO;

	MASH_str line;

	miD_oB.CreateData();
	MASH_cout << "Welcome to Mashup Inc: Banking Division " << AppD::User << "!!! We have many accounts to chooose from";

	u.SV(2);
	miT_oB.CreateTable();
	u.SV();

	MASH_cout << "What kind of account do you wanna open?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	miC_oB.Choice(command);
}
