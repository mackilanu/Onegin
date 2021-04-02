#include "Game.h"

bool Game::init()
{
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        //Create the window
        window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(window == NULL) {
            printf("SDL could not create the window. SDL_Error: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);
        }
    }
    
    return success;
}

void Game::close()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("Game closed\n");
}


bool Game::loadMedia()
{
    bool success = true;
    const char *path = "assets/sm-sprite.bmp";
    helloWorld = SDL_LoadBMP(path);

    if(helloWorld == NULL) {
        printf("Could not load image %s! SDL Error: %s\n", path, SDL_GetError());
        success = false;
    }     
    return success;
}
