#include <SDL2/SDL.h>
#include <format>
#include <iostream>
#include <memory>

class Game {
    public:
        Game();

        void init();
        void run();

        static constexpr int width{800};
        static constexpr int height{600};

    private:
        const std::string title;
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
};
Game::Game()    // constructor
    : title{"Open Window"}, window{nullptr, SDL_DestroyWindow} {}

void Game::init() {
    this->window.reset(SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, 0));
    if (!this->window) {    // if window is null
        auto error = std::format("Error creating Window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Game::run() {
    SDL_Delay(2000);
}


void initialize_sdl() {
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        auto error = std::format("Error initializing SDL2: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void close_sdl() {
    SDL_Quit();
}

int main()
{
    int exit = EXIT_SUCCESS;

    try {
        initialize_sdl();
        Game game;
        game.init();
        game.run();
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        exit = EXIT_FAILURE;
    }

    close_sdl();
    return exit;
}
