#pragma once
#include "event.h"
#include "item.h"

class ChangeTeam : public Event {

public:
    ChangeTeam(Entity& entity, bool backToOriginal);
    void execute(Engine& engine) override;
private:
    Entity& entity;
    bool backToOriginal;
};