#pragma once
#include "event.h"
#include "item.h"

class PickUp : public Event {

public:
    PickUp(Entity& entity);
    void execute(Engine& engine) override;
private:
    Entity& entity;

};