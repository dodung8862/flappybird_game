#define INITIAL_SPEED 3
#include "graphics.h"

void render(const Sprite& bird, const Graphics& graphics) {
    graphics.render2(bird.x, bird.y, bird);
}

void StartScreen(Graphics& graphics) {
    // Load text và nút cho màn hình Start
    SDL_Texture* backgroundTexture = graphics.loadTexture("background-day.png");
    TTF_Font* font = graphics.loadFont("04B_19.TTF", 120);

    SDL_Color white = {255, 255, 255};
    SDL_Color color = {0, 255, 0, 255};

    SDL_Texture* titleTexture = graphics.renderText("FlappyBird", font, color);

    SDL_Texture* startButtonTexture = graphics.renderText("START", font, white);
    SDL_Texture* startBirdTexture = graphics.loadTexture("sprite-sceen.png");

    SDL_Rect titleRect = {100, 200, 400, 100};
    SDL_Rect startButtonRect = {225, 555, 120, 40};
    SDL_Rect startBirdRect = {250, 380, 85, 60};

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) quit = true;

            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                if (x >= startButtonRect.x && x <= startButtonRect.x + startButtonRect.w &&
                    y >= startButtonRect.y && y <= startButtonRect.y + startButtonRect.h) {
                    std::cout << "Game Started!" << std::endl;
                    return;  // Thoát khỏi màn hình start và vào game
                }
            }
        }

        // Render màn hình Start
        SDL_RenderClear(graphics.renderer);
        SDL_RenderCopy(graphics.renderer, backgroundTexture, NULL, NULL);  // Render background
        SDL_RenderCopy(graphics.renderer, titleTexture, NULL, &titleRect);
        SDL_RenderCopy(graphics.renderer, startButtonTexture, NULL, &startButtonRect);
        SDL_RenderCopy(graphics.renderer, startBirdTexture, NULL, &startBirdRect);
        SDL_RenderPresent(graphics.renderer);  // Hiển thị frame đã render
    }

    // Cleanup
    SDL_DestroyTexture(titleTexture);
    SDL_DestroyTexture(startButtonTexture);
}


void RenderScore(Graphics& graphics, int score) {
    std::string scoreText = std::to_string(score);

    TTF_Font* font = graphics.loadFont("04B_19.TTF", 80);

    SDL_Color white = {255, 255, 255};

    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), white);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(graphics.renderer, scoreSurface);

    SDL_Rect scoreRect = {250, 160, 60, 60};

    // Copy texture điểm số lên màn hình
    SDL_RenderCopy(graphics.renderer, scoreTexture, NULL, &scoreRect);

    // Dọn dẹp SDL_Surface và Texture sau khi hiển thị
    SDL_FreeSurface(scoreSurface);
    SDL_DestroyTexture(scoreTexture);
}


void EndScreen(Graphics& graphics, int score){
    SDL_Texture* backgroundTexture = graphics.loadTexture("background-day.png");
    std::string scoreText = "Your Score: " + std::to_string(score);

    TTF_Font* font = graphics.loadFont("04B_19.TTF", 120);

    SDL_Color white = {255, 255, 255};
    SDL_Color color = {0, 255, 0, 255};
    SDL_Color orange = {255, 165, 0, 255};

    SDL_Texture* GameOverTexture = graphics.renderText("Game Over", font, orange);

    SDL_Texture* RestartButtonTexture = graphics.renderText("RESTART", font, white);
    SDL_Texture* EndBirdTexture = graphics.loadTexture("sprite-sceen.png");

    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText.c_str(), white);
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(graphics.renderer, scoreSurface);

    SDL_Rect GameOverRect = {100, 200, 400, 100};
    SDL_Rect RestartButtonRect = {220, 750, 160, 40};
    SDL_Rect EndBirdRect = {250, 380, 85, 60};
    SDL_Rect scoreRect = {100, 550, 400, 80};

    //SDL_SetRenderDrawColor(graphics.renderer, 0, 0, 0, 255);  // Màu nền đen
    SDL_RenderClear(graphics.renderer);
    SDL_RenderCopy(graphics.renderer, backgroundTexture, NULL, NULL);
    SDL_RenderCopy(graphics.renderer, GameOverTexture, NULL, &GameOverRect);
    SDL_RenderCopy(graphics.renderer, scoreTexture, NULL, &scoreRect);
    SDL_RenderCopy(graphics.renderer, RestartButtonTexture, NULL, &RestartButtonRect);
    SDL_RenderCopy(graphics.renderer, EndBirdTexture, NULL, &EndBirdRect);
    SDL_RenderPresent(graphics.renderer);

    // Đợi người chơi nhấn phím để Restart
    SDL_Event e;
    bool restart = false;
    while (!restart) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                exit(0);  // Thoát chương trình nếu đóng cửa sổ
            }
            if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE) {
                restart = true;  // Restart khi nhấn SPACEư
                StartScreen(graphics);
            }
        }
        SDL_Delay(100);  // Giảm tải CPU

    }

    // Giải phóng texture
    SDL_DestroyTexture(GameOverTexture);
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(RestartButtonTexture);
}


void gameOver() {
//    playSound("game_over.wav");   // Phát âm thanh Game Over
//    displayGameOverScreen();      // Hiển thị màn hình kết thúc
 //   restartGame();                // Reset game hoặc quay về màn hình chính
}


