#pragma once
#include <stddef.h>
#include <stdarg.h>

struct Class {
    size_t size;
    void* (*ctor)(void* self, va_list* app);
    void* (*dtor)(void* self);
};

void* new(const void* class, ...);
void delete(void* item);