//
// Created by Josh Haines on 4/16/25.
//

#include "hit.h"

#include <iostream>

#include "die.h"
#include "engine.h"
#include "entity.h"

Hit::Hit(Entity& entity, int damage)
    :entity{entity}, damage{damage}{}

void Hit::execute(Engine& engine) {
    //Add an audio sound effect
    entity.take_damage(damage);
}

void Hit::when_done(Engine& engine) {
    if (!entity.is_alive()) {

        add_next<Die>(entity);

    }
}

