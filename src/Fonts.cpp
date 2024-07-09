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



SDL_Texture* Fonts::load_font_asTexture(const std::string& file_path, SDL_Renderer* renderer) {
    SDL_Texture* texture = IMG_LoadTexture(renderer, file_path.c_str());
    if (!texture) {
        throw std::runtime_error(std::format("Error loading texture: {}", IMG_GetError()));
    }
    return texture;
}

void Fonts::init() {
    font.reset(load_font(ttf_default.c_str(), font_size));
}
