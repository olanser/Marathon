#include "castSpells.h"

int castFloatToInt(float number) {
    int castInt = static_cast<int>(number);

    return castInt; 
}

int* castToNonConstIntPtr(const int* ptr) {
    int* castIntPtr = const_cast<int*>(ptr);

    return castIntPtr;
}
