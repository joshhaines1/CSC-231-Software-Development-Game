//
// Created by Josh Haines on 4/16/25.
//

#include "die.h"

#include "engine.h"
Die::Die(Entity& entity) :entity{entity}{}

void Die::execute(Engine& engine) {
    //audio event or animation
    engine.remove_entity(entity);
}


