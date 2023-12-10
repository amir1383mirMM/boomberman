#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <sstream>
#include "Map.hpp"
#include "Player.hpp"

using namespace sf;

class Game
{
private:

    // somthing

    bool key_held;
    double passed_time = 0.0;
    Clock cooldownClock;
    bool isCooldown = false;
    const int cooldownDuration = 300; // milliseconds

    // Resources
    Texture *bg_texture;
    Sprite background;
    Font font;
    MAP game_map;
    Player player;
    vector<Text> texts;

    // Window
    RenderWindow *map_window = NULL;
    View view;
    Event event;
    void resize_view();

    // Initialise Functions
    void init_map_window();
    void init_map(string map_name);
    void init_player();
    void init_view();
    void init_texts();
    void init_font();

    void move_person(Person &person, float dir_x, float dir_y);
    
    void default_events();
    void default_enemys_movement();
   
    void player_hit_event();
    void player_collect_powerup();
    void player_hit_enemy();

    void update_texts();

    void end_game();
public:
    // Constructors

    Game(string map_name);
    Game();
    ~Game();

    // Accessors
    bool did_lose();
    bool did_win();


    // void close();
    void run_game();
    bool running();

    // Functions
    void update();
    void render();
    void poll_events();
};
