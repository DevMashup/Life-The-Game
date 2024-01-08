#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "sfBankC_O.h"
#include "sfBankD_O.h"
#include "sfBankT_O.h"
#include "ReuseO.h"

#include "Universal/Universal.h"

class sfBankE_O {
public:
	void Create();

	static MASH_uint accCounter;
};