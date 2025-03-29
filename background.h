#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

struct ScrollingBackground {
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;

    void setTexture(SDL_Texture* _texture);
    void scroll(int distance);
};

#endif // BACKGROUND_H_INCLUDED
