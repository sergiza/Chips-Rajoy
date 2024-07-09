#include "PlayerSprite.h"

PlayerSprite::PlayerSprite()
    : playerSprite_rectangle{0,0,0,0}, 
      playerSprite_velocity{5} {}

void PlayerSprite::update_PlayerSprite(const Uint8 *keystate) {
    if (keystate[SDL_SCANCODE_LEFT]) {
        playerSprite_rectangle.x -= playerSprite_velocity;
    }
    if (keystate[SDL_SCANCODE_RIGHT]) {
        playerSprite_rectangle.x += playerSprite_velocity;
    }
    if (keystate[SDL_SCANCODE_UP]) {
        playerSprite_rectangle.y -= playerSprite_velocity;
    }
    if (keystate[SDL_SCANCODE_DOWN]) {
        playerSprite_rectangle.y += playerSprite_velocity;
    }
}
