//
// Created by Josh Haines on 4/14/25.
//
#include "potion.h"

#include "entity.h"

Potion::Potion(int healing_amount)
    :Item{"potion_large_yellow"}, healing_amount{healing_amount}{
}

void Potion::use(Engine& engine, Entity& owner) {
    owner.take_damage(healing_amount);
}

