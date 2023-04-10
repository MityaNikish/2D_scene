#include "init_field.h"
#include "parameters.h"
#include "console.h"

void init_colors() {
    con_initPair((short)color_border, (short)CON_COLOR_BLACK, (short)CON_COLOR_BLUE);
    con_initPair((short)color_field, (short)CON_COLOR_GREEN, (short)CON_COLOR_GREEN);
    con_initPair((short)color_point, (short)CON_COLOR_RED, (short)CON_COLOR_GREEN);
}

void initial_draw() {
    con_clearScr();
    con_gotoXY(title_x, title_y);
    con_outTxt("Use arrows to move point, use Esc to exit.");

    {
        int image_char;
        int color;
        for (int window_pos_x = 0; window_pos_x < max_x; ++window_pos_x) {
            for (int window_pos_y = 1; window_pos_y < max_y; ++window_pos_y) {
                if (window_pos_x < field_x || window_pos_x > field_width || window_pos_y < field_y || window_pos_y > field_height) {
                    image_char = char_nothing;
                    color = color_nothing;
                }
                else if (window_pos_x == field_x || window_pos_x == field_width || window_pos_y == field_y || window_pos_y == field_height) {
                    image_char = char_border;
                    color = color_border;
                }
                else {
                    image_char = char_field;
                    color = color_field;
                }
                con_charAt(image_char, color, window_pos_x, window_pos_y);
            }
        }
    }
}