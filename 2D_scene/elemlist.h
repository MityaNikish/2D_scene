#pragma once
#include "new.h" 

typedef struct _Tokens {
    char name[10];
    int arg[4];
} Tokens;

struct WrapContainer {
    const struct Class class;
    int size;
    Tokens* elem_vector;
};

void* push(struct WrapContainer* _self, const Tokens* tok);

extern const void* _WrapContainer;