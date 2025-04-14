//
// Created by Josh Haines on 4/14/25.
//

#include "use.h"
#include "entity.h"
#include "item.h"

Result Use::perform(Engine& engine, std::shared_ptr<Entity> entity) {
    auto item = entity->get_current_item();
    if (item) {
        item->use(engine, *entity);
        entity->remove_item(item.get());
        return success();
    } else {

        return failure();

    }
}
