#include "Game.h"

Game::Game()    // constructor
    : title{"sdlgz"},
      background{nullptr, SDL_DestroyTexture},
      Surface_DVDtext(nullptr, SDL_FreeSurface),
      Texture_DVDtext{nullptr, SDL_DestroyTexture} {}

void Game::init() {
    graphics.init(window_width, window_height, title);
    fonts.init();
}

void Game::load_media() {
    background.reset(graphics.load_texture("rsrc/images/adibu.jpg"));
    Surface_DVDtext.reset(fonts.render_font("DVD"));

    dvd.text_rectangle.w = Surface_DVDtext->w;
    dvd.text_rectangle.h = Surface_DVDtext->h;

    Texture_DVDtext.reset(graphics.texture_from_surface(Surface_DVDtext.get()));
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

        dvd.update_DVD(window_width, window_height);

        SDL_RenderClear(graphics.get_renderer());
        SDL_RenderCopy(graphics.get_renderer(), background.get(), nullptr, nullptr);
        SDL_RenderCopy(graphics.get_renderer(), Texture_DVDtext.get(), nullptr, &dvd.text_rectangle);
        SDL_RenderPresent(graphics.get_renderer());

        SDL_Delay(16); // close to 60 frames/second
    }
}
