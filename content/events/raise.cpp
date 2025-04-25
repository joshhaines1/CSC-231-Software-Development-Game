//
// Created by Josh Haines on 4/23/25.
//

#include "raise.h"
#include <map>

constexpr int delta = 1; //pixels to shift per frame
constexpr int duration = 6; //number of frames

Raise::Raise(Sprite& sprite)
    :Event(duration), sprite{sprite}, copy{sprite}, direction{0, -1}{
    sprite.angle = 0;
}

void Raise::execute(Engine& engine) {
    sprite.shift += direction * delta;
    sprite.flip = !sprite.flip;

}

void Raise::when_done(Engine& engine) {
    sprite = copy;
}
