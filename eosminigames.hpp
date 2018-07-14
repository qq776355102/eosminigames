/**
 *  EOSMINIGAMES
 *  By Jonathan LEI (xJonathan@outlook.com)
 */

#include <eosiolib/eosio.hpp>

#include "action_data.hpp"

using namespace eosio;

class eosminigames : public contract
{
  public:
    using contract::contract;

    /// @abi action
    void hi();

    void handleTransfer(account_name from, account_name to, extended_asset quantity, string memo);
};

extern "C"
{
    void apply(uint64_t receiver, uint64_t code, uint64_t action)
    {
        auto self = receiver;
        eosminigames thiscontract(self);
        if (code == self)
        {
            // Action is pushed directly to the contract
            switch (action)
            {
            case N(hi):
                execute_action(&thiscontract, &eosminigames::hi);
                break;
            }
        }
        else
        {
            // The contract is the recepient of the message
            if (action == N(transfer))
            {
                // Adds contract name to make it an extended asset

                auto transferData = unpack_action_data<transfer>();

                extended_asset contractMoney(transferData.quantity, code);

                thiscontract.handleTransfer(transferData.from, transferData.to, contractMoney, transferData.memo);
            }
        }
    }
}