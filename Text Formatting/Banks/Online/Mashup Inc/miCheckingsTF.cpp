#include "miCheckingsTF.h"

MASH_int64t miCheckingsTF::RegCheckingsMI::accNum = 0;
MASH_f miCheckingsTF::RegCheckingsMI::Amount = 0.00;

void miCheckingsTF::RegCheckingsMI::Log()
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
	MASH_cout << "Bank: Mashup Inc Banking Division" << MASH_endl;
	MASH_cout << "Account Type: Regular Checking" << MASH_endl;
	MASH_cout << "Acc #: Checking-" << accNum << MASH_endl;
	MASH_cout << "Amount: " << Amount << " " << AppD::Currency << MASH_endl;
} 
