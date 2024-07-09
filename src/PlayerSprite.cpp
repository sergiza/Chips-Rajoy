#include "PlayerSprite.h"

PlayerSprite::PlayerSprite()
    : playerSprite_rectangle{0,0,0,0}, 
      playerSprite_velocity{5} {}

void PlayerSprite::update_PlayerSprite(const Uint8 *keystate) {
    if (keystate[SDL_SCANCODE_LEFT] || keystate[SDL_SCANCODE_H]) {
        playerSprite_rectangle.x -= playerSprite_velocity;
    }
    if (keystate[SDL_SCANCODE_RIGHT] || keystate[SDL_SCANCODE_L]) {
        playerSprite_rectangle.x += playerSprite_velocity;
    }
    if (keystate[SDL_SCANCODE_UP] || keystate[SDL_SCANCODE_K]) {
        playerSprite_rectangle.y -= playerSprite_velocity;
    }
    if (keystate[SDL_SCANCODE_DOWN] || keystate[SDL_SCANCODE_J]) {
        playerSprite_rectangle.y += playerSprite_velocity;
    }
}
