#include "kcmoBanksC_I.h"

void kcmoBanksC_I::Choice(MASH_vec<MASH_str>& command)
{
	if (command[0] == "Wallet" || command[0] == "wallet") {
		OtherE oE;

		oE.CheckWallet();
	}
	else if (command[0] == "Age" || command[0] == "age") {
		OtherE oE;

		oE.IncreaseAge();
	}
	else if (command[0] == "Summit" || command[0] == "summit") {
		if (command[1] == "Prairie" || command[1] == "prairie") {
			if (command[2] == "Bank" || command[2] == "bank") {
				spbBankE_I spbE_Ib;

				spbE_Ib.Create();
			}
		}
	}
	else if (command[0] == "Plaza" || command[0] == "plaza") {
		if (command[1] == "Horizon" || command[1] == "horizon") {
			phBankE_I phE_Ib;

			phE_Ib.Create();
		}
	}
}
