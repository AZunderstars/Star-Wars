#include "Bullet.hpp"

void Bullet::draw(Window *window)
{
    window->fill_rect(Rectangle(location, width, height), RED);
}

Bullet::Bullet(Point starting_location, int speed)
{
    location.x = starting_location.x;
    location.y = starting_location.y;
    width = BULLET_WIDTH;
    height = BULLET_HEIGHT;
    speed_x = 0;
    speed_y = speed;
}

bool Bullet::is_in_window(Window *window)
{
    return location.y <= window->get_height() && location.y + height >= 0;
}

int Bullet::get_direction()
{
    if (speed_y < 0)
        return UP;
    else
        return DOWN;
}
