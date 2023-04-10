#pragma once
#include "new.h"

struct Creator {
    const struct Class _class;
    const char* name;
    const int number_of_args;
    void* (*figure_creation)(const void* self, va_list* app);
};

extern const void* Creator;
void* figure_creation(const void* self, ...);