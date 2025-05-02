#include "animationevent.h"

#include "engine.h"

AnimationEvent::AnimationEvent(Vec position, std::string name)
    :name{name}, position{position}{}

void AnimationEvent::execute(Engine& engine) {
    if (frame_count == 0) { // Initialization, only done once

        //Get the animation
        sprite = engine.graphics.get_animated_sprite(name);
        //Set the number of frames
        number_of_frames = sprite.number_of_frames();

    }

    engine.camera.add_overlay(position, sprite.get_sprite());
    sprite.update(); //go to next frame

}

