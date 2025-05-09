#pragma once
#include "item.h"

class RedStaff : public Item {

public:
    RedStaff(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;
    void interact(Engine& engine, Entity& entity) override;
private:
    int damage;

};