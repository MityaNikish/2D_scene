#include "creator_shape.h"
#include "rect.h"
#include "new.h"

static void* CreatorRect_figure_creation(const void* _self, va_list* app)
{
    const struct CreatorRect* self = _self;
    int arg1 = va_arg(*app, int);
    int arg2 = va_arg(*app, int);
    int arg3 = va_arg(*app, int);
    int arg4 = va_arg(*app, int);
    return new(Rect, arg1, arg2, arg3, arg4);
}

static void* CreatorRect_ctor(void* _self, va_list* app)
{
    struct CreatorRect* self = _self;
    return self;
}

static const struct Creator _CreatorRect = {
    {
    sizeof(struct CreatorRect),
    CreatorRect_ctor,
    0
    },
    "rect",
    4,
    CreatorRect_figure_creation
};

const void* CreatorRect = &_CreatorRect;