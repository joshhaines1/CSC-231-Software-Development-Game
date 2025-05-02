#pragma once
#include "item.h"

class Knife : public Item {

public:
    Knife(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;
    void interact(Engine& engine, Entity& entity) override;
private:
    int damage;

};