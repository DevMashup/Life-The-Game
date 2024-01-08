#include "phBankC_I.h"

void phBankC_I::Choice(MASH_vec<MASH_str> command)
{
	if (command[0] == "Wallet" || command[0] == "wallet") {
		OtherE oE;

		oE.CheckWallet();
	}
	else if (command[0] == "Age" || command[0] == "age") {
		OtherE oE;

		oE.IncreaseAge();
	}
	else if (command[0] == "Regular" || command[0] == "regular") {
		if (command[1] == "Checkings" || command[1] == "checkings") {
			BankO* regChecking = new phCheckingsE::RegCheckingsPH();

			regChecking->Create();
		}
		else if (command[1] == "Savings" || command[1] == "savings") {
			BankO* regSaving = new phSavingsE::RegSavingsPH();

			regSaving->Create();
		}
	}
}
