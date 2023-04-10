#include "point.h"
#include "new.h"
#include "parameters.h"

static int conditions(int x, int y) {
    if ((y >= 0)
        && (x >= 0)
        && (x <= field_width - field_x - 1)
        && (y <= field_height - field_y - 1)) {
        return 1;
    }
    return 0;
}


static void Point_draw(const void* _self)
{
    const struct Point* self = _self;
    if (conditions(self->x, self->y)) {
        con_charAt(char_point, color_point, field_x + self->x + 1, field_y + self->y + 1);
    }
}

static void* Point_ctor(void* _self, va_list* app)
{
    struct Point* self = ((const struct Class*)Shape)->ctor(_self, app);
    self->x = va_arg(*app, int);
    self->y = va_arg(*app, int);
    self->shape.draw = Point_draw;
    return self;
}


static const struct Shape _Point = {
    {
    sizeof(struct Point),
    Point_ctor,
    0
    },
    Point_draw
};


const void* Point = &_Point;
