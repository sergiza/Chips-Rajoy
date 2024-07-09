#include "DVD.h"

DVD::DVD()
    : text_String{"DVD"},
      text_rectangle{0, 0, 0, 0},
      text_velocity{3},
      text_X_velocity{3}, text_Y_velocity{3} {}

void DVD::update_DVD(int window_width, int window_height) {
    text_rectangle.x += text_X_velocity;
    text_rectangle.y += text_Y_velocity;

    if (text_rectangle.x < 0) {
        text_X_velocity = text_velocity;
    } else if (text_rectangle.x + text_rectangle.w > window_width) {
        text_X_velocity = -text_velocity;
    }
    if (text_rectangle.y < 0) {
        text_Y_velocity = text_velocity;
    } else if (text_rectangle.y + text_rectangle.h > window_height) {
        text_Y_velocity = -text_velocity;
    }
}
