#ifndef __OBJECT_H__
#define __OBJECT_H__
#include "rsdl.hpp"

class Object
{
protected:
    Point location;
    int width, height;
    int speed_x, speed_y;
public:
    virtual void draw(Window *window){};
    virtual void update();
    virtual Point get_center();
    virtual bool does_hit(Object object);
    virtual Point get_location();
};

#endif