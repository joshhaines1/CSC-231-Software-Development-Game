#pragma once
#include "entity.h"
#include <memory>

namespace Monsters {

    void make_demon(std::shared_ptr<Entity> monster);
    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity);

}
