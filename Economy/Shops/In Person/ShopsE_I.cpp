#include "ShopsE_I.h"

void ShopsE_I::Create(MASH_str mode)
{
	ShopsD_I sD_I;

	sD_I.CreateData();
	if (AppD::currentCity == "Kansas City, MO") {
		usShopsD_I usD_Is;
		moShopsD_I moD_Is;
		kcmoShopsE_I kcmoE_Is;

		usD_Is.CreateData();
		moD_Is.CreateData();

		kcmoE_Is.Create(mode);
	}
	else if (AppD::currentCity == "St. Louis, MO") {
		usShopsD_I usD_Is;
		moShopsD_I moD_Is;

		usD_Is.CreateData();
		moD_Is.CreateData();
	}
}
