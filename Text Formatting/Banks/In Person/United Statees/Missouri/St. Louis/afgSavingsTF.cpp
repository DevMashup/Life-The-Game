#include "afgSavingsTF.h"

MASH_int64t afgSavingsTF::RegSavingsAFG::accNum = 0;
MASH_f afgSavingsTF::RegSavingsAFG::Amount = 0;

void afgSavingsTF::RegSavingsAFG::Log()
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
	MASH_cout << "Bank: ArchCity Financial Group" << MASH_endl;
	MASH_cout << "Account Type: Regular Saving" << MASH_endl;
	MASH_cout << "Acc #: Saving-" << accNum << MASH_endl;
	MASH_cout << "Amount: " << Amount << " " << AppD::Currency << MASH_endl;
}
