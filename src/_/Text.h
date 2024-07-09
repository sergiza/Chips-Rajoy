#ifndef TEXT_H
#define TEXT_H

#include <SDL2/SDL_ttf.h>
#include <memory>
#include <string>
#include <SDL2/SDL.h>

class Text {
    public:
        Text(std::string& font_path, int font_size, SDL_Color color, SDL_Renderer* renderer);
        ~Text();

        SDL_Texture* create_texture(std::string& text, int& width, int& height);
        void update_position(int& x, int& y, int& x_vel, int& y_vel, int screen_width, int screen_height, int text_width, int text_height);

    private:
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font;
        SDL_Color color;
        SDL_Renderer* renderer;
};

#endif // TEXT_H
