#pragma once
#include <SDL2/SDL_ttf.h>
#include <string>

class Font {
public:
    static bool Init();
    static SDL_Texture* RenderText(const std::string& message, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);
};
