#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "Object.hpp"
#include "Bullet.hpp"
#include "consts.hpp"

class Enemy : public Object
{
public:
    void draw(Window *window){};
    virtual Bullet shoot();
    virtual bool does_shoot();
    virtual void update(Window *window){};

protected:
    int shoot_counter = 0;
};

#endif
