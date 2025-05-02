#pragma once
#include "entity.h"
#include <memory>

namespace Monsters {

    //Generic monsters with different sprites
    void make_large_monster(std::shared_ptr<Entity> monster);
    void make_medium_monster(std::shared_ptr<Entity> monster);
    void make_small_monster(std::shared_ptr<Entity> monster);


    //Specific monsters
    void make_demon(std::shared_ptr<Entity> monster);
    void make_necromancer(std::shared_ptr<Entity> monster);
    void make_skeleton(std::shared_ptr<Entity> monster);
    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity);

}
