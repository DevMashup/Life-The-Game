#include "phSavingsTF.h"

MASH_int64t phSavingsTF::RegSavingsPH::accNum = 0;
MASH_f phSavingsTF::RegSavingsPH::Amount = 0.00;

void phSavingsTF::RegSavingsPH::Log()
{
	Universal u;

	MASH_str topBorder = "----------------------------------------";
	MASH_str title = AppD::User + "'s Checking";

	int placement = (topBorder.length() - title.length()) / 2;

	//u.SH(40 + placement);
	//u.MASH_LOG(title.c_str());
	//u.SH(40);
	//u.MASH_LOG("----------------------------------------");

	MASH_cout << "Account Holder: " << AppD::User << MASH_endl;
	MASH_cout << "Bank: Plaza Horizon" << MASH_endl;
	MASH_cout << "Account Type: Regular Saving" << MASH_endl;
	MASH_cout << "Acc #: Sav-" << accNum << MASH_endl;
	MASH_cout << "Amount: " << Amount << " " << AppD::Currency << MASH_endl;
}
