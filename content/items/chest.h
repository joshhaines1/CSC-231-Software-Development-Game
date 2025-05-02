#pragma once
#include "item.h"

class Chest : public Item {

public:
    Chest(std::shared_ptr<Item> item, Vec position, bool isFake = false);
    void interact(Engine& engine, Entity& entity) override;
    static void create_chest(Engine& engine, std::shared_ptr<Item> item, bool isFake = false);
    Vec position;
private:
    bool isFake;
    std::shared_ptr<Item> item;

};