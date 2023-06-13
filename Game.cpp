#include "Game.hpp"
using namespace std;

Game::Game() {}

void Game::run(ifstream &map)
{
    for (int i = 0; i < levels_number; i++)
    {
        game_state = PLAYING;
        clear_game();
        load_map(map);
        player = Player(Point(rand() % window_rows * WIDTH_SCALE, (window_cols - 1) * HEIGHT_SCALE));
        play_level();
        if (game_state == CLOSED || game_state == LOST)
            break;
    }
    window->stop_music();
    if (game_state == FINISHED_LEVEL)
        game_state = WON;
    show_result(game_state);
}

void Game::initialize(ifstream &map)
{
    srand(time(0));
    map >> window_rows >> window_cols;
    window = new Window(window_rows * WIDTH_SCALE, window_cols * HEIGHT_SCALE);
    map >> levels_number;
}

void Game::play_level()
{
    while (game_state == PLAYING)
    {
        handle_events();
        update();
        draw();
        delay(DELAY_TIME);
    }
}

void Game::handle_events()
{
    while (window->has_pending_event())
    {
        Event event = window->poll_for_event();
        switch (event.get_type())
        {
        case Event::EventType::QUIT:
            game_state = CLOSED;
            break;
        case Event::EventType::KEY_PRESS:
            player.handle_key_press(event.get_pressed_key());
            if (event.get_pressed_key() == SHOOT_BUTTON)
                add_bullet(player.shoot());
            break;
        case Event::EventType::KEY_RELEASE:
            player.handle_key_release(event.get_pressed_key());
            break;
        }
    }
}

void Game::update()
{
    player.update(window);
    for (int i = 0; i < enemies.size(); i++)
    {
        if (enemies[i]->does_shoot())
            add_bullet(enemies[i]->shoot());
        enemies[i]->update(window);
    }
    for (int i = 0; i < bullets.size(); i++)
        bullets[i].update();
    check_bullets();
    check_spaceships_crash();
    if (enemies.size() == 0)
        game_state = FINISHED_LEVEL;
    update_powers();
}

void Game::draw()
{
    window->clear();
    window->draw_img(BACKGROUND_IMAGE);
    for (int i = 0; i < hostages.size(); i++)
        hostages[i].draw(window);
    for (int i = 0; i < bullets.size(); i++)
        bullets[i].draw(window);
    player.draw(window);
    for (int i = 0; i < enemies.size(); i++)
        enemies[i]->draw(window);
    for (int i = 0; i < powers.size(); i++)
        powers[i].draw(window);
    window->update_screen();
}

void Game::add_bullet(Bullet bullet)
{
    bullets.push_back(bullet);
}

void Game::check_bullets()
{
    for (int i = 0; i < bullets.size(); i++)
    {
        if (!player.get_shield() && bullets[i].does_hit(player) && bullets[i].get_direction() == DOWN)
            game_state = LOST;
        check_hostages_hit(bullets[i]);
        if (check_enemies_hit(bullets[i]) || !bullets[i].is_in_window(window))
            bullets.erase(bullets.begin() + i);
    }
}

void Game::check_spaceships_crash()
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (player.does_hit(*enemies[i]))
            game_state = LOST;
    }
    for (int i = 0; i < hostages.size(); i++)
    {
        if (player.does_hit(hostages[i]))
            game_state = LOST;
    }
}

void Game::check_hostages_hit(Bullet bullet)
{
    for (int i = 0; i < hostages.size(); i++)
    {
        if (bullet.does_hit(hostages[i]) && bullet.get_direction() == UP)
            game_state = LOST;
    }
}

void Game::check_powers()
{
    for (int i = 0; i < powers.size(); i++)
    {
        if (player.does_hit(powers[i]))
        {
            if (powers[i].get_mode() == BULLET_POWER)
                player.set_bullet_power(true);
            if (powers[i].get_mode() == SHIELD_POWER)
                player.set_shield_power(true);
            powers.erase(powers.begin() + i);
        }
    }
}

bool Game::check_enemies_hit(Bullet bullet)
{
    for (int i = 0; i < enemies.size(); i++)
    {
        if (bullet.does_hit(*enemies[i]) && bullet.get_direction() == UP)
        {
            add_powers(enemies[i]->get_location());
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
            return true;
        }
    }
    return false;
}

void Game::load_map(ifstream &map)
{
    for (int col = 0; col < window_cols; col++)
    {
        for (int row = 0; row < window_rows; row++)
        {
            char cell;
            map >> cell;
            add_cell(cell, row, col);
        }
    }
}

void Game::add_cell(char cell, int row, int col)
{
    Point location = Point(row * WIDTH_SCALE, col * HEIGHT_SCALE);
    if (cell == MOVING_ENEMY_CHAR)
        enemies.push_back(new Moving_enemy(location));
    if (cell == FIXED_ENEMY_CHAR)
        enemies.push_back(new Fixed_enemy(location));
    if (cell == HOSTAGE_CHAR)
        hostages.push_back(Hostage(location));
}

void Game::add_powers(Point location)
{
    if (rand() % 100 < BULLET_POWER_CHANCE_PER)
        powers.push_back(Power(location, BULLET_POWER));
    else if (rand() % 100 < SHIELD_POWER_CHANCE_PER)
        powers.push_back(Power(location, SHIELD_POWER));
}

void Game::show_result(int result)
{
    if (result == WON)
        window->draw_img(WON_IMAGE);
    else if (result == LOST)
        window->draw_img(LOST_IMAGE);
    else
        return;
    window->update_screen();
    while (true)
    {
        if (window->poll_for_event().get_type() == Event::QUIT)
            break;
    }
}

void Game::clear_game()
{
    bullets.clear();
    hostages.clear();
    powers.clear();
}

void Game::update_powers()
{
    check_powers();
    if (player.get_shield())
        shield_power_counter++;
    if (shield_power_counter % SHIELD_POWER_DURATION == 0)
        player.set_shield_power(false);
    if (player.get_bullet_power())
        bullet_power_counter++;
    if (bullet_power_counter % BULLET_POWER_DURATION == 0)
        player.set_bullet_power(false);
}

void Game::intro()
{
    window->draw_img(FAR_FAR_AWAY);
    window->update_screen();
    window->play_music(INTRO_MUSIC);
    delay(2000);
    window->draw_img(LOGO);
    window->update_screen();
    delay(5000);
}