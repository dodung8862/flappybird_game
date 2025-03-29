#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED
#define MUSIC_THEME_PATH "./flappy_assets/Running Away - John Charles Fiddy.mp3"
#define SOUND_JUMP "./flappy_assets/jump.wav"
#define SOUND_LOST "./flappy_assets/lost.wav"

    const int SCREEN_WIDTH = 288 * 2;
    const int SCREEN_HEIGHT = 512 * 2;
    constexpr const char* WINDOW_TITLE = "Hello World!";

    constexpr const char* BIRD_SPRITE_FILE = "sprite.png";

    const int BIRD_CLIPS[][4] = {
    {0, 0, 68, 48},    // Frame đầu tiên
    {112, 0, 68, 48}
};
    const float G = 0.5;
    const float SPEEDFLY = -8;
    const int BIRD_FRAMES = sizeof(BIRD_CLIPS)/sizeof(int)/4;

    const int pipeWidth = 80;       // Chiều rộng cột
    const int gapHeight = 150;      // Khoảng cách giữa 2 cột
    const int pipeSpeed = 5;        // Tốc độ di chuyển

    const int PIPE_WIDTH = 78;               // Chiều rộng cột
    const int GAP_HEIGHT = 100;              // Khoảng cách giữa cột trên và dưới
    const int PIPE_SPACING = 300;            // Khoảng cách giữa các cặp cột theo trục X



#endif // DEF_H_INCLUDED
