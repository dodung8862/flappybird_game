#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

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
#define MOUSE_SIZE 5
#define MAX_PIPES 5

    struct Sprite {
    SDL_Texture* texture;
    SDL_Rect rect;
    std::vector<SDL_Rect> clips;
    int x, y;
    int currentFrame = 0;
    double speed = INITIAL_SPEED;
    Sprite(int x, int y) {
        rect.x = x;
        rect.y = y;
        rect.h = 68;
        rect.w = 48;
    }

    void update(bool mouseClick);

    void init(SDL_Texture* _texture, int frames, const int _clips [][4], int startX, int startY);

    void tick();

    const SDL_Rect* getCurrentClip() const;
};


#endif // SPRITE_H_INCLUDED
