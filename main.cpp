#include "Game.hpp"

int main()
{
    Game* game = new Game;
    game->run_game();
    while (game->running())
    {
        // update
        game->update();

        // render
        game->render();

    

    return 0;
}