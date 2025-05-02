//
// Created by Josh Haines on 4/29/25.
//

#include "changeteam.h"

#include "pickup.h"
#include "entity.h"

ChangeTeam::ChangeTeam(Entity& entity, bool backToOriginal)
    :entity{entity}, backToOriginal{backToOriginal}{}

void ChangeTeam::execute(Engine& engine) {
    if (backToOriginal) {

        entity.set_team(entity.get_original_team());
        entity.set_sprite(entity.original_sprite_name);

    } else {

        entity.set_team(Team::Monster);
        entity.set_sprite("necromancer");

    }

}

