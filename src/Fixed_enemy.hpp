#ifndef __FIXED_ENEMY__H__
#define __FIXED_ENEMY__H__
#include "Enemy.hpp"
#include "consts.hpp"

class Fixed_enemy : public Enemy
{
public:
    Fixed_enemy(Point starting_location);
    void draw(Window *window);
};

#endif