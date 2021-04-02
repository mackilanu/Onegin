#include <iostream>
#include "Game.h"

int main() {
    Game game;

    if(!game.init()) {
        printf("Game could not be initialized!\n");
    } else {
        if(!game.loadMedia()) {
            printf("Media could not be loaded!\n");
        } else {
            bool quit = false;
            SDL_Event e;
            while(!quit) {
                while(SDL_PollEvent(&e) != 0) {
                    if(e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
                SDL_BlitSurface(game.helloWorld, NULL, game.screenSurface, NULL);
                SDL_UpdateWindowSurface(game.window);
            }
        }
    }
    game.close();
}
