#include "closedoor.h"
#include <iostream>
#include "engine.h"
#include "entity.h"
#include "updatefov.h"

Result CloseDoor::perform(Engine& engine, std::shared_ptr<Entity> entity)
{
    Vec position = entity->get_position();
    bool closed_any_doors = false;
    for (Vec neighbor : engine.dungeon.neighbors(position))
    {
        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (tile.has_door() && tile.door->is_open())
        {
            //Tile has door and is open
            tile.door->close();
            tile.walkable = false;
            closed_any_doors = true;
        }
    }

    //Update FOV after closing door
    if (closed_any_doors)
    {

        engine.events.create_event<UpdateFOV>();
        return success();

    }
    return failure();
}
