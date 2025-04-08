#include "monsters.h"

#include <randomness.h>

#include "entity.h"
#include "rest.h"
#include "wander.h"

namespace Monsters {

    void make_demon(std::shared_ptr<Entity> monster)
    {
        monster->set_sprite("demon_big");
        monster->set_max_health(40);
        monster->behavior = default_behavior;

    }

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity)
    {
        if (probability(66))
        {

            return std::make_unique<Wander>();

        }
        return std::make_unique<Rest>();
    }

}
