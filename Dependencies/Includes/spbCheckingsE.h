#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <random>

#include "AppD.h"
#include "AppO.h"
#include "OtherE.h"
#include "spbCheckingsD.h"
#include "spbCheckingsTF.h"
#include "BanksE.h"
#include "TemporaryO.h"
#include "miBankE_O.h"

#include "BaseO.h"

#include "Universal/Universal.h"

class spbCheckingsE {
public:
	class RegCheckingsSPB : public BankO {
	public:
		void Create() override;
		void Withdrawal(MASH_f) override;
		void Deposit(MASH_f) override;
		MASH_f GetBankAmount() override;

		static MASH_b hasAccount;
		static MASH_f Amount;
		static MASH_int64t accNum;
		static MASH_b hasCard;
	};
};