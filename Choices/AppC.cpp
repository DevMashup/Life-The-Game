#include "AppC.h"

void AppC::Choice(MASH_vec<MASH_str>& command)
{
	if (command.size() == 0) {
		Universal u;

		AppO aO;

		MASH_cout << "Please enter a command";
		u.SV();

		aO.ConApp();
	}
	else {
		if (command[0] == "Wallet" || command[0] == "wallet") {
			OtherE oE;

			oE.CheckWallet();
		}
		else if (command[0] == "Age" || command[0] == "age") {
			OtherE oE;

			oE.IncreaseAge();
		}
		else if (command[0] == "Bank" || command[0] == "bank") {
			BanksE bE;

			if (command.size() == 1) {
				bE.Create(); //Done
			}
			else if (command[1] == "I" || command[1] == "i") {
				bE.Info(); //Done
			}
			else if (command[1] == "C" || command[1] == "c") {
				bE.Create(); //Done
			}
			else if (command[1] == "T" || command[1] == "t") {
				bE.Transfer();
			}
			else {
				MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

				MASH_exit;
			}
		}
		else if (command[0] == "Job" || command[0] == "job") {
			Universal u;

			AppO aO;

			MASH_cout << "Sorry, this command isnt fully functional yet";
			u.SV();

			aO.ConApp();
			/*JobsE jE;

			if (command.size() == 1) {
				jE.Find();
			}
			else {
				MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

				MASH_exit;
			}*/
		}
		else if (command[0] == "Shop" || command[0] == "shop") {
			Universal u;

			AppO aO;

			MASH_cout << "Sorry, this command isnt fully functional yet";
			u.SV();

			aO.ConApp();

			//ShopsE sE;

			//if (command.size() == 1) {
			//	MASH_str buy = "B";

			//	sE.Create(buy); //Default is Buy
			//}
			//else if (command[1] == "B" || command[1] == "b") {
			//	sE.Create(command[1]);
			//}
			//else if (command[1] == "S" || command[1] == "s") {
			//	sE.Create(command[1]);
			//}
			//else {
			//	MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

			//	MASH_exit;
			//}
		}
	}
}
