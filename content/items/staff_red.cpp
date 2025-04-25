#include "hit.h"
#include "staff_red.h"
#include "engine.h"
#include "entity.h"
#include "raise.h"

RedStaff::RedStaff(int damage) :Item("staff_red"), damage{damage}{}

/*void RedStaff::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    auto raise = engine.events.create_event<Raise>(sprite, direction);
    raise->add_next<Hit>(defender, damage);
}*/

void RedStaff::use(Engine& engine, Entity& attacker, Entity&) {
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


        }

    }

}


