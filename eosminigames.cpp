/**
 *  EOSMINIGAMES
 *  By Jonathan LEI (xJonathan@outlook.com)
 */

#include "eosminigames.hpp"

void eosminigames::hi()
{
    print("Hello eosminigames!");
}

void eosminigames::handleTransfer(account_name from, account_name to, extended_asset quantity, string memo)
{
    if (from == _self)
    {
        // A withdrawal
        print("Withdrawal of ", quantity, " to ", name{to}, " detected");
    }
    else if (to == _self)
    {
        // A deposit
        print("Deposit of ", quantity, " from ", name{from}, " detected");
    }
    else
        // Why is this message even pushed to me?
        return;
}