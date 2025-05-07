#include "move.h"
#include "animationevent.h"
#include "attack.h"
#include "changeteam.h"
#include "engine.h"
#include "entity.h"
#include "item.h"
#include "openchest.h"
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
        if (entity->get_team() != entity->get_original_team()) {

            engine.events.create_event<AnimationEvent>(entity->get_position(), "gas");
            entity->set_team(entity->get_original_team());

        }
        if (tile.entity->get_team() != entity->get_team())
        {
            return alternative(Attack{*tile.entity});

        }

        return alternative(Rest{});

    }
    if (tile.has_item() && tile.item->name == "chest")
    {
        if ((entity->get_team() == Team::Hero || entity->get_original_team() == Team::Hero)) {

            if (entity->get_team() != entity->get_original_team()) {

                auto animation = engine.events.create_event<AnimationEvent>(entity->get_position(), "gas");
                //Returns the entity to their original team
                animation->add_next<ChangeTeam>(*entity, true);

            }
            return alternative(OpenChest{*tile.item});

        } else {

            return alternative(Rest{});
        }

    }

    entity->move_to(entity->get_position() + direction);

    //Every time the user moves -> subtract one from turns left
    entity->turns_left_in_shapeshift--;

    if (entity->turns_left_in_shapeshift <= 0) {

        if (entity->get_team() != entity->get_original_team()) {
            auto animation = engine.events.create_event<AnimationEvent>(entity->get_position(), "gas");
            //Returns the entity to their original team
            animation->add_next<ChangeTeam>(*entity, true);

        }

    }
    if (tile.has_item() && (entity->get_team() == Team::Hero || entity->get_original_team() == Team::Hero)) {

        tile.item->interact(engine, *entity);

    }
    return success();

}