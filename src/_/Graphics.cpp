#include "Graphics.h"
#include <stdexcept>
#include <format>

Graphics::Graphics(std::string& title, int width, int height)
    : window{SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0), SDL_DestroyWindow},
        renderer{SDL_CreateRenderer(window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer} {
            if (!window) {
                throw std::runtime_error(std::format("Error creating Window: {}", SDL_GetError()));
            }
            if (!renderer) {
                throw std::runtime_error(std::format("Error creating Renderer: {}", SDL_GetError()));
            }
        }

Graphics::~Graphics() {
    // Destructores únicos se encargan de limpiar
}

SDL_Renderer* Graphics::get_renderer() const {
    return renderer.get();
}

SDL_Texture* Graphics::load_texture(const std::string& file_path) {
    SDL_Texture* texture = IMG_LoadTexture(renderer.get(), file_path.c_str());
    if (!texture) {
        throw std::runtime_error(std::format("Error loading texture: {}", IMG_GetError()));
    }
    return texture;
}
