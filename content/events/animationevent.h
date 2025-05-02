#pragma once
#include <animatedsprite.h>
#include <vec.h>

#include "event.h"

class AnimationEvent : public Event {

public:
    AnimationEvent(Vec position, std::string name);
    void execute(Engine& engine) override;

private:
    std::string name;
    Vec position;
    AnimatedSprite sprite;


};