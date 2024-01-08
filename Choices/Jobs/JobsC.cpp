#include "JobsC.h"

void JobsC::Choice(MASH_vec<MASH_str>& command)
{
	if (command[0] == "Wallet" || command[0] == "wallet") {
		OtherE oE;

		oE.CheckWallet();
	}
	else if (command[0] == "Age" || command[0] == "age") {
		OtherE oE;

		oE.IncreaseAge();
	}
	else if (command[0] == "Online" || command[0] == "online") {
		JobsE_O jE_o;

		jE_o.Create();
	}
	/*else if (command[0] == "In" || command[0] == "in") {
		if (command[1] == "Person" || command[1] == "person") {
			BanksE_I bE_i;

			bE_i.Create();
		}*/
}
