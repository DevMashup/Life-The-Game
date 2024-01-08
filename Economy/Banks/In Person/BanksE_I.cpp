#include "BanksE_I.h"

void BanksE_I::Create()
{
	BanksD_I bD_I;
	BanksC_I bC_I;

	bD_I.CreateData();
	bC_I.Choice();
}
