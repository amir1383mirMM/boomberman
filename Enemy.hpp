#pragma once

#include <cstdlib>
#include "Person.hpp"
#include <SFML/Graphics.hpp>


class Enemy : public Person
{
protected:
    Vector2f cur_dir; 

public:
    Vector2f get_cur_dir() { return cur_dir; }

    void move_left();
    void move_right();
    void move_down();
    void move_up();

    Enemy(string file_name, float enemy_speed_, string  vectorial);
    ~Enemy();
};
