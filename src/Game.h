#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Sound.h"
#include "Fonts.h"
#include <SDL2/SDL.h>
#include <format>
#include <iostream>
#include <memory>

class Game {
    public:
        Game();
        ~Game();
        static constexpr int window_width{800};
        static constexpr int window_height{600};
        const std::string title;

        void init();
        void run();
        void load_media();

    private:
        Graphics graphics;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> icon;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> icon_Texture;

        Sound sound;
        std::unique_ptr<Mix_Chunk, decltype(&Mix_FreeChunk)> pkmn;
        std::unique_ptr<Mix_Music, decltype(&Mix_FreeMusic)> LA;

        SDL_Event event;
        const Uint8 *keystate;

        Fonts fonts;
};

#endif
