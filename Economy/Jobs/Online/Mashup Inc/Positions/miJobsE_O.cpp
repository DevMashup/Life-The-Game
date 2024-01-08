#include "miJobsE_O.h"

void miJobsE_O::Create()
{
	Universal u;

	miJobsT_O mibT_o;
	miJobsD_O mibD_o;
	miJobsC_O mibC_o;
	ReuseO rO;

	MASH_str line;

	mibD_o.CreateData();

	MASH_cout << "Welcome to Mashup Inc " << AppD::User << "!!! We have many positions available";

	u.SV(2);
	mibT_o.CreateTable();
	u.SV();

	MASH_cout << "So, where would you like to go?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	mibC_o.Choice(command);
}
