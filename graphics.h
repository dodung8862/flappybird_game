#ifndef GRAPHICS_H_INCLUDED
#define GRAPHICS_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "def.h"
#include "background.h"
#include "sprite.h"
#include "pipe.h"
#include <iostream>
#include <SDL_mixer.h>

bool inside(int x, int y, SDL_Rect r);

bool overlap(const SDL_Rect& r1, const SDL_Rect& r2);

struct Graphics {
    SDL_Renderer *renderer;
	SDL_Window *window;

	void logErrorAndExit(const char* msg, const char* error);

	void init();

	void prepareScene(bool clearScreen = true);

    void presentScene();

    SDL_Texture *loadTexture(const char *filename);

    void renderTexture(SDL_Texture *texture, int x, int y);

    void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);

    void quit();

    TTF_Font* loadFont(const char* path, int size);

    SDL_Texture* renderText(const char* text, TTF_Font* font, SDL_Color textColor);

    void render1(const ScrollingBackground& background);

    void render2(int x, int y, const Sprite& sprite) const;


};



#endif // GRAPHICS_H_INCLUDED
