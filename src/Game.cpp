#include "Game.h"
#include "Graphics.h"
#include "Audio.h"
#include "Font.h"
#include <stdio.h>
#include "SDL2/SDL_ttf.h"

Game::Game() {
    // INIT
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Chips-Rajoy!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    IMG_Init(IMG_INIT_PNG);
    Audio::Init();
    Font::Init();

    // assets
    bgTexture = Graphics::LoadTexture(PATH_bgTexture, renderer);
    cookieTexture = Graphics::LoadTexture(PATH_cookieTexture , renderer);
    Mix_Music* bgm = Audio::LoadMusic(PATH_music_bossa);
    Audio::PlayMusic(bgm);
    font = TTF_OpenFont(PATH_font.c_str(), 24);
    if (!font) SDL_Log("Error loading font");
}

Game::~Game() {
    if (bgTexture)
        SDL_DestroyTexture(bgTexture);
    if (cookieTexture)
        SDL_DestroyTexture(cookieTexture);
    if (font)
        TTF_CloseFont(font);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    Mix_CloseAudio();
    TTF_Quit();
}

void Game::loop() {
    while (running) {
        render();
        input();
        update();
    }
}

void Game::input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) running = false;

        if (event.type == SDL_MOUSEBUTTONDOWN) {
            int mx = event.button.x;
            int my = event.button.y;
            if (mx >= rect.x && mx <= rect.x + rect.w &&
                my >= rect.y && my <= rect.y + rect.h) {
                state.score += state.multiplier;
                printf("Cookies: %d\n", state.score);
                Mix_Chunk* popSound = Audio::LoadSound(PATH_sound_pop);
                Audio::PlaySound(popSound);
            }
        }
    }
}

void Game::update() {
    // TO DO
}

void Game::render() {
    if (bgTexture)
        SDL_RenderCopy(renderer, bgTexture, nullptr, nullptr);
    if (cookieTexture)
        SDL_RenderCopy(renderer, cookieTexture, nullptr, &rect);

    std::string Text_score = "Cookies: " + std::to_string(state.score);
    SDL_Color white = {255, 255, 255, 255};
    SDL_Texture* textTex = Font::RenderText(Text_score, font, white, renderer);
    if (textTex) {
        int tw, th;
        SDL_QueryTexture(textTex, nullptr, nullptr, &tw, &th);
        SDL_Rect dst = {10, 480 - th - 10, tw, th};
        SDL_RenderCopy(renderer, textTex, nullptr, &dst);
        SDL_DestroyTexture(textTex);
    }

    SDL_RenderPresent(renderer);
}
