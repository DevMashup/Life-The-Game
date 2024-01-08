#include "TemporaryO.h"

void TemporaryO::miSaveAcc()
{
	BankO* savings = new miSavingsE::RegSavingsMI();

	savings->Create();

	delete savings;
}

void TemporaryO::miCheckAcc()
{
	BankO* check = new miCheckingsE::RegCheckingsMI();

	check->Create();

	delete check;
}

void TemporaryO::sfSaveAcc()
{
	BankO* save = new sfSavingsE::RegSavingsSF();

	save->Create();

	delete save;
}

void TemporaryO::sfCheckAcc()
{
	BankO* check = new sfCheckingsE::RegCheckingsSF();

	check->Create();

	delete check;
}

void TemporaryO::spbSaveAcc()
{
	BankO* save = new spbSavingsE::RegSavingsSPB();

	save->Create();

	delete save;
}

void TemporaryO::spbCheckAcc()
{
	BankO* check = new spbCheckingsE::RegCheckingsSPB();;

	check->Create();

	delete check;
}

void TemporaryO::phSaveAcc()
{
	BankO* save = new phSavingsE::RegSavingsPH();

	save->Create();
	delete save;
}

void TemporaryO::phCheckAcc()
{
	BankO* check = new phCheckingsE::RegCheckingsPH();;

	check->Create();
	delete check;
}

void TemporaryO::afgSaveAcc()
{
	BankO* save = new afgSavingsE::RegSavingsAFG();

	save->Create();
}

void TemporaryO::afgCheckAcc()
{
	BankO* check = new afgCheckingsE::RegCheckingsAFG();

	check->Create();
	delete check;
}

void TemporaryO::ghbSaveAcc()
{
	BankO* save = new ghbSavingsE::RegSavingsGHB();

	save->Create();
	delete save;
}

void TemporaryO::ghbCheckAcc()
{
	BankO* check = new ghbCheckingsE::RegCheckingsGHB();;

	check->Create();

	delete check;
}

void TemporaryO::MainMenu()
{
	AppO aO;

	aO.ConApp();
}
