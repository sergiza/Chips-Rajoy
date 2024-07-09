#include "Graphics.h"

Graphics::Graphics()
    : window{nullptr, SDL_DestroyWindow},
      renderer{nullptr, SDL_DestroyRenderer} {}

void Graphics::init(int width, int height, std::string title) {
    // create window
    this->window.reset( SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, width, height, 0));
    if (!this->window) {
        auto error = std::format("Error creating Window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    // create renderer
    this->renderer.reset( SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED));
    if (!this->renderer) {    // if renderer is null
        auto error = std::format("Error creating Renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

SDL_Renderer* Graphics::get_renderer() { // const?
    return renderer.get();
}
