//
// Created by Josh Haines on 4/30/25.
//

#include "openchest.h"

#include "attack.h"
#include "engine.h"
#include "entity.h"
#include "item.h"


OpenChest::OpenChest(Item& chest)
    :chest{chest}{
}

Result OpenChest::perform(Engine& engine, std::shared_ptr<Entity> entity) {

    chest.interact(engine, *entity);
    return success();
}

