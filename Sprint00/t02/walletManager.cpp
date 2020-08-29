#include "walletManager.h"

Wallet* createWallet(int number) {
    Wallet* newWallet = new (std::nothrow) Wallet;

    newWallet->septims = number;
    return newWallet;
}

void destroyWallet(Wallet* deleteWallet) {
    delete deleteWallet;
}

Wallet* createWallets(int count) {
    Wallet* newWallets = new (std::nothrow) Wallet[count];

    return newWallets;
}

void destroyWallets(Wallet* deleteWallets) {
    delete [] deleteWallets;
}
