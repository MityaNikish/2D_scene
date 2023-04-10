#pragma once
#include "new.h"

struct Shape {
    const struct Class class;
    void (*draw)(const void* self);
};

extern const void* Shape;
void draw(const void* self);