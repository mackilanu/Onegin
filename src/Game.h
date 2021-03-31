#include <SDL2/SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game {
    public:
        SDL_Window *window;
        SDL_Surface *screenSurface;
        SDL_Surface *helloWorld;
        bool init();
        bool loadMedia();
        void close();
};
