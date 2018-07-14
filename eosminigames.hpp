/**
 *  EOSMINIGAMES
 *  By Jonathan LEI (xJonathan@outlook.com)
 */

#include <eosiolib/eosio.hpp>

using namespace eosio;

class eosminigames : public contract
{
  public:
    using contract::contract;

    /// @abi action
    void hi();
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
    }
}