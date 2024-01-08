#include "ShopsC_O.h"

void ShopsC_O::Choice(MASH_vec<MASH_str>& command, MASH_str mode)
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
			miShopE_O miE_oS;

			miE_oS.Shop(mode);
		}
	}
}
