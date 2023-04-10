#include <string.h>
#include "vline.h"
#include "new.h"
#include "parameters.h"

static int conditions(int y1, int y2, int x, int pos_y) {
    if ((x >= 0)
        && (y1 <= pos_y)
        && (y2 >= pos_y)
        && (x < field_width - field_x - 1)) {
        return 1;
    }
    return 0;
}


static void Vline_draw(const void* _self)
{
    const struct Vline* self = _self;
    for (int field_pos_y = 0; field_pos_y < field_height - field_y - 1; ++field_pos_y) {
        if (conditions(self->start_point.y, self->end_point.y, self->start_point.x, field_pos_y)) {
            con_charAt(char_point, color_point, field_x + self->start_point.x + 1, field_y + field_pos_y + 1);
        }
    }
}

static void* Vline_ctor(void* _self, va_list* app)
{
    struct Vline* self = ((const struct Class*)Shape)->ctor(_self, app);
    struct Point* point_temp = new(Point, 0, 0);

    memcpy(&self->start_point, point_temp, sizeof(struct Point));
    memcpy(&self->end_point, point_temp, sizeof(struct Point));

    self->start_point.y = va_arg(*app, int);
    self->end_point.y = va_arg(*app, int);
    self->start_point.x = va_arg(*app, int);
    self->end_point.x = self->start_point.x;

    self->shape.draw = Vline_draw;
    return self;
}

static const struct Class _Vline = {
    sizeof(struct Vline),
    Vline_ctor,
    0
};

const void* Vline = &_Vline;