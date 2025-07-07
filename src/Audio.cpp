#include "Audio.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

bool Audio::Init() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        SDL_Log("SDL_mixer error: %s", Mix_GetError());
        return false;
    }
    return true;
}

Mix_Music* Audio::LoadMusic(const std::string& path) {
    Mix_Music* music = Mix_LoadMUS(path.c_str());
    if (!music) SDL_Log("Failed to load music %s: %s", path.c_str(), Mix_GetError());
    return music;
}

Mix_Chunk* Audio::LoadSound(const std::string& path) {
    Mix_Chunk* chunk = Mix_LoadWAV(path.c_str());
    if (!chunk) SDL_Log("Failed to load sound %s: %s", path.c_str(), Mix_GetError());
    return chunk;
}

void Audio::PlayMusic(Mix_Music* music, int loops) {
    if (music) Mix_PlayMusic(music, loops);
}

void Audio::PlaySound(Mix_Chunk* chunk) {
    if (chunk) Mix_PlayChannel(-1, chunk, 0);
}
