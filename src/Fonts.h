#ifndef FONTS_H
#define FONTS_H

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <memory>
#include <string>
#include <format>

class Fonts {
    public:
        Fonts();

        int font_size;
        SDL_Color font_color;
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font;
        const std::string ttf_default = "rsrc/fonts/freesansbold.ttf";

        void init();
        TTF_Font* load_font(const std::string& file_path, int font_size);
        SDL_Surface* render_font(const std::string& text_string);

    private:
};

#endif
