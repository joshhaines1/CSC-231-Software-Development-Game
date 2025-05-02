//
// Created by Josh Haines on 4/14/25.
//
#include "teleport_potion.h"

#include "shapeshift_potion.h"

#include "animationevent.h"
#include "changeteam.h"
#include "engine.h"
#include "entity.h"
#include "pickup.h"
#include "teleport.h"

TeleportPotion::TeleportPotion()
    :Item{"potion_red"} {
}

void TeleportPotion::use(Engine& engine, Entity& owner) {

    auto animation = engine.events.create_event<AnimationEvent>(owner.get_position(), "magic");
    animation->add_next<Teleport>(owner);
    owner.remove_item(owner.get_current_item().get());
}

void TeleportPotion::interact(Engine& engine, Entity& entity) {
    engine.events.create_event<PickUp>(entity);
}

