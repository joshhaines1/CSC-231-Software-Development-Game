#include "move.h"

#include <iostream>

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
    if (engine.dungeon.get_tile(entity->get_position() + direction).walkable || tile.has_door() && tile.door->is_open())
    {
        if (engine.dungeon.get_tile(entity->get_position() + direction).has_entity()) {

            return alternative(Rest());

        }
        entity->move_to(entity->get_position() + direction);
        return success();

    } else if (engine.dungeon.get_tile(entity->get_position() + direction).has_door() && !engine.dungeon.get_tile(entity->get_position() + direction).door->is_open())
    {
        return alternative(OpenDoor{*tile.door});
    } else {

        return failure();

    }
}