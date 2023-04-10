#include <string.h>
#include <stdlib.h>
#include "elemlist.h"

static void* ElemList_ctor(void* _self, va_list* app)
{
    struct WrapContainer* self = _self;
    self->size = va_arg(*app, int);
    self->elem_vector = (Tokens*)calloc(sizeof(Tokens), self->size);
    if (self->elem_vector == NULL) {
        return NULL;
    }
    return self;
}

static void* ElemList_dtor(void* _self)
{
    struct WrapContainer* self = _self;
    free(self->elem_vector);
    return self;
}

void* push(struct WrapContainer* _self, const Tokens* tok) {
    struct WrapContainer* self = _self;
    void* temp_elem_vector = (Tokens*)realloc(self->elem_vector, sizeof(Tokens) * (self->size + 1));
    if (temp_elem_vector != NULL) {
        self->elem_vector = temp_elem_vector;
        ++self->size;
        memcpy(self->elem_vector + (self->size - 1), tok, sizeof(Tokens));
        return self->elem_vector;
    }
    return NULL;
}


static const struct Class _ElemList = {
    sizeof(struct WrapContainer),
    ElemList_ctor,
    ElemList_dtor
};

const void* _WrapContainer = &_ElemList;
