#pragma once
#include "item.h"

class Knife : public Item {

public:
    Knife(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;

};