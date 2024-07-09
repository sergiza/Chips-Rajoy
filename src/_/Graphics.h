#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <memory>
#include <string>

class Graphics {
    public: 
        Graphics(std::string& title, int width, int height);
        ~Graphics();

        SDL_Renderer* get_renderer() const;
        SDL_Texture* load_texture(const std::string& file_path);

    private:
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
};

#endif
