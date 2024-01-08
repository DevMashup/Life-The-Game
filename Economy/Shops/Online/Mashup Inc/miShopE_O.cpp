#include "miShopE_O.h"

void miShopE_O::Shop(MASH_str mode)
{
	Universal u;

	if (mode == "S" || mode == "s") {
		MASH_cout << "Sorry, you cannot sell plane tickets yet";
	}
	else if (mode == "B" || mode == "b") {
		MASH_cout << "Welcome to Mashup Inc: Travel Division " << AppD::User << ", ";

		if (AppD::currentCity == "Kansas City, MO") {
			char YorN;

			MASH_cout << "So you want a ticket for 300 " << AppD::Currency << " to go to St. Louis, MO?: ";
			MASH_cout << "(Please type 'Y' or 'N')";
			MASH_cin >> YorN;
			u.SV(2);

			if (YorN == 'Y' || YorN == 'y') {
				if (miCheckingsE::RegCheckingsMI::hasAccount || miSavingsE::RegSavingsMI::hasAccount) {
					if (miCheckingsE::RegCheckingsMI::Amount > 150.00) {
						AppD aD;
						AppO aO;

						AppD::currentCity = "St. Louis, MO";

						MASH_cout << "Welcome to St, Louis, MO. Feel free to stay as longas you'd like" << MASH_endl;
						aD.UpdateData();
						u.SV();

						miCheckingsE::RegCheckingsMI::Amount -= 150.00;
						aO.ConApp();
					}
					else if (miSavingsE::RegSavingsMI::Amount > 150.00) {
						AppD aD;
						AppO aO;

						AppD::currentCity = "St. Louis, MO";

						MASH_cout << "Welcome to St, Louis, MO. Feel free to stay as longas you'd like" << MASH_endl;
						aD.UpdateData();
						u.SV();

						miCheckingsE::RegCheckingsMI::Amount -= 150.00;
						aO.ConApp();
					}
					else {
						AppO aO;

						MASH_cout << "You do not have enough money in either your Mashup Inc Accounts" << MASH_endl;
					
						aO.ConApp();
					}
				}
				else if (AppD::walletAmount > 300.00) {
					AppD aD;
					AppO aO;

					AppD::currentCity = "St. Louis, MO";

					MASH_cout << "Welcome to St, Louis, MO. Feel free to stay as longas you'd like" << MASH_endl;
					aD.UpdateData();
					u.SV();

					AppD::walletAmount -= 300.00;
					aO.ConApp();
				}
				else {
					AppO aO;

					MASH_cout << "You do have enough in your wallet to buy a ticket" << MASH_endl;

					aO.ConApp();

				}
			}
			else {
				AppO aO;

				aO.ConApp();
			}
		}
		if (AppD::currentCity == "St. Louis, MO") {
			char YorN;

			MASH_cout << "So you want a ticket for 300 " << AppD::Currency << " to go to Kansas City, MO?: ";
			MASH_cout << "(Please type 'Y' or 'N')";
			MASH_cin >> YorN;
			u.SV(2);

			if (YorN == 'Y' || YorN == 'y') {
				if (miCheckingsE::RegCheckingsMI::hasAccount || miSavingsE::RegSavingsMI::hasAccount) {
					if (miCheckingsE::RegCheckingsMI::Amount > 150.00) {
						AppD aD;
						AppO aO;

						AppD::currentCity = "Kansas City, MO";

						MASH_cout << "Welcome to Kansas City, MO. Feel free to stay as longas you'd like" << MASH_endl;
						aD.UpdateData();
						u.SV();

						miCheckingsE::RegCheckingsMI::Amount -= 150.00;
						aO.ConApp();
					}
					else if (miSavingsE::RegSavingsMI::Amount > 150.00) {
						AppD aD;
						AppO aO;

						AppD::currentCity = "Kansas City, MO";

						MASH_cout << "Welcome to Kansas City, MO. Feel free to stay as longas you'd like" << MASH_endl;
						aD.UpdateData();
						u.SV();

						miCheckingsE::RegCheckingsMI::Amount -= 150.00;
						aO.ConApp();
					}
					else {
						AppO aO;

						MASH_cout << "You do not have enough money in either your Mashup Inc Accounts" << MASH_endl;

						aO.ConApp();
					}
				}
				else if (AppD::walletAmount > 300.00) {
					AppD aD;
					AppO aO;

					AppD::currentCity = "Kansas City, MO";

					MASH_cout << "Welcome to Kansas city, MO. Feel free to stay as longas you'd like" << MASH_endl;
					aD.UpdateData();
					u.SV();

					AppD::walletAmount -= 300.00;
					aO.ConApp();
				}
				else {
					AppO aO;

					MASH_cout << "You do have enough in your wallet to buy a ticket" << MASH_endl;

					aO.ConApp();

				}
			}
			else {
				AppO aO;

				aO.ConApp();
			}
		}
	}
}
