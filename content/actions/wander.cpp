//
// Created by Josh Haines on 4/7/25.
//

#include "wander.h"
#include "vec.h"
#include "dungeon.h"
#include "engine.h"
#include "randomness.h"
#include "entity.h"
#include "move.h"
#include "rest.h"

Result Wander::perform(Engine& engine, std::shared_ptr<Entity> entity)
{
    Vec position = entity->get_position();
    std::vector<Vec> neighbors = engine.dungeon.neighbors(position);

    //Randomizes the direction of search
    shuffle(std::begin(neighbors), std::end(neighbors));

    //search for an open tile
    for (Vec neighbor : neighbors)
    {

        Tile& tile = engine.dungeon.get_tile(neighbor);
        if (!tile.is_wall() && !tile.has_entity())
        {

            Vec direction = neighbor - position;
            return alternative(Move{direction});

        }

    }

    return alternative(Rest{});
}

