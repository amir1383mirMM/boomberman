#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace sf;
using namespace std;



class Person
{
protected:
    Sprite sprite;
    Texture *texture;
    int health;
    float person_speed;

    // Private Functions
    void init_texture(string file_name);
    void init_sprite();

public:
    // Accessors
    void move(float dir_x, float dir_y);
    void reduse_health(int number) { this->health -= number; }
    bool is_alive() { return (this->health > 0); }
    void close() { delete texture; }

    int get_health() { return this->health; }
    Sprite get_sprite() { return this->sprite; };
    Vector2f get_position() { return this->sprite.getPosition(); }
    void to_pos(Vector2f pos);

    // Constructors
    Person(string file_name, float person_speed_);
};
