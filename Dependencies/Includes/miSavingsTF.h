#pragma once

#include <iostream>

#include "AppD.h"

#include "Universal/Universal.h"

class miSavingsTF {
public:
	class RegSavingsMI {
	public:
		void Log();

		static MASH_int64t accNum;
		static MASH_f Amount;
	};
};