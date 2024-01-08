#pragma once

#include <iostream>

#include "AppD.h"

#include "Universal/Universal.h"

class sfSavingsTF {
public:
	class RegSavingsSF {
	public:
		void Log();

		static MASH_int64t accNum;
		static MASH_f Amount;
	};
};