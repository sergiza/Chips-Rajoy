#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include <format>
#include <memory>

class Sound {
    public:
        Sound();
        Mix_Chunk* load_sound(const std::string& file_path);
        Mix_Music* load_music(const std::string& file_path);

    private:
};

#endif
