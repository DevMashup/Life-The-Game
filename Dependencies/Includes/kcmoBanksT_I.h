#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Universal/Universal.h"

class kcmoBanksT_I {
public:
	void CreateTable();
private:
	void TableNote();
	void AddItems(MASH_vec<MASH_str>&);
};