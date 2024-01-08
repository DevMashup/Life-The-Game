#pragma once

#include <iostream>

#include "miCheckingsE.h"
#include "miSavingsD.h"
#include "miSavingsTF.h"
#include "BaseO.h"

#include "Universal/Universal.h"

class miSavingsE {
public:
	class RegSavingsMI : public BankO{
	public:
		void Create() override;
		void Withdrawal(MASH_f) override;
		void Deposit(MASH_f) override;
		MASH_f GetBankAmount() override;

		static MASH_b hasAccount;
		static MASH_f Amount;
		static MASH_int64t accNum;
		static MASH_b hasCard;
		static MASH_b hasCoupon;
	};
};