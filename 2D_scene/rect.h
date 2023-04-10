#pragma once
#include "shape.h"
#include "point.h"

struct Rect {
    struct Shape shape;
    struct Point start_point;
    struct Point end_point;
};

extern const void* Rect;