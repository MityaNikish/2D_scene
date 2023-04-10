#include <string.h>
#include "hline.h"
#include "new.h"
#include "parameters.h"

static int conditions(int x1, int x2, int y, int pos_x) {
    if ((y >= 0)
        && (x1 <= pos_x)
        && (x2 >= pos_x)
        && (y < field_height - field_y - 1)) {
        return 1;
    }
    return 0;
}


static void Hline_draw(const void* _self)
{
    const struct Hline* self = _self;
    for (int field_pos_x = 0; field_pos_x < field_width - field_x - 1; ++field_pos_x) {
        if (conditions(self->start_point.x, self->end_point.x, self->start_point.y, field_pos_x)) {
            con_charAt(char_point, color_point, field_x + field_pos_x + 1, field_y + self->start_point.y + 1);
        }
    }
}

static void* Hline_ctor(void* _self, va_list* app)
{
    struct Hline* self = ((const struct Class*)Shape)->ctor(_self, app);

    struct Point* point_temp = new(Point, 0, 0);

    memcpy(&self->start_point, point_temp, sizeof(struct Point));
    memcpy(&self->end_point, point_temp, sizeof(struct Point));

    self->start_point.x = va_arg(*app, int);
    self->end_point.x = va_arg(*app, int);
    self->start_point.y = va_arg(*app, int);
    self->end_point.y = self->start_point.y;

    self->shape.draw = Hline_draw;
    return self;
}

static const struct Class _Hline = {
    sizeof(struct Hline),
    Hline_ctor,
    0
};

const void* Hline = &_Hline;