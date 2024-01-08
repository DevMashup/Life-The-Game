#pragma once

#include "spbCheckingsE.h"
#include "spbSavingsD.h"
#include "spbSavingsTF.h"
#include "BaseO.h"

class spbSavingsE {
public:
	class RegSavingsSPB : public BankO {
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