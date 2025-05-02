//
// Created by Josh Haines on 5/2/25.
//

#include "teleport.h"

#include "animationevent.h"
#include "engine.h"

Teleport::Teleport(Entity& entity)
    :entity{entity}{
}


void Teleport::execute(Engine& engine) {
    auto tile = engine.dungeon.random_open_border_tile();
    entity.move_to(tile);
    engine.events.create_event<AnimationEvent>(tile, "magic");
}

