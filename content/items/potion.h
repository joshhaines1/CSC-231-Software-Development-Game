#pragma once
#include "item.h"

class Potion : public Item {

public:
    Potion(int healing_amount);
    void use(Engine& engine, Entity& owner) override;

private:
    int healing_amount;

};