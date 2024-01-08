#pragma once

#include "miJobsD_O.h"

class miPositionsD {
public:
	class Pilot {
	public:
		void CreateData();
	private:
		void AddMIData();
		void AddGlobalData();
	};
};