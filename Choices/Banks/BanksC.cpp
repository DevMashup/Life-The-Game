#include "BanksC.h"

void BanksC::Choice(MASH_vec<MASH_str>& command)
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
		BanksE_O bE_o;

		bE_o.Create();
	}
}
