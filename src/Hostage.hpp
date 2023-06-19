#ifndef __HOSTAGE_H__
#define __HOSTAGE_H__
#include "Object.hpp"
#include "consts.hpp"

class Hostage : public Object
{
public:
    void draw(Window *window);
    Hostage(Point starting_location);
};

#endif
