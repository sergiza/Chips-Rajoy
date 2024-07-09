#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Fonts.h"

#include "DVD.h"
#include "PlayerSprite.h"

#include <SDL2/SDL.h>
#include <format>
#include <iostream>
#include <memory>

class Game {
    public:
        Game();
        static constexpr int window_width{800};
        static constexpr int window_height{600};
        const std::string title;

        void init();
        void run();
        void load_media();

    private:
        Graphics graphics;
        Fonts fonts;

        SDL_Event event;
        DVD dvd;
        PlayerSprite playerSprite;

        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;

        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> DVDtext_Surface;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> DVDtext_Texture;

        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> icon;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> icon_Texture;
};

#endif
