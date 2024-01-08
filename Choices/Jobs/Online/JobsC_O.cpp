#include "JobsC_O.h"

void JobsC_O::Choice(MASH_vec<MASH_str>& command)
{
	if (command[0] == "Wallet" || command[0] == "wallet") {
		OtherE oE;

		oE.CheckWallet();
	}
	else if (command[0] == "Age" || command[0] == "age") {
		OtherE oE;

		oE.IncreaseAge();
	}
	else if (command[0] == "Mashup" || command[0] == "mashup") {
		if (command[1] == "Inc" || command[1] == "inc") {
			miJobsE_O mijE_o;

			mijE_o.Create();
		}
	}
	/*else if (command[0] == "In" || command[0] == "in") {
		if (command[1] == "Person" || command[1] == "person") {
			BanksE_I bE_i;

			bE_i.Create();
		}*/
}
