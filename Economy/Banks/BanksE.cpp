#include "BanksE.h"

MASH_uint BanksE::list = 1;
MASH_uint BanksE::Counter = 0;
MASH_vec<BankO*> BanksE::accs;

void BanksE::Create()
{
	Universal u;

	BanksD bD;
	BanksT bT;
	BanksC bC;
	ReuseO rO;

	MASH_str line;

	bD.CreateData();

	if (RandomO::YoB > 1959 && RandomO::BCorAD == "A.D") { //Done
		MASH_cout << "Hello " + AppD::User + "!!! We have one mode you can choose from" << MASH_endl;
	
		u.SV(2);
		bT.CreateTable();
		u.SV();

		MASH_cout << "What mode would you perfer?: ";
		getline(MASH_cin, line);
		MASH_vec<MASH_str> command = rO.Split(line, " ");
		u.SV();

		bC.Choice(command);
	}
	else if(RandomO::YoB < 1960 || RandomO::BCorAD == "B.C") {
		BanksE_I bE_i;

		bE_i.Create();
	}
}

void BanksE::Info()
{
	Universal u;

	ReuseO rO;

	BanksD::File = AppD::Folder + "/Banks/Global.json";

	if (MASH_fs::exists(BanksD::File)) {
		rO.RecreateBank();
		
		if (miCheckingsE::RegCheckingsMI::hasAccount) {
			miCheckingsTF::RegCheckingsMI checking;

			checking.Log();
		}

		u.SV(1);

		if (miSavingsE::RegSavingsMI::hasAccount) {
			miSavingsTF::RegSavingsMI checking;

			checking.Log();
		}
		u.SV();
		if (sfCheckingsE::RegCheckingsSF::hasAccount) {
			sfCheckingsTF::RegCheckingsSF checking;

			checking.Log();
		}
		u.SV();
		if (sfSavingsE::RegSavingsSF::hasAccount) {
			sfSavingsTF::RegSavingsSF checking;

			checking.Log();
		}
		u.SV();
		if (spbCheckingsE::RegCheckingsSPB::hasAccount) {
			spbCheckingsTF::RegCheckingsSPB checking;

			checking.Log();
		}
		u.SV();
		if (spbSavingsE::RegSavingsSPB::hasAccount) {
			spbSavingsTF::RegSavingsSPB checking;

			checking.Log();
		}
		u.SV();
		if (phCheckingsE::RegCheckingsPH::hasAccount) {
			phCheckingsTF::RegCheckingsPH checking;

			checking.Log();
		}
		u.SV();
		if (phSavingsE::RegSavingsPH::hasAccount) {
			phSavingsTF::RegSavingsPH checking;

			checking.Log();
		}
		u.SV();
		if (ghbCheckingsE::RegCheckingsGHB::hasAccount) {
			ghbCheckingsTF::RegCheckingsGHB checking;

			checking.Log();
		}
		u.SV();
		if (ghbSavingsE::RegSavingsGHB::hasAccount) {
			ghbSavingsTF::RegSavingsGHB checking;

			checking.Log();
		}
		u.SV();
		if (afgCheckingsE::RegCheckingsAFG::hasAccount) {
			afgCheckingsTF::RegCheckingsAFG checking;

			checking.Log();
		}
		if (afgSavingsE::RegSavingsAFG::hasAccount) {
			afgSavingsTF::RegSavingsAFG checking;

			checking.Log();
		}

		char YorN;
		MASH_cout << "Do you wanna go back to the main menu?: (Please type 'Y' or 'N')";
		MASH_cin >> YorN;
		u.SV(2);

		if (YorN == 'Y' || YorN == 'y') {
			AppO aO;

			aO.ConApp();
		}
		else {
			MASH_exit;
		}
	}
	else {
		Universal u;

		TemporaryO tO;

		MASH_cout << "Global bank file does not exist. please try again";
		u.SV();

		tO.MainMenu();
	}

}

void BanksE::Transfer()
{
	ReuseO rO;

	BanksD::File = AppD::Folder + "/Banks/Global.json";

	if (MASH_fs::exists(BanksD::File)) {
		rO.RecreateBank();

		MASH_cout << "Checking is " + miCheckingsE::RegCheckingsMI::hasAccount << MASH_endl;
		MASH_cout << "Saving is " + miSavingsE::RegSavingsMI::hasAccount << MASH_endl;
		if (miCheckingsE::RegCheckingsMI::hasAccount) {
			MASH_cout << list << ".) Mashup Inc[Check-" << miCheckingsE::RegCheckingsMI::accNum << "]" << MASH_endl;
			accs.push_back(new miCheckingsE::RegCheckingsMI());

			list++;
		}
		if (miSavingsE::RegSavingsMI::hasAccount) {
			MASH_cout << list << ".) Mashup Inc[Save-" << miSavingsE::RegSavingsMI::accNum << "]" << MASH_endl;
			accs.push_back(new miSavingsE::RegSavingsMI());

			list++;
		}
		if (sfCheckingsE::RegCheckingsSF::hasAccount) {
			MASH_cout << list << ".) Sally's Finances[Check-" << sfCheckingsE::RegCheckingsSF::accNum << "]" << MASH_endl;
			accs.push_back(new sfCheckingsE::RegCheckingsSF());

			list++;
		}
		if (sfSavingsE::RegSavingsSF::hasAccount) {
			MASH_cout << list << ".) Sally's Finances[Save-" << sfSavingsE::RegSavingsSF::accNum << "]" << MASH_endl;
			accs.push_back(new sfSavingsE::RegSavingsSF());

			list++;
		}
		if (phCheckingsE::RegCheckingsPH::hasAccount) {
			MASH_cout << list << ".) Plaza Horizon[Check-" << phCheckingsE::RegCheckingsPH::accNum << "]" << MASH_endl;
			accs.push_back(new phCheckingsE::RegCheckingsPH());

			list++;
		}
		if (phSavingsE::RegSavingsPH::hasAccount) {
			MASH_cout << list << ".) Plaza Horizon[Save-" << phSavingsE::RegSavingsPH::accNum << "]" << MASH_endl;
			accs.push_back(new phSavingsE::RegSavingsPH());

			list++;
		}
		if (spbCheckingsE::RegCheckingsSPB::hasAccount) {
			MASH_cout << list << ".) Summit Prairie Bank[Check-" << spbCheckingsE::RegCheckingsSPB::accNum << "]" << MASH_endl;
			accs.push_back(new spbCheckingsE::RegCheckingsSPB());

			list++;
		}

		if (spbSavingsE::RegSavingsSPB::hasAccount) {
			MASH_cout << list << ".) Summit Prairie Bank[Save-" << spbSavingsE::RegSavingsSPB::accNum << "]" << MASH_endl;
			accs.push_back(new spbSavingsE::RegSavingsSPB());

			list++;
		}

		if (afgCheckingsE::RegCheckingsAFG::hasAccount) {
			MASH_cout << list << ".) ArchCity Financial Group[Check-" << afgCheckingsE::RegCheckingsAFG::accNum << "]" << MASH_endl;
			accs.push_back(new afgCheckingsE::RegCheckingsAFG());

			list++;
		}
		if (afgSavingsE::RegSavingsAFG::hasAccount) {
			MASH_cout << list << ".) ArchCity Financial Group[Save-" << afgSavingsE::RegSavingsAFG::accNum << "]" << MASH_endl;
			accs.push_back(new afgSavingsE::RegSavingsAFG());

			list++;
		}
		if (ghbCheckingsE::RegCheckingsGHB::hasAccount) {
			MASH_cout << list << ".) Gateway Heights Bank[Check-" << ghbCheckingsE::RegCheckingsGHB::accNum << "]" << MASH_endl;
			accs.push_back(new ghbCheckingsE::RegCheckingsGHB());

			list++;
		}

		if (ghbSavingsE::RegSavingsGHB::hasAccount) {
			MASH_cout << list << ".) Gateway Hieghts[Save-" << ghbSavingsE::RegSavingsGHB::accNum << "]" << MASH_endl;
			accs.push_back(new ghbSavingsE::RegSavingsGHB());

			list++;
		}

		if (list < 2) {
			MASH_cout << "You only appear to have 1 or no accounts." << MASH_endl;
		}
		else if (list > 1) {
			Universal u;

			AppO aO;

			MASH_str word;
			MASH_cout << "What would you like to do?: (Please type either 'Deposit' or 'Withdrawal'";
			MASH_cin >> word;
			u.SV(2);

			if (word.size() == 0) {
				MASH_cout << "Please type either 'Deposit' or 'Withdrawal";
				u.SV();

				aO.ConApp();
			}
			else {
				if (word == "Deposit" || word == "deposit") {
					MASH_uint firstNum;
					MASH_uint secNum;
					MASH_f Amount;

					MASH_cout << "Please enter a number associated with account you wanna put money into: ";
					MASH_cin >> firstNum;
					u.SV(2);

					MASH_cout << "Please enter a number associated with account you wanna take money from: ";
					MASH_cin >> secNum;
					u.SV(2);

					MASH_cout << "Please enter an amount: ";
					MASH_cin >> Amount;
					u.SV(2);

					if (Amount > accs[secNum - 1]->GetBankAmount()) {
						MASH_cout << "Not enough money to withdrawal" << MASH_endl;
					} 
					else if (Amount <= accs[secNum - 1]->GetBankAmount()) {
						accs[firstNum - 1]->Deposit(Amount);
						accs[secNum - 1]->Withdrawal(Amount);

					}
				}
				else if (word == "Withdrawal" || word == "withdrawal") {
					MASH_uint firstNum;
					MASH_uint secNum;
					MASH_f Amount;

					MASH_cout << "Please enter a number associated with account you wanna take money from: ";
					MASH_cin >> firstNum;
					u.SV(2);

					MASH_cout << "Please enter a number associated with account you wanna put money into: ";
					MASH_cin >> secNum;
					u.SV(2);


					MASH_cout << "Please enter an amount: ";
					MASH_cin >> Amount;
					u.SV(2);

					if (Amount > accs[firstNum - 1]->GetBankAmount()) {
						MASH_cout << "Not enough money to withdrawal" << MASH_endl;
					}
					else if (Amount <= accs[firstNum - 1]->GetBankAmount()) {
						accs[firstNum - 1]->Withdrawal(Amount);
						accs[secNum - 1]->Deposit(Amount);

					}
				}
				else {
					MASH_cout << "Have a suggestion on where this menu should take you. E-mail me at realdevmashup@gmail.com and your suggestion might get implemented" << MASH_endl;

					MASH_exit;
				}
			}
		}

		list = 1;

		Universal u;

		char YorN;
		MASH_cout << "Do you wanna go back to the main menu?: (Please type 'Y' or 'N')";
		MASH_cin >> YorN;
		u.SV(2);

		if (YorN == 'Y' || YorN == 'y') {
			AppO aO;

			aO.ConApp();
		}
		else {
			MASH_exit;
		}
	}
	else {
		Universal u;

		TemporaryO tO;

		MASH_cout << "Global bank file does not exist. please try again";
		u.SV();

		tO.MainMenu();
	}
}
