#include "Fonts.h"

Fonts::Fonts()
    : font_size{80},
      font_color{255, 255, 255, 255},
      font{nullptr, TTF_CloseFont} {}


TTF_Font* Fonts::load_font(const std::string& ttf, int font_size) {
    TTF_Font* font = TTF_OpenFont(ttf.c_str(), font_size);
    if (!font) {    // if font is null
        auto error = std::format("Error creating Font: {}", TTF_GetError());
        throw std::runtime_error(error);
    }
    return font;
}

SDL_Surface* Fonts::render_font(const std::string& text_string) {
    SDL_Surface* surface = TTF_RenderText_Blended(font.get(), text_string.c_str(), font_color);
    if (!surface) {    // if surface is null
        auto error = std::format("Error loading text Surface: {}", TTF_GetError());
        throw std::runtime_error(error);
    }
    return surface;
}


void Fonts::init() {
    font.reset(load_font(ttf_default.c_str(), font_size));
}
