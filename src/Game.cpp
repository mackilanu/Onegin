#include "Game.h"

bool Game::init()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(window == NULL) {
            printf("SDL could not create the window. SDL_Error: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xff, 0xff, 0xff));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(4000);
        }
    }
    
    return success;
}

void Game::close()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}


bool Game::loadMedia()
{}
