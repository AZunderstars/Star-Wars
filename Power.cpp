#include "Power.hpp"

int Power::get_mode()
{
    return mode;
}

Power::Power(Point starting_location, int _mode)
{
    location.x = starting_location.x;
    location.y = starting_location.y;
    width = POWER_WIDTH;
    height = POWER_HEIGHT;
    speed_x = speed_y = 0;
    mode = _mode;
}

void Power::draw(Window *window)
{
    if (mode == BULLET_POWER)
        window->draw_img(BULLET_POWER_IMAGE, Rectangle(location, width, height));
    if (mode == SHIELD_POWER)
        window->draw_img(SHIELD_POWER_IMAGE, Rectangle(location, width, height));
}