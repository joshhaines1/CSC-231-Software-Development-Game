#include "monsters.h"
#include <randomness.h>
#include "entity.h"
#include "item.h"
#include "rest.h"
#include "wander.h"
#include "engine.h"
#include "move.h"

namespace Monsters {

    void make_demon(std::shared_ptr<Entity> monster)
    {
        monster->set_sprite("demon_big");
        monster->set_max_health(40);
        monster->behavior = default_behavior;

    }

    void make_necromancer(std::shared_ptr<Entity> monster)
    {
        monster->set_sprite("necromancer");
        monster->set_max_health(25);
        monster->behavior = default_behavior;

    }

    void make_skeleton(std::shared_ptr<Entity> monster)
    {
        monster->set_sprite("skeleton");
        monster->set_max_health(30);
        monster->behavior = default_behavior;

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
