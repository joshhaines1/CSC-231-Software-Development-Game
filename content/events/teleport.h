#pragma once
#include "entity.h"
#include "event.h"

class Teleport : public Event {

public:
    Teleport(Entity& entity);
    void execute(Engine& engine) override;
private:
    Entity& entity;
};