#include "Game.h"

Game::Game()    // constructor
    : title{"sdlgz"},
      text_str{"DVD"},
      text_rect{0, 0, 0, 0},
      text_vel{3}, text_xvel{3}, text_yvel{3},
      background{nullptr, SDL_DestroyTexture},
      Surface_DVDtext(nullptr, SDL_FreeSurface),
      text{nullptr, SDL_DestroyTexture} {}

void Game::init() {
    graphics.init(window_width, window_height, title);
    fonts.init();
}

void Game::load_media() {
    background.reset(graphics.load_texture("rsrc/images/adibu.jpg"));

    Surface_DVDtext.reset(TTF_RenderText_Blended(fonts.font.get(), text_str.c_str(), fonts.font_color));
    if (!Surface_DVDtext) {    // if surface is null
        auto error = std::format("Error loading text Surface: {}", TTF_GetError());
        throw std::runtime_error(error);
    }

    text_rect.w = Surface_DVDtext->w;
    text_rect.h = Surface_DVDtext->h;

    text.reset(SDL_CreateTextureFromSurface(graphics.get_renderer(), Surface_DVDtext.get()));
    if (!text) {    // if text is null
        auto error = std::format("Error creating Texture from Surface: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}

void Game::update_text() {
    text_rect.x += text_xvel;
    text_rect.y += text_yvel;

    if (text_rect.x < 0) {
        text_xvel = text_vel;
    } else if (text_rect.x + text_rect.w > window_width) {
        text_xvel = -text_vel;
    }
    if (text_rect.y < 0) {
        text_yvel = text_vel;
    } else if (text_rect.y + text_rect.h > window_height) {
        text_yvel = -text_vel;
    }
}

void Game::run() {
    SDL_Delay(100);
    while (true) {
        while (SDL_PollEvent(&event)) {
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

        update_text();

        SDL_RenderClear(graphics.get_renderer());
        SDL_RenderCopy(graphics.get_renderer(), background.get(), nullptr, nullptr);
        SDL_RenderCopy(graphics.get_renderer(), text.get(), nullptr, &text_rect);
        SDL_RenderPresent(graphics.get_renderer());

        SDL_Delay(16); // close to 60 frames/second
    }
}
