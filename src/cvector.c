#include "cvector.h"
#include <stdlib.h>
#include <string.h>

int vec_init(Vec *v, size_t elem_size) {
  v->size = 0;
  v->capacity = 10;
  v->elem_size = elem_size;
  v->data = malloc(elem_size * v->capacity);
  if (!v->data)
    return VEC_ERR_ALLOC;
  return VEC_OK;
}

void vec_deinit(Vec *v) {
  free(v->data);
  v->data = NULL;
  v->size = 0;
  v->capacity = 0;
}

int vec_push_back(Vec *v, const void *elem) {
  if (v->size == v->capacity) {
    size_t new_cap = v->capacity * 2;
    void *tmp = realloc(v->data, new_cap * v->elem_size);
    if (!tmp)
      return VEC_ERR_ALLOC;
    v->data = tmp;
    v->capacity = new_cap;
  }
  memcpy((char *)v->data + v->size * v->elem_size, elem, v->elem_size);
  v->size++;
  return VEC_OK;
}

int vec_reserve(Vec *v, size_t new_cap) {
  if (v->capacity >= new_cap)
    return VEC_OK;
  void *tmp = realloc(v->data, new_cap * v->elem_size);
  if (!tmp)
    return VEC_ERR_ALLOC;
  v->data = tmp;
  v->capacity = new_cap;
  return VEC_OK;
}

int vec_shrink_to_fit(Vec *v) {
  if (v->size == 0) {
    free(v->data);
    v->data = NULL;
    v->capacity = 0;
    return VEC_OK;
  }
  void *tmp = realloc(v->data, v->size * v->elem_size);
  if (!tmp)
    return VEC_ERR_ALLOC;
  v->data = tmp;
  v->capacity = v->size;
  return VEC_OK;
}

void *vec_get(const Vec *v, size_t index) {
  if (index >= v->size)
    return NULL;
  return (char *)v->data + index * v->elem_size;
}

int vec_pop_copy(Vec *v, void *out) {
  if (v->size == 0)
    return VEC_ERR_OOB;
  v->size--;
  if (out) {
    void *elem_ptr = (char *)v->data + v->size * v->elem_size;
    memcpy(out, elem_ptr, v->elem_size);
  }
  return VEC_OK;
}

size_t vec_size(const Vec *v) { return v->size; }

size_t vec_capacity(const Vec *v) { return v->capacity; }
