#include <assert.h>
#include "shape.h"
#include "new.h"

void draw(const void* self)
{
    const struct Shape* cp = self;
    assert(self && cp && cp->draw);
    cp->draw(self);
}

static void* Shape_ctor(void* _self, void* app)
{
    struct Shape* self = _self;
    return self;
}

static const struct Class _Shape = {
    sizeof(struct Shape),       // size
    Shape_ctor,                 // ctor
    0                           // dtor
};

const void* Shape = &_Shape;
