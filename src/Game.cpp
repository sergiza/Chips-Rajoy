#include "Game.h"

Game::Game()    // constructor
    : title{"sdlgz"},
      icon{nullptr, SDL_FreeSurface},
      background{nullptr, SDL_DestroyTexture},
      icon_Texture{nullptr, SDL_DestroyTexture},
      keystate{SDL_GetKeyboardState(nullptr)},
      sound_pop{nullptr, Mix_FreeChunk},
      music_bossa{nullptr, Mix_FreeMusic} {}

Game::~Game() { 
    Mix_HaltChannel(-1);
    Mix_HaltMusic();
}

void Game::init() {
    graphics.init(window_width, window_height, title);
    fonts.init();
}

void Game::load_media() {
    background.reset(graphics.load_texture("rsrc/images/fondo-pastel_blurry.png"));
    icon.reset(graphics.load_surface("rsrc/images/cookie-COOKIE.png"));
    SDL_SetWindowIcon(graphics.get_window(), icon.get());

    icon_Texture.reset(graphics.texture_from_surface(icon.get()));

    sound_pop.reset(sound.load_sound("rsrc/sounds/pop.ogg"));
    music_bossa.reset(sound.load_music("rsrc/music/Bossa Antigua.mp3"));
}


void Game::run() {
    SDL_Delay(100);
    Mix_PlayMusic(music_bossa.get(), -1);

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
                        case SDL_SCANCODE_SPACE:
                            Mix_PlayChannel(-1, sound_pop.get(), 0);
                            break;
                        case SDL_SCANCODE_M:
                            if (Mix_PausedMusic())
                                Mix_ResumeMusic();
                            else
                                Mix_PauseMusic();
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }


        SDL_RenderClear(graphics.get_renderer());
        SDL_RenderCopy(graphics.get_renderer(), background.get(), nullptr, nullptr);
        SDL_RenderPresent(graphics.get_renderer());

        SDL_Delay(16); // close to 60 frames/second
    }
}
