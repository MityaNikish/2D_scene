#include "creator_shape.h"
#include "vline.h"
#include "new.h"

static void* CreatorVLine_figure_creation(const void* _self, va_list* app)
{
    const struct CreatorVLine* self = _self;
    int arg1 = va_arg(*app, int);
    int arg2 = va_arg(*app, int);
    int arg3 = va_arg(*app, int);
    return new(Vline, arg1, arg2, arg3);
}

static void* CreatorVLine_ctor(void* _self, va_list* app)
{
    struct CreatorVLine* self = _self;
    return self;
}

static const struct Creator _CreatorVLine = {
    {
    sizeof(struct CreatorVLine),
    CreatorVLine_ctor,
    0
    },
    "vline",
    3,
    CreatorVLine_figure_creation
};

const void* CreatorVLine = &_CreatorVLine;