#pragma once
#include "item.h"

class Axe : public Item {

public:
    Axe(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;
    void interact(Engine& engine, Entity& entity) override;
private:
    int damage;

};