#pragma once
#include "sprite.h"
#include "event.h"
#include "sprite.h"

class Swing : public Event {

public:
    Swing(Sprite& sprite, Vec direction);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    double starting_angle, delta;

};