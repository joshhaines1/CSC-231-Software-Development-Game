//
// Created by Josh Haines on 4/30/25.
//
#include "engine.h"
#include "audioevent.h"

AudioEvent::AudioEvent(std::string name)
    :name{name}{

}

void AudioEvent::execute(Engine& engine) {
    engine.audio.play_sound(name);
}

