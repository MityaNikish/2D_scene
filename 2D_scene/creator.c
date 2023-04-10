#include <assert.h>
#include "creator.h"
#include "new.h"

void* figure_creation(const void* self, ...)
{
    const struct Creator* cp = self;
    assert(self && cp && cp->figure_creation);
    va_list ap;
    va_start(ap, self);
    void* obj = cp->figure_creation(self, &ap);
    va_end(ap);
    return obj;
}
