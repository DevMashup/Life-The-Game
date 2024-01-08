#include "AppO.h"

void AppO::ConApp()
{
	Universal u;

	AppT aT;
	AppC aC;
	ReuseO rO;

	MASH_str line;
	MASH_cout << "Welcome to life " << AppD::User << "!! We have tons of options";

	u.SV(2);
	aT.CreateTable();
	u.SV();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	MASH_cout << "What do you wanna do?: ";
	getline(MASH_cin, line);
	MASH_vec<MASH_str> command = rO.Split(line, " ");
	u.SV();

	aC.Choice(command);
}
