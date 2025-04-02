#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "def.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "music.h"
#include <SDL_mixer.h>
#define CHEESE_SIZE 10
#define INITIAL_SPEED 3
#define MAX_PIPES 5

    void Pite::addPite() {
        for (int i = 0; i < 2; ++i) {  // Thêm 2 cặp cột
            int pipeY = 100 + rand() % (SCREEN_HEIGHT / 2);
            pipes.push_back({SCREEN_WIDTH + i * PIPE_SPACING, 800 - pipeY });
            scoredPipes.push_back(false);
        }
    }

    void Pite::updatePites() {
        for (auto& pipe : pipes) {
            pipe.first -= pipeSpeed;  // Di chuyển sang trái

            // Nếu cột ra khỏi màn hình, xóa nó
            if (pipe.first + PIPE_WIDTH < 0) {
                pipes.erase(pipes.begin());
                scoredPipes.erase(scoredPipes.begin());
            }
            while(pipes.size() < 2){
                addPite();
            }
        }
    }

    void Pite::renderPipes(SDL_Renderer* renderer, SDL_Texture* topPipeTexture, SDL_Texture* bottomPipeTexture) {

        for (const auto& pipe : pipes) {
            // Vẽ cột trên
            SDL_Rect topPipeRect = {pipe.first, 0, PIPE_WIDTH , pipe.second};
            SDL_RenderCopy(renderer, topPipeTexture, NULL, &topPipeRect);

            // Vẽ cột dưới
            SDL_Rect bottomPipeRect = {pipe.first, pipe.second+ GAP_HEIGHT, PIPE_WIDTH, 900 - (pipe.second + GAP_HEIGHT)};
            SDL_RenderCopy(renderer, bottomPipeTexture, NULL, &bottomPipeRect);
        }
    }

    bool Pite::inside(int x, int y, SDL_Rect r) {
        return x > r.x && x < r.x + r.w && y > r.y && y < r.y + r.h;
    }

    bool Pite::overlap(const SDL_Rect& r1, const SDL_Rect& r2) {
        return inside(r1.x, r1.y, r2) || inside(r1.x + r1.w, r1.y, r2) || inside(r1.x, r1.y+r1.h, r2) || inside(r1.x+r1.w, r1.y+r1.h, r2);
    }

    bool Pite::checkCollisionWithBird(SDL_Rect birdRect) {
        for (const auto& pipe : pipes) {
            SDL_Rect topPipeRect = {pipe.first, 0, PIPE_WIDTH , pipe.second};
            SDL_Rect bottomPipeRect = {pipe.first, pipe.second+ GAP_HEIGHT, PIPE_WIDTH, 900 - (pipe.second + GAP_HEIGHT)};

            // Sử dụng hàm overlap để kiểm tra va chạm
            if (overlap(birdRect, topPipeRect) || overlap(birdRect, bottomPipeRect) || birdRect.y <= 0 || birdRect.y + birdRect.h >= SCREEN_HEIGHT) {
                return true;  // Có va chạm
            }
        }
        return false;  // Không có va chạm
    }

    void Pite::updateScore(int birdX, int& score, Mix_Chunk *gJump, Sound& sound) {
        for (int i = 0; i < pipes.size(); ++i) {
            if (birdX > pipes[i].first + PIPE_WIDTH && !scoredPipes[i]) {
                score++;
                sound.play(gJump);
                scoredPipes[i] = true;  // Đánh dấu cột đã được cộng điểm
                std::cout << "Score: " << score << std::endl;
            }
        }
    }
