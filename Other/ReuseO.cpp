#include "ReuseO.h"

MASH_vec<MASH_str> ReuseO::Split(MASH_str str, MASH_str delimiter)
{
    MASH_vec<MASH_str> v;
    if (!str.empty()) {
        int start = 0;
        do {
            // Find the index of occurrence
            int idx = str.find(delimiter, start);
            if (idx == MASH_str::npos) {
                break;
            }

            // If found add the substring till that
            // occurrence in the vector
            int length = idx - start;
            v.push_back(str.substr(start, length));
            start += (length + delimiter.size());
        } while (true);
        v.push_back(str.substr(start));
    }

    return v;
}

void ReuseO::RecreateBank()
{
    std::ifstream banksinput(BanksD::File);
    banksinput >> BanksD::Data;
    for (MASH_uint i = 0; i < BanksD::Data.size(); i++) {
        if (BanksD::Data[i].contains("Online")) {
            BanksD::Counter = i;
            auto globalElement = BanksD::Data[BanksD_O::Counter]["Online"];
            for (MASH_uint j = 0; j < globalElement.size(); j++) {
                if (globalElement[j].contains("Mashup Inc")) {
                    BanksD_O::Counter = j;
                    MASH_cout << BanksD_O::Counter;
                    auto localElem = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Mashup Inc"];
                    for (MASH_uint k = 0; k < localElem.size(); k++) {
                        if (localElem[k].contains("Checking")) {
                            miBankD_O::Counter = k;
                            miCheckingsE::RegCheckingsMI::accNum = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Checking"]["Regular"]
                                ["Account #"];
                            miCheckingsE::RegCheckingsMI::Amount = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Checking"]["Regular"]
                                ["Bank Amount"];
                            miCheckingsTF::RegCheckingsMI::accNum = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Checking"]["Regular"]
                                ["Account #"];
                            miCheckingsTF::RegCheckingsMI::Amount = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Checking"]["Regular"]
                                ["Bank Amount"];

                            miCheckingsE::RegCheckingsMI::hasAccount = true;
                        }
                        if (localElem[k].contains("Saving"))
                        {
                            miBankD_O::Counter = k;

                            miSavingsE::RegSavingsMI::accNum = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Saving"]["Regular"]
                                ["Account #"];
                            miSavingsE::RegSavingsMI::Amount = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Saving"]["Regular"]
                                ["Bank Amount"];
                            miSavingsTF::RegSavingsMI::accNum = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Saving"]["Regular"]
                                ["Account #"];
                            miSavingsTF::RegSavingsMI::Amount = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Mashup Inc"][miBankD_O::Counter]["Saving"]["Regular"]
                                ["Bank Amount"];

                            miSavingsE::RegSavingsMI::hasAccount = true;
                        }
                    }
                }
                if (globalElement[j].contains("Sally's Finances")) {
                    BanksD_O::Counter = j;
                    MASH_cout << "sf is located at " << BanksD_O::Counter;
                    auto localElem = BanksD::Data[BanksD::Counter]["Online"][BanksD_O::Counter]["Sally's Finances"];
                    for (MASH_uint k = 0; k < localElem.size(); k++) {
                        if (localElem[k].contains("Checking")) {
                            sfBankD_O::Counter = k;
                            sfCheckingsE::RegCheckingsSF::accNum = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Sally's Finances"][sfBankD_O::Counter]["Checking"]["Regular"]
                                ["Account #"];
                            sfCheckingsE::RegCheckingsSF::Amount = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Sally's Finances"][sfBankD_O::Counter]["Checking"]["Regular"]
                                ["Bank Amount"];
                            sfCheckingsTF::RegCheckingsSF::accNum = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Sally's Finances"][sfBankD_O::Counter]["Checking"]["Regular"]
                                ["Account #"];
                            sfCheckingsTF::RegCheckingsSF::Amount = BanksD::Data[BanksD::Counter]["Online"]
                                [BanksD_O::Counter]["Sally's Finances"][sfBankD_O::Counter]["Checking"]["Regular"]
                                ["Bank Amount"];

                            sfCheckingsE::RegCheckingsSF::hasAccount = true;
                        }
                    }
                }
            }
        }
    }
}
