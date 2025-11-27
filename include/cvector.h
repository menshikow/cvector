#ifndef CVECTOR_CVECTOR_H
#define CVECTOR_CVECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*
 *
 */
typedef struct {
    void *data;          // pointer to the start of the contiguous memory block
    size_t size;         // current number of elements
    size_t capacity;     // total number of elements that can fit
    size_t element_size; // the size in bytes of a single element
} CVector;

/*
 *
 */
CVector* cvec_create(size_t initial_capacity, size_t element_size);

/*
 *
 */
void cvec_destroy(CVector *vec);

/*
 *
 */
bool cvec_push(CVector *vec, void *element);

/*
 *
 */
void* cvec_pop(CVector *vec);

/*
 *
 */
void* cvec_get(CVector *vec, size_t index);

#endif //CVECTOR_CVECTOR_H