#pragma once

#include "Universal/Universal.h"

class BankO {
public:
    virtual void Create() = 0;
    virtual void Withdrawal(MASH_f Amount) = 0;
    virtual void Deposit(MASH_f Amount) = 0;
    virtual MASH_f GetBankAmount() = 0;
};