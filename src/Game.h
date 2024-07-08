#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <format>
#include <iostream>
#include <memory>

class Game {
    public:
        Game();

        void init();
        void run();
        void load_media();

        static constexpr int width{800};
        static constexpr int height{600};

    private:
        void update_text();

        const std::string title;
        SDL_Event event;
        int font_size;
        SDL_Color font_color;
        std::string text_str;
        SDL_Rect text_rect;
        const int text_vel;
        int text_xvel;
        int text_yvel;

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> text_surf;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> text;
};

#endif
