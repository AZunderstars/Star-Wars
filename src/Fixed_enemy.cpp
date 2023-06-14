#include "Fixed_enemy.hpp"

Fixed_enemy::Fixed_enemy(Point starting_location)
{
    location.x = starting_location.x;
    location.y = starting_location.y;
    width = FIXED_ENEMY_WIDTH;
    height = FIXED_ENEMY_HEIGHT;
    speed_x = speed_y = 0;
}

void Fixed_enemy::draw(Window *window)
{
    window->draw_img(FIXED_IMAGE, Rectangle(location, width, height));
}
