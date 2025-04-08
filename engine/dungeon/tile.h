#pragma once

#include "sprite.h"
#include <memory>

// forward declaration
class Entity;
class Door;
class Item;

class Tile {
public:
    Tile();
    [[nodiscard]] bool is_wall() const;
    [[nodiscard]] bool has_door() const;
    [[nodiscard]] bool has_item() const;
    [[nodiscard]] bool has_entity() const;
    [[nodiscard]] bool is_visible() const;
    
    enum class Type { None, Floor, Wall, Door };
    
    Type type;
    Sprite sprite;
    bool visible;
    bool walkable;

    std::shared_ptr<Door> door;
    std::shared_ptr<Item> item;
    Entity* entity;
};
