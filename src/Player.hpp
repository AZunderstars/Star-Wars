#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Object.hpp"
#include "Bullet.hpp"
#include "consts.hpp"

class Player : public Object
{
private:
    bool bullet_power;
    bool shield_power;

public:
    bool get_shield();
    bool get_bullet_power();
    void set_bullet_power(bool mode);
    void set_shield_power(bool mode);
    void draw(Window *window);
    void handle_key_press(char key);
    void handle_key_release(char key);
    Player(Point starting_location);
    void update(Window *window);
    Bullet shoot();
    Player() = default;
};

#endif
