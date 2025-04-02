#ifndef MUSIC_H
#define MUSIC_H

#include <SDL_mixer.h>
#include <string>

class Music {
    Mix_Music *gMusic;
public:
    Mix_Music *loadMusic(const char* path);
    void play(Mix_Music *gMusic);
};

class Sound {
    Mix_Chunk* gChunk;
public:
    Mix_Chunk* loadSound(const char* path);
    void play(Mix_Chunk* gChunk);
};


#endif // MUSIC_H
