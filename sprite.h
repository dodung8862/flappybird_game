#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "def.h"
#include <vector>
#define INITIAL_SPEED 3

    struct Sprite {
    SDL_Texture* texture;
    SDL_Rect rect;
    std::vector<SDL_Rect> clips;
    int x, y;
    int currentFrame = 0;
    double speed = INITIAL_SPEED;

    void update(bool mouseClick);

    void init(SDL_Texture* _texture, int frames, const int _clips [][4], int startX, int startY);

    void tick();

    const SDL_Rect* getCurrentClip() const;
};


#endif // SPRITE_H_INCLUDED
