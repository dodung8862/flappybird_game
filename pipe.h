#ifndef PIPE_H_INCLUDED
#define PIPE_H_INCLUDED
using namespace std;
#include "music.h"
struct Pite {
    int x; // vị trí
    int y;
    bool poin;
    SDL_Texture* topPipeTexture;
    SDL_Texture* bottomPipeTexture;
    SDL_Rect topPipeRect;
    SDL_Rect bottomPipeRect;
    SDL_Rect rect;
    Pite(int x, int y) {
        rect.x = x;
        rect.y = y;
        rect.h = 104;
        rect.w = 10;

    }

    std::vector<std::pair<int, int>> pipes;
    std::vector<bool> scoredPipes;

    void addPite();

    void updatePites();

    void renderPipes(SDL_Renderer* renderer, SDL_Texture* topPipeTexture, SDL_Texture* bottomPipeTexture);

    bool inside(int x, int y, SDL_Rect r);

    bool overlap(const SDL_Rect& r1, const SDL_Rect& r2) ;

    bool checkCollisionWithBird(SDL_Rect birdRect);    // Hàm xử lý va chạm

    void updateScore(int birdX, int& score, Mix_Chunk *gJump, Sound& sound);    // Hàm cộng điểm
};


#endif // PIPE_H_INCLUDED
