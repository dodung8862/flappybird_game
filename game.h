#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define INITIAL_SPEED 3
#include "graphics.h"

void render(const Sprite& bird, const Graphics& graphics);

void StartScreen(Graphics& graphics);

void RenderScore(Graphics& graphics, int score);

bool checkCollision(const SDL_Rect& a, const SDL_Rect& b);

void EndScreen(Graphics& graphics, int score);

void gameOver();


#endif // GAME_H_INCLUDED
