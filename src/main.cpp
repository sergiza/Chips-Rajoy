#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
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
        void update_text();

        const std::string title;
        SDL_Event event;
        int font_size;
        SDL_Color font_color;
        std::string text_str;
        SDL_Rect text_rect;
        const int text_vel;
        int text_xvel;
        int text_yvel;

        std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> window;
        std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> renderer;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> background;
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font;
        std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> text_surf;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> text;
};
Game::Game()    // constructor
    : title{"sdlgz"},
        font_size{80}, font_color{255, 255, 255, 255},
        text_str{"SDL"}, text_rect{0, 0, 0, 0},
        text_vel{3}, text_xvel{3}, text_yvel{3},
        window{nullptr, SDL_DestroyWindow},
        renderer{nullptr, SDL_DestroyRenderer},
        background{nullptr, SDL_DestroyTexture},
        font{nullptr, TTF_CloseFont},
        text_surf(nullptr, SDL_FreeSurface),
        text{nullptr, SDL_DestroyTexture} {}

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

    this->font.reset(TTF_OpenFont("rsrc/fonts/freesansbold.ttf", this->font_size));
    if (!this->font) {    // if font is null
        auto error = std::format("Error creating Font: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    this->text_surf.reset(TTF_RenderText_Blended(this->font.get(), this->text_str.c_str(), this->font_color));
    if (!this->text_surf) {    // if surface is null
        auto error = std::format("Error loading text Surface: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    this->text_rect.w = this->text_surf->w;
    this->text_rect.h = this->text_surf->h;

    this->text.reset(SDL_CreateTextureFromSurface(this->renderer.get(), this->text_surf.get()));
    if (!this->text) {    // if text is null
        auto error = std::format("Error creating Texture from Surface: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Game::update_text() {
    this->text_rect.x += this->text_xvel;
    this->text_rect.y += this->text_yvel;

    if (this->text_rect.x < 0) {
        this->text_xvel = this->text_vel;
    } else if (this->text_rect.x + this->text_rect.w > this->width) {
        this->text_xvel = -this->text_vel;
    }
    if (this->text_rect.y < 0) {
        this->text_yvel = this->text_vel;
    } else if (this->text_rect.y + this->text_rect.h > this->height) {
        this->text_yvel = -this->text_vel;
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

        this->update_text();

        SDL_RenderClear(this->renderer.get());

        SDL_RenderCopy(this->renderer.get(), this->background.get(), nullptr, nullptr);

        SDL_RenderCopy(this->renderer.get(), this->text.get(), nullptr, &this->text_rect);

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
