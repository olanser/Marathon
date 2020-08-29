#pragma once

#include <iostream>

struct Wallet {
    int septims;
};

Wallet* createWallet(int number);
void destroyWallet(Wallet* deleteWallet);
Wallet* createWallets(int count);
void destroyWallets(Wallet* deleteWallets);
