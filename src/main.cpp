#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <format>
#include <iostream>
#include <memory>

class Game {
    public:
        Game();

        void init();
        void run();
        void load_media();

        static constexpr int width{800};
        static constexpr int height{600};

    private:
        const std::string title;
        SDL_Event event;
        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
};
Game::Game()    // constructor
    : title{"Open Window"}, window{nullptr, SDL_DestroyWindow}, renderer{nullptr, SDL_DestroyRenderer}, background{nullptr, SDL_DestroyTexture} {}

void Game::init() {
    this->window.reset(
            SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, this->width, this->height, 0));
    if (!this->window) {    // if window is null
        auto error = std::format("Error creating Window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->renderer.reset(
            SDL_CreateRenderer(this->window.get(), -1, SDL_RENDERER_ACCELERATED));
    if (!this->renderer) {    // if renderer is null
        auto error = std::format("Error creating Renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Game::load_media() {
    this->background.reset(IMG_LoadTexture(this->renderer.get(), "rsrc/images/background.png"));
    if (!this->background) {    // if background is null
        auto error = std::format("Error loading texture: {}", IMG_GetError());
        throw std::runtime_error(error);
    }
}

void Game::run() {
    SDL_Delay(100);
    while (true) {
        while (SDL_PollEvent(&this->event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_Q:
                            return;
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }
        SDL_RenderClear(this->renderer.get());

        SDL_RenderCopy(this->renderer.get(), this->background.get(), nullptr, nullptr);

        SDL_RenderPresent(this->renderer.get());
        SDL_Delay(16); // close to 60 frames/second
    }
}

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
}

void close_sdl() {
    IMG_Quit();
    SDL_Quit();
}

int main()
{
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
