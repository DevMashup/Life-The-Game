#pragma once

#include "miCheckingsE.h"
#include "miSavingsE.h"
#include "sfCheckingsE.h"
#include "sfSavingsE.h"
#include "spbCheckingsE.h"
#include "spbSavingsE.h"
#include "phCheckingsE.h"
#include "phSavingsE.h"
#include "ghbCheckingsE.h"
#include "ghbSavingsE.h"
#include "afgCheckingsE.h"
#include "afgSavingsE.h"
#include "AppO.h"

#include "BaseO.h"

class TemporaryO {
public:
	void miSaveAcc();
	void miCheckAcc();
	void sfSaveAcc();
	void sfCheckAcc();
	void spbSaveAcc();
	void spbCheckAcc();
	void phSaveAcc();
	void phCheckAcc();
	void afgSaveAcc();
	void afgCheckAcc();
	void ghbSaveAcc();
	void ghbCheckAcc();
	void MainMenu();
};