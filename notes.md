# CSC 231 Game Notes
## Action Class
The class to override to take a turn in the game:
```c++
class Action {
public:
    virtual ~Action() = default;

    // override perform in a derived class
    virtual Result perform(Engine& engine, std::shared_ptr<Entity> entity) = 0;
};
```
My code goes in the 'content' folder. DO NOT EDIT THE ENGINE FOLDER

**Always return from Action**
```c++
return success();
return failure();
return alternative(OpenDoor{});
```

**Entity Moving Member Functions:**
```c++
class Entity {
public:
    Vec get_position() const;
    void move_to(Vec position);
    void change_direction(Vec direction);
}
```
-------------
### How to Use Markdown
*italic*

**bold**
```c++
class A {
public: 
    A();
 };
```
