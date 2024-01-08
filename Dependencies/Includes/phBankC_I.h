#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "OtherE.h"
#include "phCheckingsE.h"
#include "phSavingsE.h"
#include "BaseO.h"

#include "Universal/Universal.h"

class phBankC_I {
public:
	void Choice(MASH_vec<MASH_str>);
};