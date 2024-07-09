#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>

class PlayerSprite {
    public:
        PlayerSprite();
        void update_PlayerSprite(int window_width, int window_height);

        SDL_Rect playerSprite_rectangle;
        int playerSprite_velocity;

    private:
};


#endif
