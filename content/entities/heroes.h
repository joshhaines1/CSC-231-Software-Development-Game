#pragma once
#include <memory>
#include "entity.h"
#include "action.h"

namespace Heroes {

	void make_wizard(std::shared_ptr<Entity> hero);
    std::unique_ptr<Action> default_behavior(Engine& engine, Entity& entity);

}
