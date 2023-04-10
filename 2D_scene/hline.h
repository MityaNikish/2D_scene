#pragma once
#include "shape.h"
#include "Point.h"

struct Hline {
    struct Shape shape;
    struct Point start_point;
    struct Point end_point;
};

extern const void* Hline;