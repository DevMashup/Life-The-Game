#include "miPositionsE.h"

MASH_uint miPositionsE::Pilot::raiseStatus = 0;

void miPositionsE::Pilot::Hired()
{
	if (raiseStatus == 0) {
		MASH_cout << "Welcome to Mashup Inc: Travel Division. We always need new pilots. Welcome to the";
		MASH_cout << " Mashup Inc family" << MASH_endl;
	}

	if (raiseStatus == 0 || raiseStatus == 1) {
		MASH_cout << "Since this is the first time on the job, you get an initial payment of 18.00" << 
		AppD::Currency << "that will be deposited into your wallet. You can then the use the 'Bank T' command";
		MASH_cout << " to transfer that money into a bank account of your choosing." << MASH_endl;

		AppD::walletAmount += 18.00;
		raiseStatus++;
	} 
	else if (raiseStatus == 2 || raiseStatus == 3) {
		MASH_cout << "Congrats, you got a promotion...and with that promotion, you get a payment of 22.00" <<
		AppD::Currency << "that will be deposited into your wallet. You can then the use the 'Bank T' command";
		MASH_cout << " to transfer that money into a bank account of your choosing." << MASH_endl;

		AppD::walletAmount += 22.00;
		raiseStatus++;
	}
	else if (raiseStatus == 4 || raiseStatus == 5) {
		MASH_cout << "Congrats, you got a promotion...and with that promotion, you get a payment of 24.00" <<
		AppD::Currency << "that will be deposited into your wallet. You can then the use the 'Bank T' command";
		MASH_cout << " to transfer that money into a bank account of your choosing." << MASH_endl;

		AppD::walletAmount += 24.00;
		raiseStatus++;
	}
	else if (raiseStatus == 6 || raiseStatus == 7) {
		MASH_cout << "Congrats, you got a promotion...and with that promotion, you get a payment of 26.00" <<
		AppD::Currency << "that will be deposited into your wallet. You can then the use the 'Bank T' command";
		MASH_cout << " to transfer that money into a bank account of your choosing." << MASH_endl;

		AppD::walletAmount += 26.00;
		raiseStatus++;
	}
	else if (raiseStatus == 8 || raiseStatus == 9) {
		MASH_cout << "Congrats, you got a promotion...and with that promotion, you get a payment of 28.00" <<
		AppD::Currency << "that will be deposited into your wallet. You can then the use the 'Bank T' command";
		MASH_cout << " to transfer that money into a bank account of your choosing." << MASH_endl;

		AppD::walletAmount += 28.00;
		raiseStatus++;
	}
	else if (raiseStatus == 10 || raiseStatus == 11) {
		MASH_cout << "Congrats, you got a promotion...and with that promotion, you get a payment of 30.00" <<
		AppD::Currency << "that will be deposited into your wallet. You can then the use the 'Bank T' command";
		MASH_cout << " to transfer that money into a bank account of your choosing." << MASH_endl;

		AppD::walletAmount += 30.00;
		raiseStatus++;
	}
	else {
		MASH_cout << "You are already at the top position. You still earn 30.00 " << AppD::Currency << " but if ";
		MASH_cout << "wanna earn more money, you going to have to get a differnt job." << MASH_endl;
	}
}
