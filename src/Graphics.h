#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <unordered_map>

class Graphics {
public:
    static SDL_Texture* LoadTexture(const std::string& file, SDL_Renderer* ren);
};
