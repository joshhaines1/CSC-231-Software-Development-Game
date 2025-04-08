#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>
#include "entity.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_wizard(hero);
        for (int i = 0; i < 40; i++)
        {

            std::shared_ptr<Entity> monster = engine.create_monster();
            Monsters::make_demon(monster);

        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
