#include "heroes.h"

#include <iostream>
#include "action.h"
#include "entity.h"
#include <memory>
#include <rest.h>

#include "attack.h"
#include "closedoor.h"
#include "drop.h"
#include "engine.h"
#include "move.h"
#include "potion.h"
#include "opendoor.h"
#include "staff_red.h"
#include "use.h"
#include "knife.h"
#include "shapeshift_potion.h"
#include "teleport_potion.h"

namespace Heroes {

    void make_wizard(std::shared_ptr<Entity> hero) {
        hero->set_sprite("wizard");
        hero->original_sprite_name = "wizard";
        hero->set_max_health(20);
        hero->behavior = default_behavior;
        hero->add_to_inventory(std::make_shared<Potion>(5));
        hero->add_to_inventory(std::make_shared<RedStaff>(4));
        hero->add_to_inventory(std::make_shared<Knife>(2));
        hero->add_to_inventory(std::make_shared<ShapeshiftPotion>());
        hero->add_to_inventory(std::make_shared<TeleportPotion>());
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
            entity.switch_to_next_item();

        } else if (key == "C")
        {
            return std::make_unique<CloseDoor>();

        } else if (key == "U")
        {
            return std::make_unique<Use>();

        } else if (key == "B") {

            return std::make_unique<Drop>();

        } else if (!key.empty() && std::isdigit(key[0])) { //Gets the number pressed

            int index = std::stoi(key);
            entity.select_item(index);

        }
        return nullptr;
    }
    
}
