# Game for CSC-231
This code serves as the final project for CSC 231 Software
Development. It consists of a game engine that you will use to create
a game through a series of steps.

The engine written by WLC faculty is built on top of the fantastic
game library [SDL](https://www.libsdl.org/) to handle user input and
graphics. The engine provides features to implement a simple 2D
turn-based game, similar to a
[Roguelike](https://en.wikipedia.org/wiki/Roguelike) game.

The engine by itself does nothing, but by creating concrete types for
Heros, Monsters, Items, and Actions, you will be able to write a fun
game rather quickly. This repository contains the engine plus my
implementation of the game in `content`.


## The Game
You play a wizard exploring a randomly generated dungeon. Each level is
filled with monsters, loot lying on the ground, and chests (some of
which are traps). The game is turn-based: monsters act after you do.

### Controls
| Key | Action |
| --- | ------ |
| `W` / `Up` | Move up |
| `A` / `Left` | Move left |
| `S` / `Down` | Move down |
| `D` / `Right` | Move right |
| `R` | Switch to the next item in your inventory |
| `0`-`9` | Select the inventory item in that slot |
| `U` | Use the current item (potions) |
| `B` | Drop the current item on your tile |
| `C` | Close an adjacent open door |

Moving into a closed door opens it, moving into a monster attacks it with
your current item, and moving into a chest opens it. Walking onto an item
picks it up (if your inventory isn't full).

### The Hero
The wizard starts with 20 health and the following items:
a healing potion, a red staff, a knife, a shapeshift potion, and a
teleport potion.

### Items
| Item | Type | Effect |
| ---- | ---- | ------ |
| Knife | Weapon | Thrusts at the target for damage |
| Axe | Weapon | Swings at the target for damage |
| Red Staff | Weapon | Raises and strikes every adjacent enemy (all 8 directions) with lightning |
| Bite | Weapon | Used by monsters; deals damage with no visible weapon |
| Healing Potion | Consumable | Restores health |
| Shapeshift Potion | Consumable | Turns you into a monster for 10 turns so that monsters leave you alone. Attacking or opening a chest while shapeshifted returns you to normal |
| Teleport Potion | Consumable | Teleports you to a random open tile in a room |
| Chest | Container | Reveals the item inside when opened. Some chests are fake: they vanish and strike you with lightning for 3 damage |

### Monsters
Monsters come in three sizes, chosen randomly at spawn. Each size has
several sprites.

| Size | Health | Sprites | Weapons |
| ---- | ------ | ------- | ------- |
| Small | 1 | zombie, tiny demon, skeleton | Knife or bite |
| Medium | 3 | orc, masked orc, orc shaman, necromancer | Red staff or bite |
| Large | 5 | ogre, big demon, big zombie | Bite (2 damage) |

When a monster can see the hero it pathfinds toward them and attacks.
Otherwise it wanders or rests.

### Setup in `main.cpp`
At startup, `main.cpp` creates the hero, scatters 6 random items on the
ground, places 4 chests (the first is always fake), and spawns 20
monsters.


## Building
The game engine is written in C++ and uses features from the C++20
standard. [CMake](https://cmake.org/) is used to build all components.

CMake has been setup to automatically download SDL dependencies from
github. Opening this folder in CLion will configure and build the
project for you.

To configure it manually, type

```
mkdir -p build
cd build
cmake ..
```
then build it using
```
cmake --build .
```

Either method generates an executable in the build directory called
`game`. This executable expects to find `settings.txt` in its working
directory.

## Running
Unlike in MacOS or Linux, Windows may require that the SDL2 and
SDL2_image libraries files be in the same directory as the
executable. Copy the all `dll` files from `build/_deps/*-build`
folders into the `build` folder (folding containing `game`).

Make sure that you set your working directory to the same folder as
where `settings.txt` is. To run in manually in the terminal, do
`./build/game` on MacOS/Linux and `.\build\game.exe` on Windows.


# Folder structure
```
.
├── CMakeLists.txt   Top-level build file
├── main.cpp         Creates the hero, loot, chests, and monsters, then runs the engine
├── settings.txt     Game settings
├── notes.md         Personal notes on the engine API
├── assets/          Sprite sheet / sound descriptions
├── engine/          Provided engine (do not modify)
└── content/         My game code
    ├── actions/     Things an entity can do in a turn
    ├── entities/    Hero and monster setup and behavior
    ├── events/      Animations and effects that play out over frames
    └── items/       Weapons, potions, and chests
```

## Settings
`settings.txt` contains one `key value` pair per line:

| Setting | Meaning |
| ------- | ------- |
| `title` | Window title |
| `screen_width`, `screen_height` | Window resolution |
| `tile_size` | Size of a tile in pixels in the sprite sheet |
| `zoom` | Scale factor for drawing |
| `tiles`, `heroes`, `monsters`, `items`, `effects`, `sounds` | Paths to asset files |
| `map_width`, `map_height` | Dungeon size in tiles |
| `room_placement_attempts` | How many times the generator tries to place a room |

## Engine
The C++ code for the engine is located inside `engine`. **You
will not need to modify any code within the engine folder** and for
your sanity, please don't.  However, you will need to **read lots of
code within the engine** in order to know how to use it.

It includes the dungeon generator (rooms, doors, fog of war, field of
view, pathfinding), camera, audio, graphics, input, and the event queue.

## Content
Place all of your code within the folder `content`. CMake will handle
include paths to files within the engine, so you should be able to
just include the name of the file you wish to use, e.g. `#include
"engine.h"`, and it will just work.

The game is built from four concepts:

* **Actions** (`content/actions`) are what an entity does on its turn.
  Each overrides `Action::perform` and returns `success()`, `failure()`,
  or `alternative(...)` to try a different action instead (e.g. `Move`
  into a door becomes `OpenDoor`, and into a monster becomes `Attack`).
  Includes `Move`, `Attack`, `OpenDoor`, `CloseDoor`, `OpenChest`,
  `Use`, `Drop`, `Rest`, and `Wander`.
* **Entities** (`content/entities`) configure heroes and monsters:
  sprite, health, starting inventory, and a `behavior` function that
  picks the entity's next action (keyboard input for the hero, AI for
  monsters).
* **Items** (`content/items`) derive from `Item` and implement `use`
  and/or `interact`.
* **Events** (`content/events`) are queued effects that run over one or
  more frames and can be chained with `add_next<...>()`. Examples:
  `Swing`, `Thrust`, `Raise`, `Hit`, `Die`, `PickUp`, `Teleport`,
  `ChangeTeam`, `AnimationEvent`, `AudioEvent`, and `UpdateFOV`.

## Assets
The engine can load 2D graphical sprites from png images (called a
[spritesheet](https://en.wikipedia.org/wiki/Texture_atlas)) using a
simple asset file. The first line of the asset file must be the file
name of the png image.  The rest of the file can contain a list of
named sprites and their locations (x, y, width, height) within the
image file. Optionally, if a sprite is animated the number of frames
in the animation can appear after the location. It is assumed that
frames appear horizontally in the image and are equally-spaced. Here's
the format:

```
image_filename.png

name_of_sprite x y width height
animated_sprite x y width height frames
```

The asset files live in `assets/`: `tiles.txt`, `heroes.txt`,
`monsters.txt`, `items.txt`, `effects.txt`, and `sounds.txt`.

## Credits
The dungeon was designed by and can be purchased from
[SecretHideout](https://secrethideout.itch.io/rogue-dungeon-tileset-16x16).

The heros, monsters, weapons, and items were created by and can be
purchased from [Robert(0x72)](https://0x72.itch.io/dungeontileset-ii).
