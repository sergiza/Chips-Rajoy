#ifndef DVD_H
#define DVD_H

#include <SDL2/SDL.h>
#include <string>

class DVD {
    public:
        DVD();
        void update_DVD(int window_width, int window_height);

        std::string text_String;
        SDL_Rect text_rectangle;
        int text_velocity;
        int text_X_velocity;
        int text_Y_velocity;

    private:
};


#endif
