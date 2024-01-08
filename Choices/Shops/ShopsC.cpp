#include "ShopsC.h"


void ShopsC::Choice(MASH_vec<MASH_str>& command, MASH_str mode)
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
		ShopsE_O sE_o;

		sE_o.Create(mode); //Done
	}
	else if (command[0] == "In" || command[0] == "in") {
		if (command[1] == "Person" || command[1] == "person") {
			ShopsE_I sE_i;

			sE_i.Create(mode);
		}
	}
}
