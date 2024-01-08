#include "sfSavingsE.h"

MASH_b sfSavingsE::RegSavingsSF::hasAccount = false;
MASH_f sfSavingsE::RegSavingsSF::Amount = 0.00;
MASH_int64t sfSavingsE::RegSavingsSF::accNum = 0;
MASH_b sfSavingsE::RegSavingsSF::hasCard = false;

void sfSavingsE::RegSavingsSF::Create()
{
	Universal u;

	AppO aO;

	char YorN;

	std::ifstream input(BanksD::File);
	if (MASH_fs::exists(BanksD::File)) {
		std::string fileContents((std::istreambuf_iterator<char>(input)),
			std::istreambuf_iterator<char>());

		if (!fileContents.empty()) {
			try {
				BanksD::Data = MASH_json::parse(fileContents);
				auto element = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"];
				for (MASH_uint i = 0; i < element.size(); i++) {
					if (element[i].contains("Saving")) {
						hasAccount = true;
					}
				}
			}
			catch (const std::exception& e) {
				std::cerr << "Error parsing JSON: " << e.what() << std::endl;
			}
		}
	}
	input.close();
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<MASH_int64t> accNumDistrib(0, 999999999);
	MASH_int64t accNumrnd = accNumDistrib(gen);
	std::uniform_int_distribution<MASH_int64t> getCardDistrib(1, 5);
	MASH_int64t getCard = getCardDistrib(gen);

	if (!hasAccount) {
		if (AppD::Age < 9) {
			MASH_cout << "Sorry. You have to be atleast 9 to open a bank account. Would you like to age yourself: (Please type 'Y' or 'N')";
			MASH_cin >> YorN;
			u.SV(2);

			if (YorN == 'Y' || YorN == 'y') {
				OtherE oE;

				oE.IncreaseAge();
			}
			else if (YorN == 'N' || YorN == 'n') {
				char YorN2;

				MASH_cout << "Would you like to go to the main menu: (Please type 'Y' or 'N')";
				MASH_cin >> YorN2;
				u.SV(2);

				if (YorN2 == 'Y' || YorN2 == 'y') {
					aO.ConApp();
				}
				else {
					MASH_exit;
				}
			}
			else {
				MASH_exit;
			}
		}
		else if (AppD::Age > 8 && AppD::Age < 16) {

			MASH_str Parent;
			std::uniform_int_distribution<MASH_int64t> fatherHelpDistrib(1, 2);
			MASH_int64t fatherHelp = fatherHelpDistrib(gen);
			std::uniform_int_distribution<MASH_int64t> motherHelpDistrib(1, 2);
			MASH_int64t motherHelp = motherHelpDistrib(gen);

			MASH_cout << "Thank you for choosing Sally's Finances. Unfourtanly, since your only " << AppD::Age;
			MASH_cout << " years old, you'll have to ask one of your parents to help you open the account. Which parent do";
			MASH_cout << " you wanna ask first: (Please type 'Father' or 'Mother'";
			MASH_cin >> Parent;
			u.SV(2);

			sfSavingsD::RegSavingsSF savingsD;
			sfSavingsTF::RegSavingsSF savingsTF;

			accNum = accNumrnd;

			sfSavingsD::RegSavingsSF::Amount = Amount;
			sfSavingsD::RegSavingsSF::accNum = accNum;

			sfSavingsTF::RegSavingsSF::accNum = accNum;

			fatherHelp = 1;
			getCard = 4;
			if (Parent == "Father" || Parent == "father") {
				if (fatherHelp == 1) {

					savingsD.CreateData();

					MASH_cout << "Congrats!! You're father decided to help you open an account. ";
					hasAccount = true;

					if (getCard != 5) {
						MASH_cout << "He also got you you're own credit card" << MASH_endl;
						u.SV();

						MASH_cout << "As a thankyou for opening an account at Sally's Finances, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						hasCard = true;
						sfSavingsTF::RegSavingsSF::Amount = Amount;

						u.SV();
						savingsTF.Log();

						MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
						MASH_cin >> YorN;
						u.SV(2);

						if (YorN == 'Y' || YorN == 'y') {
							BanksD::Counter = 0;
							BanksD_O::Counter = 0;
							sfBankD_O::Counter = 0;

							aO.ConApp();
						}
						else {
							MASH_exit;
						}
					}
					else {

						MASH_cout << "Unfortsnly though, he could not afford you to get a credit card. Please come back";
						MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Sally's Finances, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						u.SV();

						sfSavingsTF::RegSavingsSF::Amount = Amount;
						savingsTF.Log();

						u.SV();

						MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
						MASH_cin >> YorN;
						u.SV(2);

						if (YorN == 'Y' || YorN == 'y') {
							aO.ConApp();
						}
						else {
							MASH_exit;
						}
					}
				}
				else {
					MASH_cout << "Looks like your father didnt want to help. Do you want to ask your mother: (Please type 'Y' or 'N')";
					MASH_cin >> YorN;

					if (YorN == 'Y' || YorN == 'y') {
						if (motherHelp == 1) {
							savingsD.CreateData();

							MASH_cout << "Congrats!! You're mother decided to help you open an account. ";
							hasAccount = true;

							if (getCard != 5) {
								MASH_cout << "she also got you you're own credit card" << MASH_endl;
								u.SV();

								MASH_cout << "As a thankyou for opening an account at Sally's Finances, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								hasCard = true;
								sfSavingsTF::RegSavingsSF::Amount = Amount;

								u.SV();
								savingsTF.Log();

								MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
								MASH_cin >> YorN;
								u.SV(2);

								if (YorN == 'Y' || YorN == 'y') {
									aO.ConApp();
								}
								else {
									MASH_exit;
								}
							}
							else {

								MASH_cout << "Unfortsnly though, she could not afford you to get a credit card. Please come back";
								MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Sally's Finances, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								u.SV();
								sfSavingsTF::RegSavingsSF::Amount = Amount;
								savingsTF.Log();

								u.SV();

								MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
								MASH_cin >> YorN;
								u.SV(2);

								if (YorN == 'Y' || YorN == 'y') {
									aO.ConApp();
								}
								else {
									MASH_exit;
								}
							}
						}
						else {
							MASH_cout << "Neither of your parents wanted to help. Please come back";
							MASH_cout << " when you're 16 or older when you can open your own account" << MASH_endl;

							u.SV(2);
							aO.ConApp();
						}
					}
					else {
						MASH_cout << "You didnt want your mother to help you. Please come back";
						MASH_cout << " when you're 16 or older when you can open your own account" << MASH_endl;

						u.SV(2);
						aO.ConApp();
					}
				}
			}
			else if (Parent == "Mother" || Parent == "mother") {
				if (motherHelp == 1) {

					savingsD.CreateData();

					MASH_cout << "Congrats!! You're mother decided to help you open an account. ";
					hasAccount = true;

					if (getCard != 5) {
						MASH_cout << "She also got you you're own credit card" << MASH_endl;
						u.SV();

						MASH_cout << "As a thankyou for opening an account at Sally's Finances, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						hasCard = true;
						sfSavingsTF::RegSavingsSF::Amount = Amount;

						u.SV();
						savingsTF.Log();

						MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
						MASH_cin >> YorN;
						u.SV(2);

						if (YorN == 'Y' || YorN == 'y') {
							aO.ConApp();
						}
						else {
							MASH_exit;
						}
					}
					else {

						MASH_cout << "Unfortsnly though, she could not afford you to get a credit card. Please come back";
						MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Sally's Finances, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						u.SV();

						sfSavingsTF::RegSavingsSF::Amount = Amount;
						savingsTF.Log();

						u.SV();

						MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
						MASH_cin >> YorN;
						u.SV(2);

						if (YorN == 'Y' || YorN == 'y') {
							aO.ConApp();
						}
						else {
							MASH_exit;
						}
					}
				}
				else {
					MASH_cout << "Looks like your mother didnt want to help. Do you want to ask your father: (Please type 'Y' or 'N')";
					MASH_cin >> YorN;

					if (YorN == 'Y' || YorN == 'y') {
						if (fatherHelp == 1) {
							savingsD.CreateData();

							MASH_cout << "Congrats!! You're father decided to help you open an account. ";
							hasAccount = true;

							if (getCard != 5) {
								MASH_cout << "he also got you you're own credit card" << MASH_endl;
								u.SV();

								MASH_cout << "As a thankyou for opening an account at Sally's Finances, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								hasCard = true;
								sfSavingsTF::RegSavingsSF::Amount = Amount;

								u.SV();
								savingsTF.Log();

								MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
								MASH_cin >> YorN;
								u.SV(2);

								if (YorN == 'Y' || YorN == 'y') {
									aO.ConApp();
								}
								else {
									MASH_exit;
								}
							}
							else {

								MASH_cout << "Unfortsnly though, he could not afford you to get a credit card. Please come back";
								MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Mashup Inc : Banking Division, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								u.SV();
								sfSavingsTF::RegSavingsSF::Amount = Amount;
								savingsTF.Log();

								u.SV();

								MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
								MASH_cin >> YorN;
								u.SV(2);

								if (YorN == 'Y' || YorN == 'y') {
									aO.ConApp();
								}
								else {
									MASH_exit;
								}
							}
						}
						else {
							MASH_cout << "Neither of your parents wanted to help. Please come back";
							MASH_cout << " when you're 16 or older when you can open your own account" << MASH_endl;

							u.SV(2);
							aO.ConApp();
						}
					}
					else {
						MASH_cout << "You didnt want your father to help you. Please come back";
						MASH_cout << " when you're 16 or older when you can open your own account" << MASH_endl;

						u.SV(2);
						aO.ConApp();
					}
				}
			}
			else {
				MASH_cout << "The ability to ask relatives will come soom" << MASH_endl;
			}
		}
		else {
			char YorN;

			sfSavingsD::RegSavingsSF savingsD;
			sfSavingsTF::RegSavingsSF savingsTF;

			accNum = accNumrnd;

			sfSavingsD::RegSavingsSF::Amount = Amount;
			sfSavingsD::RegSavingsSF::accNum = accNum;

			sfSavingsTF::RegSavingsSF::accNum = accNum;

			savingsD.CreateData();
			MASH_cout << "Thank you for opening an account at Sally's Finances. As a reward, you'll get an intial deposit of 250 " << AppD::Currency << "." << MASH_endl;
			Deposit(250.00);
			u.SV(2);

			sfSavingsTF::RegSavingsSF::Amount = Amount;
			hasAccount = true;
			savingsTF.Log();

			MASH_cout << "Would you like to buy a credit card for 50 " << AppD::Currency << "?: (Please type 'Y' or 'N')";
			MASH_cin >> YorN;
			u.SV(2);

			if (YorN == 'Y' || YorN == 'y') {
				Withdrawal(50.00);

				MASH_cout << "Thank you for purchasing a credit card." << MASH_endl;
				hasCard = true;
			}
			else {
				char yorn;

				MASH_cout << "Do you wanna go back to the main menu?: (Please reply with 'Y' or 'N')";
				MASH_cin >> yorn;
				u.SV(2);

				if (YorN == 'Y' || YorN == 'y') {
					aO.ConApp();
				}
				else {
					MASH_exit;
				}

			}
		}
	}
	else {
		BanksE bE;

		MASH_cout << "You already have an account. Would you like to view all your banks";

		if (hasCard) {
			MASH_str line;

			MASH_cout << " or transfer money?: (Type 'Info' or 'Transfer')";
			MASH_cin >> line;
			u.SV(2);

			if (line == "Info" || line == "info") {
				bE.Info();
			}
			else if (line == "Transfer" || line == "transfer") {
				bE.Transfer();
			}
			else {
				MASH_exit;
			}
		}
		else {
			MASH_str line;

			MASH_cout << " , transfer money or buy a credit card?: (Type 'Info','Transfer', or 'Card') ";
			MASH_cin >> line;

			if (line == "Info" || line == "info") {
				bE.Info();
			}
			else if (line == "Transfer" || line == "transfer") {
				bE.Transfer();
			}
			else if (line == "Card" || line == "card") {
				char YorN;

				MASH_cout << "Are you sure? A credit card costs 50 " << AppD::Currency << "?: (Please type 'Y' or 'N'";
				MASH_cin >> YorN;
				u.SV();

				if (YorN == 'Y' || YorN == 'y') {
					MASH_f priceOfCard = 50.00;

					if (Amount > priceOfCard) {
						MASH_cout << "Congrats!!! Here's your credit card";
						hasCard = true;
					}
					else {
						MASH_cout << "Oh no!!! It appears you do not have enough money to buy a credit card";

						aO.ConApp();
					}
				}
				else if (YorN == 'N' || YorN == 'n') {
					char YorN;

					MASH_cout << "Did you want to open a checkings account instead?: (Please type 'Y' or 'N'";
					MASH_cin >> YorN;
					u.SV();

					if (YorN == 'Y' || YorN == 'y') {
						TemporaryO tO;

						tO.sfCheckAcc();
					}
					else if (YorN == 'N' || YorN == 'n') {
						MASH_exit;
					}
				}
				else {
					MASH_exit;
				}

			}
			else {
				MASH_exit;
			}
		}
	}
}

void sfSavingsE::RegSavingsSF::Withdrawal(MASH_f num)
{
	Amount -= num;

	//Own
	sfSavingsD::RegSavingsSF::File = AppD::Folder + "/Banks/Online/Sally's Finances/Accounts/Saving.json";

	if (MASH_fs::exists(sfSavingsD::RegSavingsSF::File)) {
		std::ifstream owninput(sfSavingsD::RegSavingsSF::File);
		owninput >> sfSavingsD::RegSavingsSF::Data;
		owninput.close();

		sfSavingsD::RegSavingsSF::Data["Regular"]["Bank Amount"] = Amount;

		std::ofstream ownoutput(sfSavingsD::RegSavingsSF::File);
		ownoutput << std::setw(4) << sfSavingsD::RegSavingsSF::Data << MASH_endl;
		ownoutput.close();

	}
	else {
		MASH_cout << "This file does'nt exist yet checking";
	}

	//Bank
	sfBankD_O::File = AppD::Folder + "/Banks/Online/Sally's Finances/Bank Data.json";

	if (MASH_fs::exists(sfBankD_O::File)) {
		std::ifstream owninput(sfBankD_O::File);
		owninput >> sfBankD_O::Data;
		owninput.close();
	}
	else {
		MASH_cout << "This file does'nt exist yet miBankD_O checking";
	}

	for (MASH_uint i = 0; i < sfBankD_O::Data.size(); i++) {
		if (sfBankD_O::Data[i].contains("Saving")) {
			sfBankD_O::Counter = i;

			break;
		}
		break;
	}
	sfBankD_O::Data[sfBankD_O::Counter]["Saving"]["Regular"]["Bank Amount"] = Amount;

	sfBankD_O::Counter = 0;

	std::ofstream bankoutput(sfBankD_O::File);
	bankoutput << std::setw(4) << sfBankD_O::Data << MASH_endl;
	bankoutput.close();

	//Banks
	std::ifstream banksinput(BanksD::File);
	banksinput >> BanksD::Data;
	for (MASH_uint i = 0; i < BanksD::Data.size(); i++) {
		if (BanksD::Data[i].contains("Online")) {
			BanksD::Counter = i;
			auto globalElement = BanksD::Data[BanksD::Counter]["Online"];
			for (MASH_uint j = 0; j < globalElement.size(); j++) {
				if (globalElement[j].contains("Sally's Finances")) {
					BanksD_O::Counter = j;
					auto localElem = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"];
					for (MASH_uint k = 0; k < localElem.size(); k++) {
						if (localElem[k].contains("Saving")) {
							sfBankD_O::Counter = k;
						}
					}

				}
			}
		}
	}
	BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"][sfBankD_O::Counter]["Saving"]["Regular"]["Bank Amount"] = Amount;

	std::ofstream banksoutput(BanksD::File);
	banksoutput << std::setw(4) << BanksD::Data << MASH_endl;
	banksoutput.close();

	BanksD::Counter = 0;
	BanksD_O::Counter = 0;
	sfBankD_O::Counter = 0;
}

void sfSavingsE::RegSavingsSF::Deposit(MASH_f num)
{
	Amount += num;

	//Own
	sfSavingsD::RegSavingsSF::File = AppD::Folder + "/Banks/Online/Sally's Finances/Accounts/Saving.json";

	if (MASH_fs::exists(sfSavingsD::RegSavingsSF::File)) {
		std::ifstream owninput(sfSavingsD::RegSavingsSF::File);
		owninput >> sfSavingsD::RegSavingsSF::Data;
		owninput.close();

		sfSavingsD::RegSavingsSF::Data["Regular"]["Bank Amount"] = Amount;

		std::ofstream ownoutput(sfSavingsD::RegSavingsSF::File);
		ownoutput << std::setw(4) << sfSavingsD::RegSavingsSF::Data << MASH_endl;
		ownoutput.close();

	}
	else {
		MASH_cout << "This file does'nt exist yet checking";
	}

	//Bank
	sfBankD_O::File = AppD::Folder + "/Banks/Online/Sally's Finances/Bank Data.json";

	if (MASH_fs::exists(sfBankD_O::File)) {
		std::ifstream owninput(sfBankD_O::File);
		owninput >> sfBankD_O::Data;
		owninput.close();
	}
	else {
		MASH_cout << "This file does'nt exist yet miBankD_O checking";
	}

	for (MASH_uint i = 0; i < sfBankD_O::Data.size(); i++) {
		if (sfBankD_O::Data[i].contains("Saving")) {
			sfBankD_O::Counter = i;

			break;
		}
		break;
	}
	sfBankD_O::Data[sfBankD_O::Counter]["Saving"]["Regular"]["Bank Amount"] = Amount;

	sfBankD_O::Counter = 0;

	std::ofstream bankoutput(sfBankD_O::File);
	bankoutput << std::setw(4) << sfBankD_O::Data << MASH_endl;
	bankoutput.close();

	//Banks
	std::ifstream banksinput(BanksD::File);
	banksinput >> BanksD::Data;
	for (MASH_uint i = 0; i < BanksD::Data.size(); i++) {
		if (BanksD::Data[i].contains("Online")) {
			BanksD::Counter = i;
			auto globalElement = BanksD::Data[BanksD::Counter]["Online"];
			for (MASH_uint j = 0; j < globalElement.size(); j++) {
				if (globalElement[j].contains("Sally's Finances")) {
					BanksD_O::Counter = j;
					auto localElem = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"];
					for (MASH_uint k = 0; k < localElem.size(); k++) {
						if (localElem[k].contains("Saving")) {
							sfBankD_O::Counter = k;
						}
					}

				}
			}
		}
	}
	BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"][sfBankD_O::Counter]["Saving"]["Regular"]["Bank Amount"] = Amount;

	std::ofstream banksoutput(BanksD::File);
	banksoutput << std::setw(4) << BanksD::Data << MASH_endl;
	banksoutput.close();

	BanksD::Counter = 0;
	BanksD_O::Counter = 0;
	sfBankD_O::Counter = 0;
}

MASH_f sfSavingsE::RegSavingsSF::GetBankAmount()
{
	return Amount;
}
