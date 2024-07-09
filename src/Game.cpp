#include "Game.h"

Game::Game()    // constructor
    : title{"sdlgz"},
        font_size{80}, font_color{255, 255, 255, 255},
        text_str{"SDL"}, text_rect{0, 0, 0, 0},
        text_vel{3}, text_xvel{3}, text_yvel{3},
        background{nullptr, SDL_DestroyTexture},
        font{nullptr, TTF_CloseFont},
        text_surf(nullptr, SDL_FreeSurface),
        text{nullptr, SDL_DestroyTexture} {}

void Game::init() {
    graphics.init(width, height, title);
}

void Game::load_media() {
    this->background.reset(IMG_LoadTexture(graphics.get_renderer(), "rsrc/images/background.png"));
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

    this->text.reset(SDL_CreateTextureFromSurface(graphics.get_renderer(), this->text_surf.get()));
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

        SDL_RenderClear(graphics.get_renderer());

        SDL_RenderCopy(graphics.get_renderer(), this->background.get(), nullptr, nullptr);

        SDL_RenderCopy(graphics.get_renderer(), this->text.get(), nullptr, &this->text_rect);

        SDL_RenderPresent(graphics.get_renderer());
        SDL_Delay(16); // close to 60 frames/second
    }
}
