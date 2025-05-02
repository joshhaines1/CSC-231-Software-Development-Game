#include "hit.h"
#include "axe.h"
#include "engine.h"
#include "entity.h"
#include "pickup.h"
#include "swing.h"
#include "thrust.h"

Axe::Axe(int damage) :Item("axe"), damage{damage}{}

void Axe::use(Engine& engine, Entity& attacker, Entity& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    auto swing = engine.events.create_event<Swing>(sprite, direction);
    swing->add_next<Hit>(defender, damage);
}

void Axe::interact(Engine& engine, Entity& entity) {
    engine.events.create_event<PickUp>(entity);
}


