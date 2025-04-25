#include "bite.h"

#include "hit.h"
#include "staff_red.h"
#include "engine.h"

Bite::Bite(int damage) :Item("none"), damage{damage}{}

void Bite::use(Engine& engine, Entity& attacker, Entity& defender) {
    engine.events.create_event<Hit>(defender, damage);
}

