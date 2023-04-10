#pragma once
#include "shape.h"
#include "rect.h"

struct Vline {
    struct Shape shape;
    struct Point start_point;
    struct Point end_point;
};

extern const void* Vline;