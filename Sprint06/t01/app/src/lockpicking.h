#pragma once 

#include <iostream>
#include <string>

enum class LockpickDifficulty {
    None = 0,
    Novice = 25,
    Apprentice = 40,
    Adept = 60,
    Expert = 80,
    Master = 100
};


class IOpenable {
    virtual bool tryToOpen(LockpickDifficulty skill) = 0;
};

class ILockable {
    virtual LockpickDifficulty lockDifficulty() const = 0;
    virtual bool isLocked() const = 0;
};