#include "move.h"
#include "engine.h"
#include "entity.h"
#include "opendoor.h"

Move::Move(Vec direction)
    :direction{direction}{

}


Result Move::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    entity->change_direction(direction);
    if (engine.dungeon.get_tile(entity->get_position() + direction).walkable)
    {
        entity->move_to(entity->get_position() + direction);
        return success();

    } else if (engine.dungeon.get_tile(entity->get_position() + direction).has_door() && !engine.dungeon.get_tile(entity->get_position() + direction).door->is_open())
    {
        return alternative(OpenDoor{});
    } else
    {
        return failure();
    }
}