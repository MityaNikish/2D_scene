#pragma once

extern const int title_x;
extern const int title_y;

extern const int field_padding;

extern const int char_border;
extern const int char_field;
extern const int char_point;
extern const int char_nothing;

extern const int color_border;
extern const int color_field;
extern const int color_point;
extern const int color_nothing;

extern const int field_width;
extern const int field_height;

extern const int field_x;
extern const int field_y;

extern const int max_x;
extern const int max_y;

/* Output char using given color pair at given position. */
void con_charAt(int image_char, int color, int x, int y);