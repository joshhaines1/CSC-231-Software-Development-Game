#include "hit.h"
#include "chest.h"
#include "animationevent.h"
#include "engine.h"
#include "entity.h"
#include "pickup.h"

Chest::Chest(std::shared_ptr<Item> item, Vec position, bool isFake)
    :Item("chest"), position{position},isFake{isFake}, item{item} {}


void Chest::interact(Engine& engine, Entity& entity) {
    if (!isFake) { // If it's a real chest

        //Open chest animation
        auto animation = engine.events.create_event<AnimationEvent>(position, "chest");
        engine.audio.play_sound("door-open");

        //Change the item on the tile from the chest to the item in the chest
        item->sprite = engine.graphics.get_sprite(item->name);
        engine.dungeon.get_tile(position).item = item;

    } else { // If it's a fake chest

        //Open chest animation
        auto animation = engine.events.create_event<AnimationEvent>(position, "fake-chest");

        //Change the item on the tile from a chest to nothing
        engine.dungeon.get_tile(position).item = nullptr;

        //Damage the player
        animation->add_next<AnimationEvent>(entity.get_position(), "lightning");
        engine.audio.play_sound("thunder");
        animation->add_next<Hit>(entity, 3);

    }

}

void Chest::create_chest(Engine& engine, std::shared_ptr<Item> item, bool isFake) {
    //Gets a random tile that is up against a wall
    Vec position = engine.dungeon.random_open_border_tile();

    //Creates a chest and places it on the tile
    auto chest = std::make_shared<Chest>(item, position, isFake);
    Tile& tile = engine.dungeon.get_tile(chest->position);
    tile.item = chest;

    //Add the sprite to the tile
    auto sprite = engine.graphics.get_animated_sprite(chest->name, 1);
    chest->sprite = sprite.get_sprite();
}

