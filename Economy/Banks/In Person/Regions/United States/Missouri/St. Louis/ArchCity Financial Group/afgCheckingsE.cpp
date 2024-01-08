#include "afgCheckingsE.h"

MASH_b afgCheckingsE::RegCheckingsAFG::hasAccount = false;
MASH_f afgCheckingsE::RegCheckingsAFG::Amount = 0.00;
MASH_int64t afgCheckingsE::RegCheckingsAFG::accNum = 0;
MASH_b afgCheckingsE::RegCheckingsAFG::hasCard = false;

void afgCheckingsE::RegCheckingsAFG::Create()
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
				auto element = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"]
					[usBanksD_I::Counter]["Missouri"][moBanksD_I::Counter]["St. Louis"][slmoBanksD_I::Counter]
					["ArchCity Financial Group"];

				for (MASH_uint i = 0; i < element.size(); i++) {
					if (element[i].contains("Checking")) {
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

			MASH_cout << "Thank you for choosing ArchCity Financial Group. Unfourtanly, since your only " << AppD::Age;
			MASH_cout << " years old, you'll have to ask one of your parents to help you open the account. Which parent do";
			MASH_cout << " you wanna ask first: (Please type 'Father' or 'Mother'";
			MASH_cin >> Parent;
			u.SV(2);

			afgCheckingsD::RegCheckingsAFG checkingsD;
			afgCheckingsTF::RegCheckingsAFG checkingsTF;

			accNum = accNumrnd;

			afgCheckingsD::RegCheckingsAFG::Amount = Amount;
			afgCheckingsD::RegCheckingsAFG::accNum = accNum;

			afgCheckingsTF::RegCheckingsAFG::accNum = accNum;

			checkingsD.CreateData();

			if (Parent == "Father" || Parent == "father") {
				if (fatherHelp == 1) {

					MASH_cout << "Congrats!! You're father decided to help you open an account. ";
					hasAccount = true;

					if (getCard != 5) {
						MASH_cout << "He also got you you're own credit card" << MASH_endl;
						u.SV();

						MASH_cout << "As a thankyou for opening an account at Plaza Horizon, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						hasCard = true;
						afgCheckingsTF::RegCheckingsAFG::Amount = Amount;

						u.SV();
						checkingsTF.Log();

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
						MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Plaza Horizon, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						u.SV();

						afgCheckingsTF::RegCheckingsAFG::Amount = Amount;
						checkingsTF.Log();

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
							checkingsD.CreateData();

							MASH_cout << "Congrats!! You're mother decided to help you open an account. ";
							hasAccount = true;

							if (getCard != 5) {
								MASH_cout << "she also got you you're own credit card" << MASH_endl;
								u.SV();

								MASH_cout << "As a thankyou for opening an account at Plaza Horizon, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								hasCard = true;
								afgCheckingsTF::RegCheckingsAFG::Amount = Amount;

								u.SV();
								checkingsTF.Log();

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
								MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Plaza Horizon, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								u.SV();
								afgCheckingsTF::RegCheckingsAFG::Amount = Amount;
								checkingsTF.Log();

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

					checkingsD.CreateData();

					MASH_cout << "Congrats!! You're mother decided to help you open an account. ";
					hasAccount = true;

					if (getCard != 5) {
						MASH_cout << "She also got you you're own credit card" << MASH_endl;
						u.SV();

						MASH_cout << "As a thankyou for opening an account at Plaza Horizon, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						hasCard = true;
						afgCheckingsTF::RegCheckingsAFG::Amount = Amount;

						u.SV();
						checkingsTF.Log();

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
						MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Plaza Horizon, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
						Deposit(250.00);

						u.SV();

						afgCheckingsTF::RegCheckingsAFG::Amount = Amount;
						checkingsTF.Log();

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
							checkingsD.CreateData();

							MASH_cout << "Congrats!! You're father decided to help you open an account. ";
							hasAccount = true;

							if (getCard != 5) {
								MASH_cout << "he also got you you're own credit card" << MASH_endl;
								u.SV();

								MASH_cout << "As a thankyou for opening an account at Plaza Horizon, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								hasCard = true;
								afgCheckingsTF::RegCheckingsAFG::Amount = Amount;

								u.SV();
								checkingsTF.Log();

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
								MASH_cout << " when you're 16 or older and purchase you're own credit card but as a thankyou for opening an account at Summit Prairie, you get an initial deposit of 250 " << AppD::Currency << "." << MASH_endl;
								Deposit(250.00);

								u.SV();
								afgCheckingsTF::RegCheckingsAFG::Amount = Amount;
								checkingsTF.Log();

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

			afgCheckingsD::RegCheckingsAFG checkingsD;
			afgCheckingsTF::RegCheckingsAFG checkingsTF;

			accNum = accNumrnd;

			afgCheckingsD::RegCheckingsAFG::Amount = Amount;
			afgCheckingsD::RegCheckingsAFG::accNum = accNum;

			afgCheckingsTF::RegCheckingsAFG::accNum = accNum;

			checkingsD.CreateData();
			MASH_cout << "Thank you for opening an account at Plaza Horizon As a reward, you'll get an intial deposit of 250 " << AppD::Currency << "." << MASH_endl;
			Deposit(250.00);
			u.SV(2);

			phCheckingsTF::RegCheckingsPH::Amount = Amount;
			hasAccount = true;
			checkingsTF.Log();

			MASH_cout << "Would you like to buy a credit card for 50 " << AppD::Currency << "?: (Please type 'Y' or 'N')";
			MASH_cin >> YorN;
			u.SV(2);

			if (YorN == 'Y' || YorN == 'y') {
				Withdrawal(50.00);

				MASH_cout << "Thank you for purchasing a credit card. As a reward here's 10 50% off coupons on any of our products" << MASH_endl;
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
						MASH_cout << "Congrats!!! you have a credit card";
						hasCard = true;
					}
					else {
						MASH_cout << "Oh no!!! It appears you do not have enough money to buy a credit card";

						aO.ConApp();
					}
				}
				else if (YorN == 'N' || YorN == 'n') {
					char YorN;

					MASH_cout << "Did you want to open a savings account instead?: (Please type 'Y' or 'N'";
					MASH_cin >> YorN;
					u.SV();

					if (YorN == 'Y' || YorN == 'y') {
						TemporaryO tO;

						tO.afgSaveAcc();
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

void afgCheckingsE::RegCheckingsAFG::Withdrawal(MASH_f num)
{
	Amount -= num;

	spbSavingsD::RegSavingsSPB::File = AppD::Folder + "/Banks/In Person/United States/Missouri/Kansas City/Summit Prairie Bank/Accounts/Saving.json";

	if (MASH_fs::exists(spbSavingsD::RegSavingsSPB::File)) {
		std::ifstream owninput(spbSavingsD::RegSavingsSPB::File);
		owninput >> spbSavingsD::RegSavingsSPB::Data;
		owninput.close();

		spbSavingsD::RegSavingsSPB::Data["Regular"]["Bank Amount"] = Amount;

		std::ofstream ownoutput(spbSavingsD::RegSavingsSPB::File);
		ownoutput << std::setw(4) << spbSavingsD::RegSavingsSPB::Data << MASH_endl;
		ownoutput.close();
	}
	else {
		MASH_cout << "This file does'nt exist yet checking";
	}

	//Bank
	spbBankD_I::File = AppD::Folder + "/Banks/In Person/United States/Missouri/Kansas City/Summit Prairie Bank/Bank Data.json";

	if (MASH_fs::exists(spbBankD_I::File)) {
		std::ifstream owninput(spbBankD_I::File);
		owninput >> spbBankD_I::Data;
		owninput.close();
	}
	else {
		MASH_cout << "This file does'nt exist yet miBankD_O checking";
	}

	for (MASH_uint i = 0; i < spbBankD_I::Data.size(); i++) {
		if (spbBankD_I::Data[i].contains("Checking")) {
			spbBankD_I::Counter = i;

			break;
		}
		break;
	}
	spbBankD_I::Data[spbBankD_I::Counter]["Checking"]["Regular"]["Bank Amount"] = Amount;

	spbBankD_I::Counter = 0;

	std::ofstream bankoutput(spbBankD_I::File);
	bankoutput << std::setw(4) << spbBankD_I::Data << MASH_endl;
	bankoutput.close();

	//Banks
	std::ifstream banksinput(BanksD::File);
	banksinput >> BanksD::Data;
	for (MASH_uint i = 0; i < BanksD::Data.size(); i++) {
		if (BanksD::Data[i].contains("In Person")) {
			BanksD::Counter = i;
			auto globalElement = BanksD::Data[BanksD::Counter]["In Person"];
			for (MASH_uint j = 0; j < globalElement.size(); j++) {
				if (globalElement[j].contains("United States")) {
					BanksD_I::Counter = j;
					auto regionElem = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"];
					for (MASH_uint k = 0; k < regionElem.size(); k++) {
						if (regionElem[k].contains("Missouri")) {
							usBanksD_I::Counter = k;
							auto stateElem = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]
								["United States"][usBanksD_I::Counter]["Missouri"];
							for (MASH_uint l = 0; l < stateElem.size(); l++) {
								if (stateElem[l].contains("Kansas City")) {
									moBanksD_I::Counter = l;
									auto cityElem = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]
										["United States"][usBanksD_I::Counter]["Missouri"][moBanksD_I::Counter]
										["Kansas City"];
									for (MASH_uint m = 0; m < cityElem.size(); m++) {
										if (cityElem[m].contains("Summit Prairie Bank")) {
											kcmoBanksD_I::Counter = l;
											auto localElem = BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]
												["United States"][usBanksD_I::Counter]["Missouri"][moBanksD_I::Counter]
												["Kansas City"][kcmoBanksD_I::Counter]["Summit Prairie Bank"];
											for (MASH_uint n = 0; n < cityElem.size(); m++) {
												if (localElem[n].contains("Saving")) {
													spbBankD_I::Counter = n;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]["Missouri"]
		[moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]["ArchCity Financial Group"][afgBankD_I::Counter]
		["Saving"]["Regular"]["Bank Amount"] = Amount;
	std::ofstream banksoutput(BanksD::File);
	banksoutput << std::setw(4) << BanksD::Data << MASH_endl;
	banksoutput.close();
	BanksD::Counter = 0;
	BanksD_I::Counter = 0;
	usBanksD_I::Counter = 0;
	moBanksD_I::Counter = 0;
	slmoBanksD_I::Counter = 0;
	afgBankD_I::Counter = 0;
}

void afgCheckingsE::RegCheckingsAFG::Deposit(MASH_f num)
{
	Amount += num;

	//Own
	std::ifstream owninput(afgCheckingsD::RegCheckingsAFG::File);
	owninput >> afgCheckingsD::RegCheckingsAFG::Data;
	owninput.close();

	afgCheckingsD::RegCheckingsAFG::Data["Regular"]["Bank Amount"] = Amount;

	std::ofstream ownoutput(afgCheckingsD::RegCheckingsAFG::File);
	ownoutput << std::setw(4) << afgCheckingsD::RegCheckingsAFG::Data << MASH_endl;
	ownoutput.close();

	//Bank
	std::ifstream bankinput(afgBankD_I::File);
	bankinput >> afgBankD_I::Data;
	bankinput.close();

	for (MASH_uint i = 0; i < afgBankD_I::Data.size(); i++) {
		if (afgBankD_I::Data[i].contains("Checking")) {
			afgBankD_I::Counter = i;

			break;
		}
		break;
	}
	afgBankD_I::Data[afgBankD_I::Counter]["Checking"]["Regular"]["Bank Amount"] = Amount;

	std::ofstream bankoutput(afgBankD_I::File);
	bankoutput << std::setw(4) << afgBankD_I::Data << MASH_endl;
	bankoutput.close();

	//Banks
	std::ifstream banksinput(BanksD::File);
	banksinput >> BanksD::Data;
	banksinput.close();

	//auto dataElement = BanksD::Data["In Person"][BanksD_I::Counter]["United States"]
	//	[usBanksD_I::Counter]["Missouri"][moBanksD_I::Counter]["Kansas City"][kcmoBanksD_I::Counter]
	//	["Plaza Horizon"];

	//if (dataElement.size() == 0) { //Never tuns
	//	phBankD_I::Counter = 0;
	//}
	//else {
	//	for (MASH_uint i = 0; i < dataElement.size(); i++) {
	//		if (dataElement[i].contains("Checking")) {
	//			phBankD_I::Counter = i;
	//		}
	//		else if (dataElement[i].contains("Saving")) {
	//			phBankD_I::Counter++;
	//		}
	//	}
	//}
	BanksD::Data[BanksD::Counter]["In Person"][BanksD_I::Counter]["United States"][usBanksD_I::Counter]["Missouri"]
		[moBanksD_I::Counter]["St. Louis"][slmoBanksD_I::Counter]["ArchCity Financial Group"][afgBankD_I::Counter]
		["Checking"]["Regular"]["Bank Amount"] = Amount;
	//miBankD_O::Counter++;

	std::ofstream banksoutput(BanksD::File);
	banksoutput << std::setw(4) << BanksD::Data << MASH_endl;
	banksoutput.close();
}

MASH_f afgCheckingsE::RegCheckingsAFG::GetBankAmount()
{
	return Amount;
}
