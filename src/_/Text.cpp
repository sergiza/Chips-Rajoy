#include "Text.h"
#include <stdexcept>
#include <format>

Text::Text(std::string& font_path, int font_size, SDL_Color color, SDL_Renderer* renderer)
    : font{TTF_OpenFont(font_path.c_str(), font_size), TTF_CloseFont},
      color{color},
      renderer{renderer} {
    if (!font) {
        throw std::runtime_error(std::format("Error creating Font: {}", TTF_GetError()));
    }
}

Text::~Text() {
    // Destructores únicos se encargan de limpiar
}

SDL_Texture* Text::create_texture(std::string& text, int& width, int& height) {
    SDL_Surface* surface = TTF_RenderText_Blended(font.get(), text.c_str(), color);
    if (!surface) {
        throw std::runtime_error(std::format("Error loading text Surface: {}", TTF_GetError()));
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface(surface);
    if (!texture) {
        throw std::runtime_error(std::format("Error creating Texture from Surface: {}", SDL_GetError()));
    }
    return texture;
}

void Text::update_position(int& x, int& y, int& x_vel, int& y_vel, int screen_width, int screen_height, int text_width, int text_height) {
    x += x_vel;
    y += y_vel;

    if (x < 0) {
        x_vel = 3;
    } else if (x + text_width > screen_width) {
        x_vel = -3;
    }
    if (y < 0) {
        y_vel = 3;
    } else if (y + text_height > screen_height) {
        y_vel = -3;
    }
}
