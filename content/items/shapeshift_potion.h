#pragma once
#include "item.h"

class ShapeshiftPotion : public Item {

public:
    ShapeshiftPotion();
    void use(Engine& engine, Entity& owner) override;
    void interact(Engine& engine, Entity& entity) override;

};