#include "opendoor.h"
#include <iostream>
#include "engine.h"
#include "entity.h"
#include "updatefov.h"

Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity)
{
    Vec position = entity->get_position();
    bool opened_any_doors = false;
    for (Vec neighbor : engine.dungeon.neighbors(position))
    {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_door() && !tile.door->is_open())
        {
            //Tile has door and is closed
            tile.door->open();
            tile.walkable = true;
            opened_any_doors = true;
        }
    }

    //Update FOV after closing door
    if (opened_any_doors)
    {
        engine.events.create_event<UpdateFOV>();
        return success();
    }

    return failure();
}
