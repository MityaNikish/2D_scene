#include "creator_shape.h"
#include "point.h"
#include "new.h"

static void* CreatorPoint_figure_creation(const void* _self, va_list* app)
{
    const struct CreatorPoint* self = _self;
    int arg1 = va_arg(*app, int);
    int arg2 = va_arg(*app, int);
    return new(Point, arg1, arg2);
}

static void* CreatorPoint_ctor(void* _self, va_list* app)
{
    struct CreatorPoint* self = _self;
    return self;
}

static const struct Creator _CreatorPoint = {
    {
    sizeof(struct CreatorPoint),
    CreatorPoint_ctor,
    0
    },
    "point",
    2,
    CreatorPoint_figure_creation
};

const void* CreatorPoint = &_CreatorPoint;