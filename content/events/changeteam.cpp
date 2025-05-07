//
// Created by Josh Haines on 4/29/25.
//

#include "changeteam.h"

#include "pickup.h"
#include "entity.h"

ChangeTeam::ChangeTeam(Entity& entity, bool backToOriginal)
    :entity{entity}, backToOriginal{backToOriginal}{}

void ChangeTeam::execute(Engine& engine) {

    //If you are returning to the original hero
    if (backToOriginal) {

        entity.set_team(entity.get_original_team());
        entity.set_sprite(entity.original_sprite_name);

    } else { //If you are changing into a monster

        entity.set_team(Team::Monster);
        entity.set_sprite("necromancer");

    }

}

