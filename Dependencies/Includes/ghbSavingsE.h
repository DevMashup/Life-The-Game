#pragma once

#include "ghbCheckingsE.h"
#include "ghbSavingsD.h"
#include "ghbSavingsTF.h"

#include "BaseO.h"

class ghbSavingsE {
public:
	class RegSavingsGHB : public BankO{
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