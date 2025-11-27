#include "../include/cvector.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* Return codes:
   VEC_OK = 0
   VEC_ERR_ALLOC = 1
*/

int vec_init(Vec *v, size_t elem_size) {
    v->size = 0;
    v->capacity = 10;
    v->elem_size = elem_size;
    v->data = malloc(elem_size * v->capacity);
    if (v->data == NULL) {
        return VEC_ERR_OOB;
    }
    return VEC_OK;
}

int vec_push_back(Vec *v, const void *element) {
    if (v->capacity == v->size) {
        v->capacity *= 2;

        void *tmp = realloc(v->data, v->capacity * v->elem_size);
        if (tmp == NULL) {
            return VEC_ERR_OOB;
        }
        v->data = tmp;
    }

    // copy element bytes into the correct offset
    memcpy((char *)v->data + v->size * v->elem_size,
           element,
           v->elem_size);

    v->size++;
    return VEC_OK;
}
