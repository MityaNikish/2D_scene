#pragma once
#include "shape.h"

struct Point {
    struct Shape shape;
    int x, y;
};

extern const void* Point;