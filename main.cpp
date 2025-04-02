#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "def.h"
#include "graphics.h"
#include "game.h"
#include "background.h"
#include "pipe.h"
#include "sprite.h"
#include "music.h"
#include <ctime>
using namespace std;

using namespace std;

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));
    Graphics graphics;
    graphics.init();

    StartScreen(graphics);

    Music music;
    Mix_Music *gMusic = music.loadMusic("RunningAway.mp3");
    music.play(gMusic);

    Sound sound;
    Mix_Chunk *gJump = sound.loadSound("jump.wav");
    Mix_Chunk *gLost = sound.loadSound("lost.wav");

    int score = 0;

    ScrollingBackground background;
    background.setTexture(graphics.loadTexture("background-day.png"));

    Sprite bird(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    bird.x = SCREEN_WIDTH / 2;
    bird.y = SCREEN_HEIGHT / 2;


    SDL_Texture* birdTexture = graphics.loadTexture(BIRD_SPRITE_FILE);
    bird.init(birdTexture, BIRD_FRAMES, BIRD_CLIPS, 150, SCREEN_HEIGHT / 3);

    Pite pite(100, 100);

    SDL_Texture* topPipeTexture = graphics.loadTexture("pipe-bottom1.png");
    SDL_Texture* bottomPipeTexture = graphics.loadTexture("pipe-top1.png");


    SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255); // Màu nền đen

    SDL_RenderPresent(graphics.renderer);

    pite.addPite();

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        bool mouseClick = false;
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                mouseClick = true;  // Nhấn chuột
            }
        }

        background.scroll(1);

        bird.update(mouseClick);

        SDL_Rect birdRect = {bird.x, bird.y, 55, 48};

        if (pite.checkCollisionWithBird(birdRect)) {
            std::cout << "Game Over! Bird hit a pipe." << std::endl;
            sound.play(gLost);
            quit = true;  // Kết thúc game nếu xảy ra va chạm
        }

        pite.updatePites();

        pite.updateScore(bird.x, score, gJump, sound);

        bird.tick();

        SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255);
        SDL_RenderClear(graphics.renderer);  // Xóa màn hình trước khi render frame mới

        graphics.prepareScene();


        graphics.render1(background);

        pite.renderPipes(graphics.renderer, topPipeTexture, bottomPipeTexture);

        render(bird, graphics);

        RenderScore(graphics, score);

        graphics.presentScene();

        SDL_Delay(40);
    }
    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    if (gJump != nullptr) Mix_FreeChunk( gJump);

    EndScreen(graphics,score);

    waitUntilKeyPressed();
    SDL_DestroyTexture( background.texture );

	SDL_DestroyTexture( birdTexture ); birdTexture = nullptr;


    graphics.quit();
    return 0;
}

