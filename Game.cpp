#include "Game.hpp"

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int LIMIT_FPS = 144;
const Vector2f FIRST_PLACE = { 150.f, 150.f };
const Vector2f VIEW_SIZE = {400.f, 400.f};


// Initialise Functions
void Game::init_map_window()
{
    this->map_window = new RenderWindow(VideoMode(1200, 1200), "Game 1", Style::Close | Style::Titlebar | Style::Resize);
    this->map_window->setFramerateLimit(LIMIT_FPS);
}

void Game::init_map(string map_name)
{
    this->game_map.read_inputs(map_name);
    this->game_map.make_map();
}

void Game::init_player()
{
    this->player.to_pos(FIRST_PLACE);
}

void Game::move_person(Person &person, float dir_x, float dir_y)
{
    person.move(dir_x, dir_y);
    //get walls from map and if person hit the wall¡ stop person
}




void Game::default_events()
{
    default_enemys_movement();
}


void Game::default_enemys_movement()
{
    for (int i = 0; i < this->game_map.get_enemys().size(); i++)
    {
        Enemy *enemy = this->game_map.get_enemys()[i];

        enemy->move(enemy->get_cur_dir().x, enemy->get_cur_dir().y);

        if (enemy->get_cur_dir().x > 0)
        {
            enemy->move_right();
        }
        else
        {
            enemy->move_left();
        }
    }
}


void Game::player_hit_event()
{
    player_hit_enemy();
    player_collect_powerup();
}

//powerup
void Game::player_collect_powerup()
{
    vector<RectangleShape> &powerup = this->game_map.get_powerups();
    for (int i = 0; i < powerup.size(); i++)
	{
        if (this->game_map.is_intersected(this->player.get_sprite(), powerup[i]))
        {
            //do somthing for each powerup
            powerup.erase(powerup.begin() + i);
        }
    }
}


void Game::player_hit_enemy()
{
    vector<Enemy *> &enemys = this->game_map.get_enemys();

    for (int i = 0; i < enemys.size(); i++)
    {
        if (this->game_map.did_it_hit(this->player.get_sprite(), *enemys[i]))
        {
            this->player.reduse_health(1);
            this->player.to_pos(FIRST_PLACE);
        }
    }
}



// Functions
void Game::update()
{
    //set somthig like boobs , keys , powerup...
    this->poll_events();
    this->default_events();
    this->player_hit_event();
    this->update_texts();
    this->end_game();
}

void Game::render()
{
    this->map_window->clear();
    
    for (auto powerup : game_map.get_powerups())
        this->map_window->draw(powerup);

    this->map_window->draw(this->player.get_sprite());

    for (auto wall_1 : game_map.get_wall_1s())
        this->map_window->draw(wall_1);

    for (auto wall_2 : game_map.get_wall_2s())
        this->map_window->draw(wall_2);

    for (auto enemy : game_map.get_enemys())
        this->map_window->draw(enemy->get_sprite());


    for (auto i : this->texts)
        this->map_window->draw(i);

    this->map_window->display();
}

void Game::poll_events()
{
    while (this->map_window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case Event::Closed:
            this->map_window->close();
            break;
        case Event::KeyPressed:
            switch (this->event.key.code)
            {
            case Keyboard::Escape:
                this->map_window->close();
                break;
                       
            }
        }
    }

    // player movement
    if (Keyboard::isKeyPressed(Keyboard::A))
    {
        this->move_person(this->player, -1.f, 0.f);
        player.move_left();
    }
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        this->move_person(this->player, 1.f, 0.f);
        player.move_right();
    }
    if (Keyboard::isKeyPressed(Keyboard::S))
    {
        this->move_person(this->player, 0.f, -1.f);
        player.move_down();
    }
    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        this->move_person(this->player, 0.f, -1.f);
        player.move_up();
    }
    if (Keyboard::isKeyPressed(Keyboard::X))
    {
        //put boomb
    }

}

void Game::run_game()
{
    if (!this->map_window->isOpen())
    {
        this->map_window->create(VideoMode(1200, 1200), "Game 1", Style::Close | Style::Titlebar | Style::Resize);
        this->map_window->setFramerateLimit(LIMIT_FPS);
    }
}

// Accessors
bool Game::running()
{
    return this->map_window->isOpen();
}

// Constructor / destructor
Game::Game(string map_name)
{
    this->init_map(map_name);
    this->init_map_window();
    this->init_player();
    this->init_view();
    this->init_font();
    this->init_texts();
}

Game::Game()
{
}

Game::~Game()
{
    delete this->map_window;
}

bool Game::did_lose()
{
    if (this->player.is_alive())
        return false;
    return true;
    //or time was finished
}

bool Game::did_win()
{
    //if have tree key and intersect the door win the game
    return false;
}


void Game::init_texts()
{
    for (int i = 0; i < 3; i++)
    {
        Text temp;
        temp.setFont(this->font);
        temp.setFillColor(Color(0, 24, 89));
        temp.setStyle(Text::Style::Bold);
        texts.push_back(temp);
    }
}

void Game::init_font()
{
    if (!this->font.loadFromFile("Amatic - Bold.ttf"))
        cout << "ERROR: FAILED TO LOAD FONTS" << endl;
}


void Game::update_texts()
{
    //text for heath , key , time ...
}

void Game::end_game()
{
    if (this->did_lose() || this->did_win())
        this->map_window->close();
}
