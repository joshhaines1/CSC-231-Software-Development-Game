#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>
#include "entity.h"
#include "randomness.h"
#include <random>

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};

        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_wizard(hero);
        for (int i = 0; i < 40; i++)
        {
            std::shared_ptr<Entity> monster = engine.create_monster();
            int random_number = (std::rand() % (100 - 0 + 1)) + 0;
            if (random_number <= 33) {

                Monsters::make_necromancer(monster);

            } else if (random_number <= 66){

                Monsters::make_demon(monster);

            } else {

                Monsters::make_skeleton(monster);

            }


        }

        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
