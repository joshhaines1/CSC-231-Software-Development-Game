#include "hit.h"
#include "staff_red.h"
#include "engine.h"
#include "entity.h"
#include "thrust.h"

RedStaff::RedStaff(int damage) :Item("staff_red"), damage{damage}{}

void RedStaff::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    auto thrust = engine.events.create_event<Thrust>(sprite, direction);
    thrust->add_next(Hit{defender, damage});
}

