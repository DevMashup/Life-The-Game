#pragma once

#include <iostream>
#include <string>

#include "Universal/Universal.h"

class affShopE {
public:
	void Shop(MASH_str);

	static MASH_str hasPet;
private:
	void Logic(MASH_str);
};