#include "Map.hpp"


const string WALL1 = "Images/wall_1.png";
const string WALL2 = "Images/wall_2.png";
const string GRASS = "Image/grass.png";



// delay time

float const height = 100;
float const widht = 100;
float const gap = height;

// Private Functions
void MAP::init_texture()
{
    grass_texture = new Texture;
    if (!grass_texture->loadFromFile(GRASS))
        cout << "ERROR: couldnt find game_map -> grass_texture" << endl;
    wall_1_texture = new Texture;
    if (!wall_1_texture->loadFromFile(WALL1))
        cout << "ERROR: couldnt find game_map -> wall_1_texture" << endl;
    wall_2_texture = new Texture;
    if (!wall_2_texture->loadFromFile(WALL2))
        cout << "ERROR: couldnt find game_map -> wall_2_texture" << endl;
 }

MAP::MAP()
{
    init_texture();
}



// Functions
void MAP::read_inputs(string file_name)
{
    vector<vector<char>> file_content;
    ifstream File(file_name);
    if (File.is_open())
    {
        std::string line;

        while (getline(File, line))
        {
            vector<char> chars(line.begin(), line.end());
            chars.push_back('\n');
            file_content.push_back(chars);
        }
        File.close();
    }
    else
        cout << "ERROR: game_map file_name didnt found" << endl;
    input = file_content;
}

/*
void MAP::make_poweup()
{

}
*/

void MAP::make_wall_1(float cur_x, float cur_y, Texture *texture)
{
    RectangleShape wall_1(Vector2f(100, 100));
    wall_1.setTexture(texture);
    wall_1.setPosition(cur_x, cur_y);
    wall_1s.push_back(wall_1);
}

void MAP::make_wall_2(float cur_x, float cur_y, Texture* texture)
{
    RectangleShape wall_2(Vector2f(100, 100));
    wall_2.setTexture(texture);
    wall_2.setPosition(cur_x, cur_y);
    wall_2s.push_back(wall_2);
}
void MAP::make_grass(float cur_x, float cur_y, Texture* texture)
{
    RectangleShape grass(Vector2f(100, 100));
    grass.setTexture(texture);
    grass.setPosition(cur_x, cur_y);
    grasses.push_back(grass);
}



void MAP::make_texture(char c, float &cur_x, float &cur_y)
{
    //powerup
    if (c == ' ')
    {
        make_grass(cur_x, cur_y, grass_texture);
    }
    if (c == 'B')
    {
        make_wall_1(cur_x, cur_y, wall_1_texture);
    }
    if (c == 'P')
    {
        make_wall_2(cur_x, cur_y, wall_2_texture);
    }
}

void MAP::make_map()
{
    float cur_y = 0.0;
    float cur_x;
    for (int i = 0; i < input.size(); i++)
    {
        cur_x = -widht;
        for (int j = 0; j < input[i].size(); j++)
        {
            make_texture(input[i][j], cur_x, cur_y);
        }
        cur_y += gap;
    }
}



bool MAP::is_intersected(Sprite sprite, RectangleShape shape)
{
    if (sprite.getGlobalBounds().intersects(shape.getGlobalBounds()))
    {
        return true;
    }
    return false;
}


bool MAP::did_it_hit(Sprite sprite, Person enemy)
{
    if (sprite.getGlobalBounds().intersects(enemy.get_sprite().getGlobalBounds()))
    {
        return true;
    }
    return false;
}

bool MAP::is_move_valid(Sprite sprite, vector<RectangleShape> *shapes)
{
    for (auto shape : *shapes)
    {
        if (is_intersected(sprite, shape))
        {
            return false;
        }
    }
    return true;
}


vector<Enemy *> &MAP::get_enemys()
{
    return enemys;
}




