#include "engine.h"
#include "heroes.h"
#include "monsters.h"
#include <iostream>
#include "entity.h"
#include "randomness.h"
#include <random>

#include "axe.h"
#include "chest.h"
#include "knife.h"
#include "potion.h"
#include "shapeshift_potion.h"
#include "staff_red.h"

int main() {
    try {
        Settings settings{"settings.txt"};
        Engine engine{settings};
        std::shared_ptr<Entity> hero = engine.create_hero();
        Heroes::make_wizard(hero);

        //Spawns ground loot
        for (int i = 0; i < 6; i++) {

            if (probability(20)) {

                engine.create_item(std::make_shared<RedStaff>(3));

            } else if (probability(20)) {

                engine.create_item(std::make_shared<Knife>(2));

            } else if (probability(20)){

                engine.create_item(std::make_shared<Potion>(4));

            }  else if (probability(20)){

                engine.create_item(std::make_shared<ShapeshiftPotion>());

            } else {

                engine.create_item(std::make_shared<Axe>(3));

            }

        }

        //Spawns chests
        for (int i = 0; i < 4; i++) {
            if (i == 0) {

                //Spawns a fake chest
                Chest::create_chest(engine, std::make_shared<RedStaff>(3), true);
                continue;
            }
            if (probability(20)) {

                Chest::create_chest(engine, std::make_shared<RedStaff>(3));

            } else if (probability(20)) {

                Chest::create_chest(engine, std::make_shared<Knife>(1));


            } else if (probability(20)){

                Chest::create_chest(engine, std::make_shared<Potion>(4));


            }  else if (probability(20)){

                Chest::create_chest(engine, std::make_shared<ShapeshiftPotion>());


            } else {

                Chest::create_chest(engine, std::make_shared<Axe>(3));

            }

        }

        for (int i = 0; i < 20; i++)
        {
            std::shared_ptr<Entity> monster = engine.create_monster();
            if (probability(33)) {

                Monsters::make_medium_monster(monster);

            } else if (probability(33)){

                Monsters::make_large_monster(monster);

            } else {

                Monsters::make_small_monster(monster);

            }


        }


        engine.run();
    }
    catch (std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
