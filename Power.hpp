#ifndef __POWERS_H__
#define __POWERS_H__
#include "Object.hpp"
#include "consts.hpp"

class Power : public Object
{
private:
    int mode;

public:
    int get_mode();
    Power(Point starting_location, int _mode);
    void draw(Window *window);
};

#endif