#pragma once

#include "Wolf.h"
#include "Human.h"

class Werewolf final : public Human, public Wolf {
public:
    Werewolf();
    ~Werewolf();
};