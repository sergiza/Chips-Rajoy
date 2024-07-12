#include "Sound.h"

Sound::Sound() {}


    Mix_Chunk* Sound::load_sound(const std::string& file_path) {
        Mix_Chunk* sound = Mix_LoadWAV(file_path.c_str());
        if (!sound) {
            throw std::runtime_error(std::format("Error loading Chunk: {}", Mix_GetError()));
        }
        return sound;
    }

    Mix_Music* Sound::load_music(const std::string& file_path) {
        Mix_Music* music = Mix_LoadMUS(file_path.c_str());
        if (!music) {
            throw std::runtime_error(std::format("Error loading Music: {}", Mix_GetError()));
        }
        return music;
    }
