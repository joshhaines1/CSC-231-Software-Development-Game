//
// Created by Josh Haines on 4/14/25.
//
#include "shapeshift_potion.h"

#include "animationevent.h"
#include "changeteam.h"
#include "engine.h"
#include "entity.h"
#include "pickup.h"

ShapeshiftPotion::ShapeshiftPotion()
    :Item{"potion_green"} {
}

void ShapeshiftPotion::use(Engine& engine, Entity& owner) {
    //Keeps track of the entity's original team
    owner.set_original_team(Team::Hero);

    /* Keeps track of how many moves the user has left
     * before it changes back */
    owner.turns_left_in_shapeshift = 5;

    //Remove the potion and trigger the animation
    auto animation = engine.events.create_event<AnimationEvent>(owner.get_position(), "gas");
    owner.remove_item(owner.get_current_item().get());

    //Changes team and sprite
    animation->add_next<ChangeTeam>(owner, false);

}

void ShapeshiftPotion::interact(Engine& engine, Entity& entity) {
    engine.events.create_event<PickUp>(entity);
}

