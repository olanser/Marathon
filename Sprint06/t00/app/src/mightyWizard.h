#pragma once

#include <iostream>
#include "FoodItem.h"

class AbstractWizard
{
public:
    AbstractWizard() = default;
    virtual ~AbstractWizard() = default;

    virtual FoodType deductFoodType(FoodItem &food) = 0;
};

class MightyWizard final : public AbstractWizard {
public:
    MightyWizard(std::string names);
    FoodType deductFoodType(FoodItem &food) override;
    void checkFood(std::nullptr_t nu);
    void checkFood(FoodItem &food);
    void checkFood(FoodItem*& food);
private:
    std::string name;
};
