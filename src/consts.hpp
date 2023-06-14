#ifndef __CONSTS_H__
#define __CONSTS_H__
#include <string>

const int WIDTH_SCALE = 150;
const int HEIGHT_SCALE = 150;
const int PLAYER_HEIGHT = 80;
const int PLAYER_WIDTH = 80;
const int HOSTAGE_WIDTH = 80;
const int HOSTAGE_HEIGHT = 80;
const int FIXED_ENEMY_WIDTH = 80;
const int FIXED_ENEMY_HEIGHT = 80;
const int MOVING_ENEMY_WIDTH = 80;
const int MOVING_ENEMY_HEIGHT = 80;
const int BULLET_WIDTH = 3;
const int BULLET_HEIGHT = 30;
const int POWER_WIDTH = 80;
const int POWER_HEIGHT = 80;
const int SHIELD_POWER_DURATION = 60;
const int BULLET_POWER_DURATION = 60;

const std::string PLAYER_IMAGE = "./assets/player.png";
const std::string MOVING_IMAGE = "./assets/moving.png";
const std::string FIXED_IMAGE = "./assets/fixed.png";
const std::string BACKGROUND_IMAGE = "./assets/background.jpg";
const std::string SHIELD_POWER_IMAGE = "./assets/shield_power.png";
const std::string BULLET_POWER_IMAGE = "./assets/bullet_power.png";
const std::string HOSTAGE_IMAGE = "./assets/hostage.png";
const std::string WON_IMAGE = "./assets/won.jpg";
const std::string LOST_IMAGE = "./assets/lost.jpg";
const std::string FAR_FAR_AWAY = "./assets/far_far_away.webp";
const std::string LOGO = "./assets/logo.png";
const std::string INTRO_MUSIC = "./assets/intro_music.mp3";

const int MOVING_ENEMY_CHAR = 'M';
const int FIXED_ENEMY_CHAR = 'F';
const int HOSTAGE_CHAR = 'H';

const int PLAYING = 1;
const int FINISHED_LEVEL = 0;
const int LOST = -1;
const int CLOSED = -2;
const int WON = 2;

const int BULLET_UP = -20;
const int BULLET_DOWN = 20;
const int BULLET_INCREASE_RATE = 2;

const int MOVING_ENEMY_SPEED = 15;
const int PLAYER_SPEED_UP = -15;
const int PLAYER_SPEED_DOWN = 15;
const int PLAYER_SPEED_RIGHT = 15;
const int PLAYER_SPEED_LEFT = -15;

const int SHOT_FREQUENCY = 15;
const int DELAY_TIME = 50;

const char SHOOT_BUTTON = ' ';
const char LEFT_BUTTON1 = 'A';
const char LEFT_BUTTON2 = 'a';
const char RIGHT_BUTTON1 = 'D';
const char RIGHT_BUTTON2 = 'd';
const char UP_BUTTON1 = 'W';
const char UP_BUTTON2 = 'w';
const char DOWN_BUTTON1 = 'S';
const char DOWN_BUTTON2 = 's';

const int BULLET_POWER_CHANCE_PER = 30;
const int SHIELD_POWER_CHANCE_PER = 25;
const int BULLET_POWER = 0;
const int SHIELD_POWER = 1;
const int UP = -1;
const int DOWN = 1;

#endif
