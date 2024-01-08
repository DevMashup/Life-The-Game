#include "sfSavingsTF.h"

MASH_int64t sfSavingsTF::RegSavingsSF::accNum = 0;
MASH_f sfSavingsTF::RegSavingsSF::Amount = 0.00;

void sfSavingsTF::RegSavingsSF::Log()
{
	Universal u;

	MASH_str topBorder = "----------------------------------------";
	MASH_str title = AppD::User + "'s Savings";

	int placement = (topBorder.length() - title.length()) / 2;

	//u.SH(40 + placement);
	//u.MASH_LOG(title.c_str());
	//u.SH(40);
	//u.MASH_LOG("----------------------------------------");

	MASH_cout << "Account Holder: " << AppD::User << MASH_endl;
	MASH_cout << "Bank: Sally's Finances" << MASH_endl;
	MASH_cout << "Account Type: Regular Savings" << MASH_endl;
	MASH_cout << "Acc #: Savings-" << accNum << MASH_endl;
	MASH_cout << "Amount: " << Amount << " " << AppD::Currency << MASH_endl;
}
