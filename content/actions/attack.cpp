//
// Created by Josh Haines on 4/16/25.
//

#include "attack.h"
#include "item.h"
#include "entity.h"
#include "rest.h"

Attack::Attack(Entity& defender)
    :defender{defender}{}


Result Attack::perform(Engine& engine, std::shared_ptr<Entity> attacker) {
    auto weapon = attacker->get_current_item();
    if (weapon) {

        weapon->use(engine, *attacker, defender);
        return success();

    } else {

        return alternative(Rest{});

    }
}

