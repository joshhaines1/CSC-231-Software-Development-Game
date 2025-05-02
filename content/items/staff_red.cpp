#include "hit.h"
#include "staff_red.h"

#include "animationevent.h"
#include "audioevent.h"
#include "engine.h"
#include "entity.h"
#include "pickup.h"
#include "raise.h"
#include "swing.h"

RedStaff::RedStaff(int damage) :Item("staff_red"), damage{damage}{}

void RedStaff::use(Engine& engine, Entity& attacker, Entity& defender) {
    auto raise = engine.events.create_event<Raise>(sprite);
    std::vector<Vec> directions = {

        {0, 1}, //Up
        {1, 1}, // Up Right
        {1, 0}, // Right
        {1, -1}, // Down Right
        {0, -1}, // Down
        {-1, -1}, // Down left
        {-1, 0},  // Left
        {-1, 1} // Up Left

    };
    for (int i = 0; i < directions.size(); i++) {

        auto tile = engine.dungeon.get_tile(attacker.get_position() + directions[i]);
        if (tile.has_entity() && tile.entity->get_team() != attacker.get_team()) {
            //If a member of the other team is on a surrounding tile, attack it
            raise->add_next<Hit>(*tile.entity, damage);
            raise->add_next<AnimationEvent>(attacker.get_position() + directions[i], "lightning");
            raise->add_next<AudioEvent>("thunder");

        }

    }

}

void RedStaff::interact(Engine& engine, Entity& entity) {
    engine.events.create_event<PickUp>(entity);
}


