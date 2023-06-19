#ifndef __MOVING_ENEMY__H__
#define __MOVING_ENEMY__H__
#include "Enemy.hpp"
#include "consts.hpp"

class Moving_enemy : public Enemy
{
public:
    Moving_enemy(Point starting_location);
    void draw(Window *window);
    void update(Window *window);
};

#endif
