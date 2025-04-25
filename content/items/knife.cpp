#include "hit.h"
#include "knife.h"
#include "engine.h"
#include "entity.h"
#include "thrust.h"

Knife::Knife(int damage) :Item("knife"), damage{damage}{}

void Knife::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    auto thrust = engine.events.create_event<Thrust>(sprite, direction);
    thrust->add_next<Hit>(defender, damage);
}

