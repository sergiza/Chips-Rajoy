#pragma once
#include <SDL2/SDL_mixer.h>
#include <string>
#include <unordered_map>

class Audio {
public:
    static bool Init();

    static Mix_Music* LoadMusic(const std::string& path);
    static Mix_Chunk* LoadSound(const std::string& path);

    static void PlayMusic(Mix_Music* music, int loops = -1); // -1 = loop infinito
    static void PlaySound(Mix_Chunk* chunk);
};
