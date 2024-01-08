#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "OtherE.h"
#include "spbCheckingsE.h"
#include "spbSavingsE.h"
#include "BaseO.h"

#include "Universal/Universal.h"

class spbBankC_I {
public:
	void Choice(MASH_vec<MASH_str>&);
};