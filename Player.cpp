#include "Player.hpp"

void Player::draw(Window *window)
{
    window->draw_img(PLAYER_IMAGE, Rectangle(location, width, height));
}

Player::Player(Point starting_location)
{
    location.x = starting_location.x;
    location.y = starting_location.y;
    width = PLAYER_WIDTH;
    height = PLAYER_HEIGHT;
    speed_x = speed_y = 0;
    bullet_power = false;
    shield_power = false;
}

void Player::update(Window *window)
{
    int new_location_x = location.x + speed_x;
    int new_location_y = location.y + speed_y;
    if (new_location_x >= 0 && new_location_x + width <= window->get_width())
        location.x = new_location_x;
    if (new_location_y >= 0 && new_location_y + height <= window->get_height())
        location.y = new_location_y;
}

void Player::handle_key_press(char key)
{
    switch (key)
    {
    case UP_BUTTON1 | UP_BUTTON2:
        speed_y = PLAYER_SPEED_UP;
        break;
    case LEFT_BUTTON1 | LEFT_BUTTON2:
        speed_x = PLAYER_SPEED_LEFT;
        break;
    case DOWN_BUTTON1 | DOWN_BUTTON2:
        speed_y = PLAYER_SPEED_DOWN;
        break;
    case RIGHT_BUTTON1 | RIGHT_BUTTON2:
        speed_x = PLAYER_SPEED_RIGHT;
        break;
    }
}

void Player::handle_key_release(char key)
{
    if (key == UP_BUTTON1 || key == UP_BUTTON2 || key == DOWN_BUTTON1 || key == DOWN_BUTTON2)
        speed_y = 0;
    if (key == LEFT_BUTTON1 || key == LEFT_BUTTON2 || key == RIGHT_BUTTON1 || key == RIGHT_BUTTON2)
        speed_x = 0;
}

Bullet Player::shoot()
{
    Point starting_point = get_center();
    starting_point.x -= BULLET_WIDTH / 2;
    if (!bullet_power)
        return Bullet(starting_point, BULLET_UP);
    else
        return Bullet(starting_point, BULLET_UP * BULLET_INCREASE_RATE);
}

bool Player::get_shield()
{
    return shield_power;
}

bool Player::get_bullet_power(){
    return bullet_power;
}

void Player::set_bullet_power(bool mode)
{
    bullet_power = mode;
}
void Player::set_shield_power(bool mode)
{
    shield_power = mode;
}