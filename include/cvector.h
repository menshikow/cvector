#ifndef CVECTOR_H
#define CVECTOR_H

#include <stddef.h>

/* error codes */
#define VEC_OK          0 // operation succeeded
#define VEC_ERR_ALLOC   1 // memory allocation error
#define VEC_ERR_OOB     2 // index out of range

typedef struct {
    void *data; // allocated block
    size_t size; // number of elements
    size_t capacity; // number of elements allocated
    size_t elem_size; // sizeof(T)
} Vec;


/* creation / destruction */
int vec_init(Vec *vec, size_t elem_size);

void vec_deinit(Vec *vec);

/* capacity management */
int vec_reserve(Vec *v, size_t new_cap);

int vec_shrink_to_fit(Vec *v);


/* modification */
int vec_push_back(Vec *v, const void *elem);


/* accessors */
void *vec_get(Vec *v, size_t index);

size_t vec_size(const Vec *v);

size_t vec_capacity(const Vec *v);

#endif


