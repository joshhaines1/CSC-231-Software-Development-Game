#pragma once
#include "action.h"
#include "../../engine/event.h"
#include "../../engine/item.h"

class Drop : public Action {

public:
    Drop();
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;;

};