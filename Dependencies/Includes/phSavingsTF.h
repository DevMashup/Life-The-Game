#pragma once

#include <iostream>

#include "AppD.h"

#include "Universal/Universal.h"

class phSavingsTF {
public:
	class RegSavingsPH {
	public:
		void Log();

		static MASH_int64t accNum;
		static MASH_f Amount;
	};
};
