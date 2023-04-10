#include <string.h>

#include "rect.h"
#include "hline.h"
#include "vline.h"

#include "new.h"
#include "parameters.h"


static int conditions(struct Point start_point, struct Point end_point, int pos_x, int pos_y) {
    if ((pos_y == start_point.y) || (pos_y == end_point.y)) {
        if ((pos_x >= start_point.x) && (pos_x <= end_point.x)) {
            return 1;
        }
    }
    
    else if ((pos_y > start_point.y) && (pos_y < end_point.y)) {
        if ((pos_x == start_point.x) || (pos_x == end_point.x)) {
            return 1;
        }
    }

    return 0;
}

static void Rect_draw(const void* _self) {
    const struct Rect* self = _self;

    for (int field_pos_y = 0; field_pos_y < field_height - field_y - 1; ++field_pos_y) {
        for (int field_pos_x = 0; field_pos_x < field_width - field_x - 1; ++field_pos_x) {
            if (conditions(self->start_point, self->end_point, field_pos_x, field_pos_y)) {
                con_charAt(char_point, color_point, field_x + field_pos_x + 1, field_y + field_pos_y + 1);
            }
        }
    }
}


static void* Rect_ctor(void* _self, va_list* app)
{
    struct Rect* self = ((const struct Class*)Shape)->ctor(_self, app);
    struct Point* point_temp = new(Point, 0, 0);

    memcpy(&self->start_point, point_temp, sizeof(struct Point));
    self->start_point.x = va_arg(*app, int);
    self->start_point.y = va_arg(*app, int);

    memcpy(&self->end_point, point_temp, sizeof(struct Point));
    self->end_point.x = va_arg(*app, int);
    self->end_point.y = va_arg(*app, int);

    self->shape.draw = Rect_draw;
    return self;
}


static const struct Class _Rect = {
    sizeof(struct Rect),
    Rect_ctor,
    0
};

const void* Rect = &_Rect;
