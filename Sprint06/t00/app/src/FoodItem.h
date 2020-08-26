#pragma once

enum class FoodType {
    Invalid,
    ApplePie,
    HoneyNut,
    Sweetroll,
    PoisonedFood
};

class FoodItem {
public:
    virtual FoodType getType();
};

class ApplePie: public FoodItem {
public:
    FoodType getType() override;
};

class HoneyNut: public FoodItem {
public:
    FoodType getType() override;
};

class Sweetroll: public FoodItem {
public:
    FoodType getType() override;
};

class PoisonedFood: public FoodItem {
public:
    FoodType getType() override;
};