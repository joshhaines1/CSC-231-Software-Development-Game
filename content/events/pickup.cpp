//
// Created by Josh Haines on 4/29/25.
//

#include "pickup.h"

#include "engine.h"
#include "entity.h"

PickUp::PickUp(Entity& entity)
    :entity{entity}{}

void PickUp::execute(Engine& engine) {
    if (!entity.is_inventory_full()) {

        entity.add_to_inventory(engine.dungeon.get_tile(entity.get_position()).item);
        engine.dungeon.get_tile(entity.get_position()).item = nullptr;

    }
}

