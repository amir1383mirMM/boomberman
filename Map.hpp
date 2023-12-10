#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

#include "Enemy.hpp"

using namespace sf;
using namespace std;

class MAP
{
private:
    vector<RectangleShape> grasses;
    vector<RectangleShape> wall_1s;
    vector<RectangleShape> wall_2s;
    vector<RectangleShape> powerups;

    vector<vector<char>> input;
    Texture *grass_texture;
    Texture *wall_1_texture;
    Texture *wall_2_texture;
    vector<Enemy*> enemys;


    


    // Private Functions
    void init_texture();

public:
    MAP();
    void read_inputs(string file_name);
    //void make_powerup();
    void make_wall_1(float cur_x, float cur_y, Texture *texture);
    void make_wall_2(float cur_x, float cur_y, Texture *texture);
    void make_grass(float cur_x, float cur_y, Texture *texture);
    void make_texture(char c, float &cur_x, float &cur_y);
    void make_map();

    vector<RectangleShape> &get_grass() { return this->grasses; }
    vector<RectangleShape> &get_wall_1s() { return this->wall_1s; }
	vector<RectangleShape> &get_wall_2s() { return this->wall_2s; }
	vector<RectangleShape> &get_powerups() { return this->powerups; }
    vector<Enemy *> &get_enemys();

    bool is_intersected(Sprite thing, RectangleShape shapes);
    bool did_it_hit(Sprite sprite, Person enemy);
    bool is_move_valid(Sprite sprite, vector<RectangleShape> *shapes); /////////////////////////

};
