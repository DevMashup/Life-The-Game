#include "BanksC_O.h"

void BanksC_O::Choice(MASH_vec<MASH_str>& command)
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
			miBankE_O miE_oB;

			miE_oB.Create();
		}
	} 
	else if (command[0] == "Sally's" || command[0] == "sally's") {
		if (command[1] == "Finances" || command[1] == "finances") {
			sfBankE_O sfE_oB;

			sfE_oB.Create();
		}
	}
}
