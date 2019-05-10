#pragma once

// free the p and set to NULL.
// p must be a T*.
#define safe_freep(p) \
    if (p) { \
        delete p; \
        p = NULL; \
    } \
    (void)0

// please use the safe_freepa(T[]) to free an array,
// or the behavior is undefined.
#define safe_freepa(pa) \
    if (pa) { \
        delete[] pa; \
        pa = NULL; \
    } \
    (void)0
