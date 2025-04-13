#include "heroes.h"

#include <iostream>
#include "action.h"
#include "entity.h"
#include <memory>
#include <rest.h>

#include "closedoor.h"
#include "engine.h"
#include "move.h"
#include "opendoor.h"

namespace Heroes {

    void make_wizard(std::shared_ptr<Entity> hero)
    {
        hero->set_sprite("wizard");
        hero->set_max_health(10);
        hero->behavior = default_behavior;
    }

    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity)
    {
        std::string key = engine.input.get_last_keypress();
        //if key == "right" then you Move ({1, 0})
        if (key == "A" || key == "Left")
        {
            return std::make_unique<Move>(Vec{-1, 0});
        } else if (key == "W" || key == "Up")
        {
            return std::make_unique<Move>(Vec{0, 1});

        } else if (key == "S" || key == "Down")
        {
            return std::make_unique<Move>(Vec{0, -1});

        }else if (key == "D" || key == "Right")
        {
            return std::make_unique<Move>(Vec{1, 0});

        } else if (key == "R")
        {
            return std::make_unique<Rest>();

        } else if (key == "C")
        {
            return std::make_unique<CloseDoor>();

        }
        return nullptr;
    }
    
}
