#include "Object.hpp"

Point Object::get_location() { return location; }

Point Object::get_center()
{
    return {location.x + width / 2, location.y + height / 2};
}

void Object::update()
{
    location.x += speed_x;
    location.y += speed_y;
}

bool Object::does_hit(Object object)
{
    return (abs(get_center().x - object.get_center().x) < width / 2 + object.width / 2 &&
            abs(get_center().y - object.get_center().y) < height / 2 + object.height / 2);
}
