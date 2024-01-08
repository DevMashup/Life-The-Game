#include "miJobsC_O.h"

void miJobsC_O::Choice(MASH_vec<MASH_str>& command)
{
	if (command[0] == "Wallet" || command[0] == "wallet") {
		OtherE oE;

		oE.CheckWallet();
	}
	else if (command[0] == "Age" || command[0] == "age") {
		OtherE oE;

		oE.IncreaseAge();
	}
	else if (command[0] == "Pilot" || command[0] == "pilot") {
		miPositionsE::Pilot mipEp;

		mipEp.Hired();
	}
}
