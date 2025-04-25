//
// Created by Josh Haines on 4/23/25.
//

#include "swing.h"
#include <map>
#include <cmath>

constexpr int duration = 5; //number of frames


Swing::Swing(Sprite& sprite, Vec direction)
    :Event(duration), sprite{sprite}, copy{sprite}, starting_angle{sprite.angle}{
    // for each direction, set starting_angle and delta (change in angle)
    if (direction == Vec{1, 0}) {

        starting_angle = 0;
        delta = 135.0 / (duration - 1);

    } else if (direction == Vec{-1, 0}) {

        starting_angle = 0;
        delta = -135.0 / (duration - 1);

    } else if (direction == Vec{0, 1}) {

        sprite.shift.y -= 12;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = -75 * sign;
        delta = 135.0 / (duration - 1) * sign;

    } else {
        sprite.shift.x = 0;
        double sign = std::copysign(1.0, starting_angle);
        starting_angle = 135 * sign;
        delta = 90.0 / (duration - 1) * sign;

    }
}

void Swing::execute(Engine& engine) {
    sprite.angle = starting_angle + delta * frame_count;
}

void Swing::when_done(Engine& engine) {
    sprite = copy;
}
