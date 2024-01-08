#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Universal/Universal.h"

class kcmoShopsT_I {
public:
	void CreateTable();
private:
	void TableNote();
	void AddItems(MASH_vec<MASH_str>&);
};