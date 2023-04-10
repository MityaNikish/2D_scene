#pragma once
#include "creator.h"

struct CreatorPoint {
    const struct Creator creator;
};

struct CreatorRect {
    const struct Creator creator;
};

struct CreatorHLine {
    const struct Creator creator;
};

struct CreatorVLine {
    const struct Creator creator;
};

extern const void* CreatorPoint;
extern const void* CreatorRect;
extern const void* CreatorHLine;
extern const void* CreatorVLine;