#pragma once
#include "item.h"

class RedStaff : public Item {

public:
    RedStaff(int damage);
    void use(Engine& engine, Entity& attacker, Entity& defender) override;

private:
    int damage;

};