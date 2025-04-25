#pragma once
#include "sprite.h"
#include "event.h"

class Thrust : public Event {

public:
    Thrust(Sprite& sprite, Vec direction);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    Vec direction;

};