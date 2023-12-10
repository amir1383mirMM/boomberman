#pragma once

#include "Person.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>

using namespace sf;
using namespace std;


class Player : public Person
{
private:
   //loat DELAY_TIME = 0;
  //int score = 0;

    // Private Functions
    vector <Texture> textures;
public:

    // Accessors
    Player();

    void init_textures();
    void move_left();
    void move_right();
    void move_up();
    void move_down();
    //Jump animation goes here
};

