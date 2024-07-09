#include "Game.h"

Game::Game()    // constructor
    : title{"sdlgz"},
      icon{nullptr, SDL_FreeSurface},
      background{nullptr, SDL_DestroyTexture},
      DVDtext_Surface(nullptr, SDL_FreeSurface),
      DVDtext_Texture{nullptr, SDL_DestroyTexture},
      icon_Texture{nullptr, SDL_DestroyTexture},
      keystate{SDL_GetKeyboardState(nullptr)} {}

void Game::init() {
    graphics.init(window_width, window_height, title);
    fonts.init();
}

void Game::load_media() {
    background.reset(graphics.load_texture("rsrc/images/adibu.jpg"));

    DVDtext_Surface.reset(fonts.render_font("DVD"));
    dvd.text_rectangle.w = DVDtext_Surface->w;
    dvd.text_rectangle.h = DVDtext_Surface->h;
    DVDtext_Texture.reset(graphics.texture_from_surface(DVDtext_Surface.get()));

    icon.reset(graphics.load_surface("rsrc/images/Cpp-logo.png"));
    SDL_SetWindowIcon(graphics.get_window(), icon.get());

    playerSprite.playerSprite_rectangle.w = icon->w;
    playerSprite.playerSprite_rectangle.h = icon->h;
    icon_Texture.reset(graphics.texture_from_surface(icon.get()));
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
        playerSprite.update_PlayerSprite(keystate);

        SDL_RenderClear(graphics.get_renderer());
        SDL_RenderCopy(graphics.get_renderer(), background.get(), nullptr, nullptr);
        SDL_RenderCopy(graphics.get_renderer(), DVDtext_Texture.get(), nullptr, &dvd.text_rectangle);
        SDL_RenderCopy(graphics.get_renderer(), icon_Texture.get(), nullptr, &playerSprite.playerSprite_rectangle);
        SDL_RenderPresent(graphics.get_renderer());

        SDL_Delay(16); // close to 60 frames/second
    }
}
