#ifndef PHPSCI_EXT_ASSIGN_H
#define PHPSCI_EXT_ASSIGN_H
#include "carray.h"

/*
 * return true if pointer is aligned to 'alignment'
 */
static inline int
carray_is_aligned(const void * p, const int alignment)
{
    /*
     * Assumes alignment is a power of two, as required by the C standard.
     * Assumes cast from pointer to unsigned integer gives a sensible representation we
     * can use bitwise & on (not required by C standard, but used by glibc).
     */
    return ((uintptr_t)(p) & ((alignment) - 1)) == 0;
}

int IsAligned(CArray *array);

#endif //PHPSCI_EXT_ASSIGN_H