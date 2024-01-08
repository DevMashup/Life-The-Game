#pragma once

#include "BanksD.h"
#include "BanksT.h"
#include "BanksC.h"
#include "ReuseO.h"
#include "BanksE_I.h"

#include "AppO.h"
#include "ReuseO.h"
#include "BaseO.h"
#include "Universal/Universal.h"

class BanksE {
public:
	void Create();
	void Info();
	void Transfer();
private:
	static MASH_uint list;
	static MASH_uint Counter;
	static MASH_vec<BankO*> accs;
};