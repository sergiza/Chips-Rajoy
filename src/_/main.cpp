#include "Game.h"

void initialize_sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        auto error = std::format("Error initializing SDL2: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    int img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if ((IMG_Init(img_flags) & img_flags) != img_flags) {
        auto error = std::format("Error initializing SDL_image: {}", IMG_GetError());
        throw std::runtime_error(error);
    }

    if (TTF_Init()) {
        auto error = std::format("Error initializing SDL_ttf: {}", TTF_GetError());
        throw std::runtime_error(error);
    }
}

void close_sdl() {
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main() {
    int exit = EXIT_SUCCESS;

    try {
        initialize_sdl();
        Game game;
        game.init();
        game.load_media();
        game.run();
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        exit = EXIT_FAILURE;
    }

    close_sdl();
    return exit;
}
