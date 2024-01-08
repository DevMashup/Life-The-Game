#include "slmoBanksC_I.h"

void slmoBanksC_I::Choice(MASH_vec<MASH_str>&command)
{
	if (command[0] == "Wallet" || command[0] == "wallet") {
		OtherE oE;

		oE.CheckWallet();
	}
	else if (command[0] == "Age" || command[0] == "age") {
		OtherE oE;

		oE.IncreaseAge();
	}
	else if (command[0] == "Gateway" || command[0] == "gateway") {
		if (command[1] == "Heights" || command[1] == "heights") {
			if (command[2] == "Bank" || command[2] == "bank") {
				ghbBankE_I ghbE_Ib;

				ghbE_Ib.Create();
			}
		}
	}
	else if (command[0] == "ArchCity" || command[0] == "archcity") {
		if (command[1] == "Financial" || command[1] == "financial") {
			if (command[2] == "Group" || command[2] == "group") {
				afgBankE_I afgE_Ib;

				afgE_Ib.Create();
			}
		}
	}
	
}
