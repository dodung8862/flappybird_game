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

void Sprite::update(bool mouseClick){
        y += speed + 0.5 * G;  // Chim rơi xuống do trọng lực
        speed += 2.5 * G;             // Tăng tốc rơi dần

        if (mouseClick) {
            speed = SPEEDFLY;
        }
    }


    void Sprite::init(SDL_Texture* _texture, int frames, const int _clips [][4], int startX, int startY) {
        texture = _texture;
        SDL_Rect clip;
        for (int i = 0; i < frames; i++) {
            clip.x = _clips[i][0];
            clip.y = _clips[i][1];
            clip.w = _clips[i][2];
            clip.h = _clips[i][3];
            clips.push_back(clip);
        }
        this->x = startX;
        this->y = startY;
    }

    void Sprite::tick() {
        currentFrame = (currentFrame + 5) % clips.size();
    }
    const SDL_Rect* Sprite::getCurrentClip() const {
        return &(clips[currentFrame]);
    }

