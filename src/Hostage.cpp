#include "Hostage.hpp"

void Hostage::draw(Window *window)
{
    window->draw_img(HOSTAGE_IMAGE, Rectangle(location, width, height));
}

Hostage::Hostage(Point starting_location)
{
    location.x = starting_location.x;
    location.y = starting_location.y;
    width = HOSTAGE_WIDTH;
    height = HOSTAGE_HEIGHT;
    speed_x = speed_y = 0;
}