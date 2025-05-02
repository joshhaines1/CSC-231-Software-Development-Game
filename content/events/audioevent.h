#pragma once
#include "event.h"

class AudioEvent : public Event {
public:
    AudioEvent(std::string name);
    void execute(Engine& engine) override;

private:
    std::string name;

};