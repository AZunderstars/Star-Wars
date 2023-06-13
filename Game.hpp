#ifndef __GAME_H__
#define __GAME_H__
#include "rsdl.hpp"
#include <vector>
#include "Player.hpp"
#include "Bullet.hpp"
#include "Power.hpp"
#include "Fixed_enemy.hpp"
#include "Moving_enemy.hpp"
#include "Hostage.hpp"
#include "consts.hpp"
#include <fstream>
#include <random>

class Game
{
private:
    Window *window;
    std::vector<Bullet> bullets;
    Player player;
    std::vector<Enemy *> enemies;
    std::vector<Hostage> hostages;
    int levels_number, game_state;
    int window_rows, window_cols;
    std::vector<Power> powers;
    int shield_power_counter = 0, bullet_power_counter = 0;

public:
    void run(std::ifstream& map);
    void play_level();
    void initialize(std::ifstream& map);
    void handle_events();
    void update();
    void draw();
    Game();
    void check_bullets();
    void add_bullet(Bullet bullet);
    void check_spaceships_crash();
    void check_hostages_hit(Bullet bullet);
    bool check_enemies_hit(Bullet bullet);
    void check_powers();
    void load_map(std::ifstream &map);
    void add_cell(char cell, int row, int col);
    void add_powers(Point location);
    void show_result(int result);
    void clear_game();
    void update_powers();
    void intro();
};

#endif