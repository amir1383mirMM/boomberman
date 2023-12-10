#include "Player.hpp"

const String PLAYER_TEXTURE = "down.png";
const float PLAYER_SPEED = 0;
const int HEALTH = 3;

const float FRAMESIZE = 0.4;


// Private Functions

// Accessors

// Constructors

Player::Player()
    : Person(PLAYER_TEXTURE, PLAYER_SPEED)
{
    this->health = HEALTH;
    init_textures();
}

void Player::init_textures()
{
    for (int i = 0; i < 3; i++)
    {

    }
    Texture tmp1;
    tmp1.loadFromFile("left.png");
    textures.push_back(tmp1);
    Texture tmp2;
    tmp2.loadFromFile("right.png");
    textures.push_back(tmp2);
    Texture tmp3;
    tmp3.loadFromFile("down.png");
    textures.push_back(tmp3);
    Texture tmp4;
    tmp4.loadFromFile("up.png");
    textures.push_back(tmp4);

}


void Player::move_left()
{
       sprite.setScale(FRAMESIZE, FRAMESIZE);
       sprite.setTexture(texture[0]);
}

void Player::move_right()
{
       sprite.setScale(FRAMESIZE, FRAMESIZE);
       sprite.setTexture(texture[1]);
       
}
void Player::move_down()
{
    sprite.setScale(FRAMESIZE, FRAMESIZE);
    sprite.setTexture(texture[2]);
}
void Player::move_up()
{
    sprite.setScale(FRAMESIZE, FRAMESIZE);
    sprite.setTexture(texture[3]);
}

