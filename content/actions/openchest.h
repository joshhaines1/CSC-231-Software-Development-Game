#pragma once
#include "action.h"
#include "item.h"

class Chest;

class OpenChest : public Action {

public:
    explicit OpenChest(Item& chest);
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;
private:
    Item& chest;

};