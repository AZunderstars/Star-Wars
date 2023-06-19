#ifndef __BULLET_H__
#define __BULLET_H__
#include "Object.hpp"
#include "consts.hpp"

class Bullet : public Object
{

public:
    void draw(Window *window);
    Bullet(Point starting_location, int speed);
    bool is_in_window(Window *window);
    int get_direction();
};

#endif
