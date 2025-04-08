#pragma once
#include "action.h"
#include "entity.h"

class OpenDoor : public Action
{
public:
    Result perform(Engine& engine, std::shared_ptr<Entity> entity) override;

};