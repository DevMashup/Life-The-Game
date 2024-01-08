#include "spbCheckingsTF.h"

MASH_int64t spbCheckingsTF::RegCheckingsSPB::accNum = 0.00;
MASH_f spbCheckingsTF::RegCheckingsSPB::Amount = 0.00;

void spbCheckingsTF::RegCheckingsSPB::Log()
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
	MASH_cout << "Bank: Summit Prairie Bank" << MASH_endl;
	MASH_cout << "Account Type: Regular Checking" << MASH_endl;
	MASH_cout << "Acc #: Checking-" << accNum << MASH_endl;
	MASH_cout << "Amount: " << Amount << " " << AppD::Currency << MASH_endl;
}
