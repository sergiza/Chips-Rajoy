#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>


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
    void input();
    void update();
    void render();

    bool running = true;
    GameState state;
    Uint32 lastAutoClick = 0;
    std::vector<Upgrade> upgrades;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // ASSETS
    // images
    SDL_Rect rect = {100, 100, 130, 130};
    SDL_Texture* cookieTexture = nullptr;
    std::string PATH_cookieTexture = "rsrc/images/cookie-COOKIE.png";
    SDL_Texture* bgTexture = nullptr;
    std::string PATH_bgTexture = "rsrc/images/fondo-pastel_blurry.png";
    SDL_Texture* upgradeMilkTexture = nullptr;
    SDL_Texture* upgradeRajoyTexture = nullptr;
    std::string PATH_upgradeMilk = "rsrc/images/milk.png";
    std::string PATH_upgradeRajoy = "rsrc/images/rajoy.png";
    // music
    std::string PATH_music_bossa="rsrc/music/Bossa Antigua.mp3";
    std::string PATH_sound_pop="rsrc/sounds/pop.ogg";
    std::string PATH_sound_chaching="rsrc/sounds/cha-ching.ogg";
    // font
    TTF_Font* font = nullptr;
    std::string PATH_font="rsrc/fonts/Monocraft.ttf";
};
