#include "creator_shape.h"
#include "hline.h"
#include "new.h"

static void* CreatorHLine_figure_creation(const void* _self, va_list* app)
{
    const struct CreatorHLine* self = _self;
    int arg1 = va_arg(*app, int);
    int arg2 = va_arg(*app, int);
    int arg3 = va_arg(*app, int);
    return new(Hline, arg1, arg2, arg3);
}

static void* CreatorHLine_ctor(void* _self, va_list* app)
{
    struct CreatorHLine* self = _self;
    return self;
}

static const struct Creator _CreatorHLine = {
    {
    sizeof(struct CreatorHLine),
    CreatorHLine_ctor,
    0
    },
    "hline",
    3,
    CreatorHLine_figure_creation
};

const void* CreatorHLine = &_CreatorHLine;