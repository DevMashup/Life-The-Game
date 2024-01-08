#include "kcmoShopsE_I.h"

void kcmoShopsE_I::Create(MASH_str mode)
{
	Universal u;

	kcmoShopsT_I kcmoT_Is;
	kcmoShopsD_I kcmoD_Is;
	kcmoShopsC_I kcmoC_Is;
	ReuseO rO;

	MASH_str line;

	kcmoD_Is.CreateData();

	MASH_cout << "Welcome to Kansas City Shopping " << AppD::User << "!!! We have many shops available";

	u.SV(2);
	kcmoT_Is.CreateTable();
	u.SV();

	MASH_cout << "So, where would you like to go?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	kcmoC_Is.Choice(command, mode);
}
