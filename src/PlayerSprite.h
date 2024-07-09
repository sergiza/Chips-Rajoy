#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class PlayerSprite {
    public:
        PlayerSprite();
        void update_PlayerSprite(const Uint8 *keystate);

        SDL_Rect playerSprite_rectangle;
        int playerSprite_velocity;

    private:
};

#endif
