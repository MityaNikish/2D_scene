#include "parameters.h"
#include "console.h"

const int title_x = 3;
const int title_y = 1;
      
const int field_padding = 3;
      
const int char_border = '#';
const int char_field = ' ';
const int char_point = '@';
const int char_nothing = ' ';
      
const int color_border = 1;
const int color_field = 2;
const int color_point = 3;
const int color_nothing = 4;
      
const int field_width = 165;
const int field_height = 38;
      
const int field_x = 5;
const int field_y = 3;
      
const int max_x = 173; //173
const int max_y = 41; //41

void con_charAt(int image_char, int color, int x, int y) {
    con_gotoXY(x, y);
    con_setColor(color);
    con_outTxt("%c", image_char);
}