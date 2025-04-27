#include "opendoor.h"
#include <iostream>
#include "engine.h"
#include "entity.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Door& door)
    :door{door}{

}



Result OpenDoor::perform(Engine& engine, std::shared_ptr<Entity> entity)
{
    door.open();
    engine.events.create_event<UpdateFOV>();
    return success();
}
