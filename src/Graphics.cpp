#include "Graphics.h"

SDL_Texture* Graphics::LoadTexture(const std::string& file, SDL_Renderer* ren) {
    SDL_Surface* tmpSurface = IMG_Load(file.c_str());
    if (!tmpSurface) {
        SDL_Log("Failed to load image %s: %s", file.c_str(), IMG_GetError());
        return nullptr;
    }
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);
    SDL_FreeSurface(tmpSurface);
    return tex;
}
