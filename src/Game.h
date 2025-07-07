#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>


struct GameState {
    int score = 0;
    int multiplier = 1;
};

struct Upgrade {
    std::string name;
    SDL_Texture* texture = nullptr;
    SDL_Rect rect;
    int cost;
    int owned = 0;
    bool available = false;
};

class Game {
public:
    Game();
    ~Game();
    void loop();

private:
    // game loop
    void input();
    void update();
    void render();
    bool running = true;
    GameState state;

    // ASSETS
    // cookie
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Rect rect = {100, 100, 100, 100};
    SDL_Texture* cookieTexture = nullptr;
    std::string PATH_cookieTexture = "rsrc/images/cookie-COOKIE.png";
    // bg
    SDL_Texture* bgTexture = nullptr;
    std::string PATH_bgTexture = "rsrc/images/fondo-pastel_blurry.png";
    // music
    std::string PATH_music_bossa="rsrc/music/Bossa Antigua.mp3";
    std::string PATH_sound_pop="rsrc/sounds/pop.ogg";
    // font
    TTF_Font* font = nullptr;
    std::string PATH_font="rsrc/fonts/Monocraft.ttf";
    // upgrades
    std::string PATH_upgradeMilk = "rsrc/images/milk.png";
    std::string PATH_upgradeRajoy = "rsrc/images/rajoy.png";
};
