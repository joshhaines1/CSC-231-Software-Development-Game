//
// Created by Josh Haines on 4/23/25.
//

#include "thrust.h"
#include <map>

constexpr int delta = 3; //pixels to shift per frame
constexpr int duration = 3; //number of frames

const std::map<Vec, double> direction_to_angle = {
    {{0, 1}, 0},
    {{1, 0}, 90},
    {{0, -1}, 180},
    {{-1, 0}, 270}
};

Thrust::Thrust(Sprite& sprite, Vec direction)
    :Event(duration), sprite{sprite}, copy{sprite}, direction{direction}{
    sprite.angle = direction_to_angle.at(direction);
}

void Thrust::execute(Engine& engine) {
    sprite.shift += direction * delta;
}

void Thrust::when_done(Engine& engine) {
    sprite = copy;
}
