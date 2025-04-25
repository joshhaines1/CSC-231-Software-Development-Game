#pragma once
#include "event.h"

class Entity;

class Hit : public Event {
public:
    Hit(Entity& entity, int damage);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    int damage;
    Entity& entity;
};