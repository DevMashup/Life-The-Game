#include "BanksC_I.h"

void BanksC_I::Choice()
{
	if (AppD::currentCity == "Kansas City, MO") {
		usBanksD_I usD_iBanks;
		moBanksD_I mobD_I;
		kcmoBanksE_I kcmobE_I;

		usD_iBanks.CreateData();
		mobD_I.CreateData();

		kcmobE_I.Create();
	}
	else if (AppD::currentCity == "St. Louis, MO") {
		usBanksD_I usD_iBanks;
		moBanksD_I mobD_I;
		slmoBanksE_I slmobE_I;

		usD_iBanks.CreateData();
		mobD_I.CreateData();

		slmobE_I.Create();
	}
}
