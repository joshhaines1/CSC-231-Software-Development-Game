#include "monsters.h"
#include <randomness.h>

#include <iostream>

#include "bite.h"
#include "entity.h"
#include "item.h"
#include "rest.h"
#include "wander.h"
#include "engine.h"
#include "knife.h"
#include "move.h"
#include "staff_red.h"

namespace Monsters {

    void make_demon(std::shared_ptr<Entity> monster)
    {
        monster->set_sprite("demon_big");
        monster->set_max_health(6);
        monster->behavior = default_behavior;
        monster->add_to_inventory(std::make_shared<Bite>(3));



    }

    void make_necromancer(std::shared_ptr<Entity> monster)
    {
        monster->set_sprite("necromancer");
        monster->set_max_health(4);
        monster->behavior = default_behavior;
        if (probability(50)) {

            monster->add_to_inventory(std::make_shared<RedStaff>(2));

        } else {

            monster->add_to_inventory(std::make_shared<Bite>(1));

        }

    }

    void make_skeleton(std::shared_ptr<Entity> monster)
    {
        monster->set_sprite("skeleton");
        monster->set_max_health(2);
        monster->behavior = default_behavior;
        if (probability(50)) {

            monster->add_to_inventory(std::make_shared<Knife>(2));

        } else {

            monster->add_to_inventory(std::make_shared<Bite>(1));

        }

    }

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity)
    {
        if (entity.is_visible() && engine.hero) {

            std::vector<Vec> path = engine.dungeon.calculate_path(entity.get_position(), engine.hero->get_position());
            if (path.size() > 1) { // At least one tile away

                Vec direction = path.at(1) - path.at(0);
                return std::make_unique<Move>(direction);

            }

        }

        //Not visible
        if (probability(66))
        {

            return std::make_unique<Wander>();

        }
        return std::make_unique<Rest>();
    }

}
