/**
 *  EOSMINIGAMES
 *  By Jonathan LEI (xJonathan@outlook.com)
 */

#pragma once

#include <eosiolib/eosio.hpp>
#include <eosiolib/asset.hpp>

using namespace eosio;
using std::string;

struct transfer
{
    account_name from;
    account_name to;
    asset quantity;
    string memo;
};