#include "Enemy.hpp"

Bullet Enemy::shoot()
{
    Point starting_point = get_center();
    starting_point.x -= BULLET_WIDTH / 2;
    return Bullet(starting_point, BULLET_DOWN);
}

bool Enemy::does_shoot()
{
    shoot_counter++;
    return shoot_counter % SHOT_FREQUENCY == 0;
}
