//
// Created by Josh Haines on 4/29/25.
//

#include "drop.h"

#include "engine.h"
#include "entity.h"

Drop::Drop(){}

Result Drop::perform(Engine& engine, std::shared_ptr<Entity> entity) {

    if (!engine.dungeon.get_tile(entity->get_position()).has_item()) {

        if (entity->get_current_item().get()->sprite.shift.x > 0) {

            //Facing left?
            entity->get_current_item().get()->sprite.shift += {-5, 0};


        } else {

            //Facing right?
            entity->get_current_item().get()->sprite.shift += {5, 0};


        }
        entity->get_current_item().get()->sprite.angle = 0;
        engine.dungeon.get_tile(entity->get_position()).item = entity->get_current_item();
        entity->remove_item(entity->get_current_item().get());

    }
    return failure();
}

