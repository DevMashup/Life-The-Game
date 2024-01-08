#include "OtherE.h"

void OtherE::IncreaseAge()
{
	Universal u;

	AppO aO;
	AppD aD;

	MASH_str YorN;

	MASH_uint ageLimit = 250;

	if (AppD::Age < ageLimit) {
		AppD::Age++;

		if (AppD::Age == 1) {
			MASH_cout << "You are now " << AppD::Age << " year old" << MASH_endl;
		}
		else {
			MASH_cout << "You are now " << AppD::Age << " years old" << MASH_endl;
		}
		aD.UpdateData();

		u.SV();

		MASH_cout << "Do you wanna go back to the main menu?: (Please type 'Y' or 'N') ";
		MASH_cin >> YorN;
		u.SV(2);


		if (YorN.size() == 0) {
			MASH_cout << "Please type either 'Y' or 'N'";
			u.SV();

			aO.ConApp();
		}
		else {
			if (YorN == "Y" || YorN == "y") {
				aO.ConApp();
			}
			else if (YorN == "N" || YorN == "n") {
				MASH_cout << "Thank you for playing Life: the game. Feel free to email me at realdevmashup@gmail.com if you have any concerns or suggestions." << MASH_endl;

				MASH_exit;
			}
			else {
				MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

				MASH_exit;
			}

		}
	} 
	else {
		MASH_cout << "Oh no!!!, you died. Do you wanna restart[[WARNING]: THIS WILL DELETE YOUR WHOLE DATA FOLDER]?: ";
		MASH_cout << "(Please type 'Y' or 'N'";
		MASH_cin >> YorN;
		u.SV(2);

		if (YorN.size() == 0) {
			MASH_cout << "Please type either 'Y' or 'N'";
			u.SV();

			aO.ConApp();
		}
		else {
			if (YorN == "Y" || YorN == "y") {
				try {
					MASH_str word;

					MASH_fs::remove_all(AppD::Folder);
					MASH_cout << "Folder successfully deleted. Do you want to play again or exit the application?: (Pleease type 'Play' or 'Exit')";
					MASH_cin >> word;

					if (word.size() == 0) {
						MASH_cout << "Please type either 'Play' or 'Exit'";
						u.SV();

						aO.ConApp();
					}
					else {
						if (word == "Play" || word == "play") {
							aO.ConApp();
						}
						else if (word == "Exit" || word == "exit") {
							MASH_cout << "Thank you for playing Life: the game. Feel free to email me at realdevmashup@gmail.com if you have any concerns or suggestions." << MASH_endl;

							MASH_exit;
						}
						else {
							MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

							MASH_exit;
						}
					}
				}
				catch (std::exception& e) {
					MASH_str word;
					MASH_uint Counter = 0;

					MASH_cout << "Error deleting folder: " << e.what() << MASH_endl;
					MASH_cout << "Trying again..." << MASH_endl;

					while (!MASH_fs::remove_all(AppD::Folder) && Counter < 31) {
						MASH_fs::remove_all(AppD::Folder);

						Counter++;

						if (MASH_fs::remove_all(AppD::Folder)) {
							MASH_cout << "Folder deleted after " << Counter << "attempts" << MASH_endl;
						}

						if (Counter > 30) {
							MASH_cout << "[ERROR]: Please delete your folder manually" << MASH_endl;
						}
					}
				}
			}
			else if (YorN == "N" || YorN == "n") {
				MASH_str word;

				MASH_cout << "Do you wanna go back to the main menu or exit te application?: (Please type 'Exit' or 'Return')";
				MASH_cin >> word;
				u.SV(2);

				if (word.size() == 0) {
					MASH_cout << "Please type either 'Exit' or 'Return'";
					u.SV();

					aO.ConApp();
				}
				else {
					if (word == "Return" || word == "return") {
						aO.ConApp();
					}
					else if (word == "Exit" || word == "exit") {
						MASH_cout << "Thank you for playing Life: the game. Feel free to email me at realdevmashup@gmail.com if you have any concerns or suggestions." << MASH_endl;

						MASH_exit;
					}
					else {
						MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

						MASH_exit;
					}
				}
			}
			else {
				MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

				MASH_exit;
			}
		}

	}
	
}

void OtherE::CheckWallet()
{
	Universal u;

	AppO aO;

	char YorN;

	MASH_cout << "You have " << AppD::walletAmount << " " << AppD::Currency << " in your wallet" << MASH_endl;

	u.SV();

	MASH_cout << "Do you wanna go back to the main menu?: (Please type 'Y' or 'N') ";
	MASH_cin >> YorN;
	u.SV(2);

	if (YorN == 'Y' || YorN == 'y') {
		aO.ConApp();
	}
	else
	{
		MASH_exit;
	}
}

void OtherE::WalletWithdrawal(MASH_f num)
{
	AppD aD;
	AppD::walletAmount -= num;
	aD.UpdateData();
}

void OtherE::WalletDeposit(MASH_f num)
{
	AppD aD;
	AppD::walletAmount += num;
	aD.UpdateData();
}

