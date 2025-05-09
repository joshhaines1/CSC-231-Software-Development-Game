#include "dungeon.h"
#include "fov.h"
#include "randomness.h"
    
Dungeon::Dungeon(const Grid<Tile>& tiles, const std::vector<Room>& rooms,
                 const std::unordered_map<Vec, AnimatedSprite>& decorations)
    :tiles{tiles}, rooms{rooms}, decorations{decorations} {
    // all tiles are not visible when first created
    for (int y = 0; y < tiles.height; ++y) {
        for (int x = 0; x < tiles.width; ++x) {
            this->tiles(x, y).visible = false;
        }
    }
}


Vec Dungeon::random_open_room_tile() const {
    // Strategy: choose a room, then choose a random tile within it if
    // it's walkable and unoccupied
    while (true) {
        Room room = random_choice(rooms);
        int x = randint(room.position.x, room.position.x+room.size.x-1);
        int y = randint(room.position.y, room.position.y+room.size.y-1);
        const Tile& tile = tiles(x, y);
        if (tile.walkable && tile.entity == nullptr && tile.item == nullptr) {
            return {x, y};
        }
    }
}

Vec Dungeon::random_open_border_tile() const {

    while (true) {
        Room room = random_choice(rooms);
        int x = randint(room.position.x, room.position.x+room.size.x-1);
        int y = randint(room.position.y, room.position.y+room.size.y-1);
        const Tile& tile = tiles(x, y);
        int surroundingWalls = 0;
        bool has_door = false;
        std::vector<Tile> neighborTiles{
            tiles(x + 1, y), //Right
            tiles(x - 1, y), //Left
            tiles(x, y + 1), //Top
            tiles(x, y - 1), //Bottom
            tiles(x + 1, y + 1), //Up Right
            tiles(x - 1, y + 1), //Up Left
            tiles(x + 1, y - 1), //Bottom Right
            tiles(x - 1, y - 1), //Bottom Left

        };
        for (auto neighbor : neighborTiles) {
            if (neighbor.is_wall()) {

                surroundingWalls++;

            }
            if (neighbor.has_door()) {

                has_door = true; ;
                break;

            }
        }
        if (has_door) {

            continue;

        }
        if (tile.walkable && tile.entity == nullptr && tile.item == nullptr && surroundingWalls == 3) {
            return {x, y};
        }
    }
}

void Dungeon::update() {
    for (auto& [position, animated_sprite] : decorations) {
        if (tiles(position).visible) {
            animated_sprite.update();
        }
    }
}

void Dungeon::update_visibility(const Vec& position) {
    fog.update_visibility(*this, position);
}

void Dungeon::remove_entity(const Vec& position) {
    tiles(position).entity = nullptr;
}

Tile& Dungeon::get_tile(const Vec& position) {
    return tiles(position);
}

bool Dungeon::within_bounds(const Vec& position) const {
    return tiles.within_bounds(position);
}

std::vector<Vec> Dungeon::neighbors(const Vec& position) const {
    std::vector<Vec> neighbors;
    for (const auto& direction : Directions) {
        Vec neighbor = position + direction;
        if (tiles.within_bounds(neighbor)) {
            neighbors.push_back(neighbor);
        }
    }
    return neighbors;
}

bool Dungeon::is_opaque(const Vec& position) const {
    const Tile& tile = tiles(position);
    if (tile.is_wall()) {
        return true;
    }
    else if (tile.has_door()) {
        return !tile.door->is_open(); // closed door
    }
    else {
        return false;
    }
}

Path Dungeon::calculate_path(const Vec& start, const Vec& stop) const {
    return breadth_first(*this, start, stop);
}
