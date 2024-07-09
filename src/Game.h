#ifndef GAME_H
#define GAME_H

#include "Graphics.h"
#include "Fonts.h"

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

        void update_text();

        std::string text_str;
        SDL_Rect text_rect;
        const int text_vel;
        int text_xvel;
        int text_yvel;

        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> Surface_DVDtext;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> text;
};

#endif
