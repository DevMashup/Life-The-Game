#include "affShopE.h"

MASH_str affShopE::hasPet = " ";

void affShopE::Shop(MASH_str mode)
{
	Universal u; 

	if (mode == "S" || mode == "s") {
		MASH_cout << "Welcome to Ashley's furry friends: Selling Division. Its always disheartening when a dog ";
		MASH_cout << "and owner are not a right fit. Now, hang tight while we check everything is in order" << MASH_endl;

		u.SV();
		if (hasPet == "Dog") {
			char YorN;

			MASH_cout << "Awwww....he's so adorable....are you sure you wanna give him up?: (Please reply with 'Y' or 'N')";
			MASH_cin >> YorN;
			u.SV(2);

			if (YorN == 'Y' || YorN == 'y') {
				MASH_cout << "Very well....which bank account do you want to use";
			}
			else {
		
			}
		}
	}
}

void affShopE::Logic(MASH_str mode)
{
}
