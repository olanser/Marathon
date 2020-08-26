#include "FoodItem.h"

FoodType FoodItem::getType() {
    return FoodType::Invalid;
};

FoodType ApplePie::getType() {
    return FoodType::ApplePie;
};

FoodType HoneyNut::getType() {
    return FoodType::HoneyNut;
};


FoodType Sweetroll::getType() {
    return FoodType::Sweetroll;
};

FoodType PoisonedFood::getType() {
    return FoodType::PoisonedFood;
};
