#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "def.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <SDL_mixer.h>
#define CHEESE_SIZE 10
#define INITIAL_SPEED 3
#define MAX_PIPES 5

    void ScrollingBackground::setTexture(SDL_Texture* _texture) {
        texture = _texture;
        SDL_QueryTexture(texture, NULL, NULL, &width, &height);
    }

    void ScrollingBackground::scroll(int distance) {
        scrollingOffset -= distance;
        if( scrollingOffset < 0 ) { scrollingOffset = width; }
    }
