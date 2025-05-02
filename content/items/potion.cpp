//
// Created by Josh Haines on 4/14/25.
//
#include "potion.h"
#include "engine.h"
#include "entity.h"
#include "pickup.h"

Potion::Potion(int healing_amount)
    :Item{"potion_large_yellow"}, healing_amount{healing_amount}{
}

void Potion::use(Engine& engine, Entity& owner) {
    owner.take_damage(-healing_amount);
    owner.remove_item(owner.get_current_item().get());
}

void Potion::interact(Engine& engine, Entity& entity) {
    engine.events.create_event<PickUp>(entity);
}

