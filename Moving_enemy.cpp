#include "Moving_enemy.hpp"

Moving_enemy::Moving_enemy(Point starting_location)
{
    location.x = starting_location.x;
    location.y = starting_location.y;
    width = MOVING_ENEMY_WIDTH;
    height = MOVING_ENEMY_HEIGHT;
    speed_y = 0;
    speed_x = MOVING_ENEMY_SPEED;
}

void Moving_enemy::draw(Window *window)
{
    window->draw_img(MOVING_IMAGE, Rectangle(location, width, height));
}

void Moving_enemy::update(Window *window)
{
    if (location.x + width >= window->get_width())
        speed_x = -MOVING_ENEMY_SPEED;
    if (location.x <= 0)
        speed_x = MOVING_ENEMY_SPEED;
    location.x += speed_x;
    location.y += speed_y;
}
