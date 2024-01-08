#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "miCheckingsE.h"
#include "miSavingsE.h"
#include "sfCheckingsE.h"
#include "miCheckingsTF.h"
#include "miSavingsTF.h"
#include "sfCheckingsTF.h"


#include "Universal/Universal.h"

class ReuseO {
public:
    MASH_vec<MASH_str> Split(MASH_str str, MASH_str delimiter);
    void RecreateBank();
};