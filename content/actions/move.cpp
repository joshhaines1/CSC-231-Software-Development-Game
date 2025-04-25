#include "move.h"

#include <iostream>

#include "attack.h"
#include "engine.h"
#include "entity.h"
#include "opendoor.h"
#include "rest.h"

Move::Move(Vec direction)
    :direction{direction}{

}


Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    Tile& tile = engine.dungeon.get_tile(entity->get_position() + direction);
    if (tile.is_wall())
    {
        return failure();

    }
    if (tile.has_door() && !tile.door->is_open())
    {

        return alternative(OpenDoor{*tile.door});

    }
    if (tile.has_entity())
    {

        if (tile.entity->get_team() != entity->get_team())
        {
            std::cout << "Should attack";
            return alternative(Attack{*tile.entity});

        }

        return alternative(Rest{});

    }

    entity->move_to(entity->get_position() + direction);
    return success();

}