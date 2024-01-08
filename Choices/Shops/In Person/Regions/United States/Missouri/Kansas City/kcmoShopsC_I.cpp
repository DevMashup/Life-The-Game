#include "kcmoShopsC_I.h"

void kcmoShopsC_I::Choice(MASH_vec<MASH_str>& command, MASH_str mode)
{
	if (command[0] == "Wallet" || command[0] == "wallet") {
		OtherE oE;

		oE.CheckWallet();
	}
	else if (command[0] == "Age" || command[0] == "age") {
		OtherE oE;

		oE.IncreaseAge();
	}
	else if (command[0] == "PH" || command[0] == "ph") {
		if (command[1] == "Airport" || command[1] == "airport") {
			phairportShopE travel;

			travel.Shop(mode);
		}
	}
	else if (command[0] == "Ashley's" || command[0] == "ashley's") {
		if (command[1] == "Furry" || command[1] == "furry") {
			if (command[2] == "Friends" || command[2] == "friends") {
				affShopE pets;

				pets.Shop(mode);
			}
		}
	}
}
