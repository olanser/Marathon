#pragma once

#include "lockpicking.h"

class Container: public ILockable, public IOpenable {
public:
    Container(bool isLocked, const LockpickDifficulty difficulty);

    LockpickDifficulty lockDifficulty() const;
    bool isLocked() const;
    bool tryToOpen(LockpickDifficulty skill);

    virtual std::string name() const = 0;

private:
    bool m_isLocked{ false};
    LockpickDifficulty m_difficulty;
};

class Barrel: virtual public Container {
public:
    Barrel();
    Barrel(bool isLocked, const LockpickDifficulty difficulty);

    std::string name() const {
        return "Barrel";
    }
};

class Chest: public Container {
public:
    Chest();
    Chest(bool isLocked, const LockpickDifficulty difficulty);
    std::string name() const {
        return "Chest";
    }
};

class Safe: public Container {
public:
    Safe();
    Safe(bool isLocked, const LockpickDifficulty difficulty);
    std::string name() const {
        return "Safe";
    }
};