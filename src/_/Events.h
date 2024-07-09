#ifndef EVENTS_H
#define EVENTS_H

#include <SDL2/SDL.h>

class Events {
    public:
        bool handle_event(SDL_Event& event);
};

#endif
