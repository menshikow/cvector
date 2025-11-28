#include "cvector.h"
#include <stdio.h>
#include <string.h>

int main() {
    Vec v;
    int result;

    // --- Test vec_init ---
    result = vec_init(&v, sizeof(int));
    if (result != VEC_OK) {
        printf("vec_init failed\n");
        return 1;
    }
    printf("vec_init passed\n");

    // --- Test vec_push_back ---
    int nums[] = {10, 20, 30};
    for (int i = 0; i < 3; i++) {
        if (vec_push_back(&v, &nums[i]) != VEC_OK) {
            printf("vec_push_back failed\n");
            return 1;
        }
    }
    printf("vec_push_back passed\n");

    // --- Test vec_size and vec_capacity ---
    if (vec_size(&v) != 3) {
        printf("vec_size failed\n");
        return 1;
    }
    if (vec_capacity(&v) < 3) {
        printf("vec_capacity failed\n");
        return 1;
    }
    printf("vec_size & vec_capacity passed\n");

    // --- Test vec_get ---
    for (size_t i = 0; i < vec_size(&v); i++) {
        int *val = (int *) vec_get(&v, i);
        if (!val || *val != nums[i]) {
            printf("vec_get failed at index %zu\n", i);
            return 1;
        }
    }
    printf("vec_get passed\n");

    // --- Test vec_pop_copy ---
    int last;
    if (vec_pop_copy(&v, &last) != VEC_OK || last != 30) {
        printf("vec_pop_copy failed\n");
        return 1;
    }
    if (vec_size(&v) != 2) {
        printf("vec_pop_copy did not reduce size\n");
        return 1;
    }
    printf("vec_pop_copy passed\n");

    // --- Test vec_reserve ---
    size_t old_cap = vec_capacity(&v);
    if (vec_reserve(&v, 100) != VEC_OK) {
        printf("vec_reserve failed\n");
        return 1;
    }
    if (vec_capacity(&v) < 100) {
        printf("vec_reserve did not increase capacity\n");
        return 1;
    }
    printf("vec_reserve passed\n");

    // --- Test vec_shrink_to_fit ---
    if (vec_shrink_to_fit(&v) != VEC_OK) {
        printf("vec_shrink_to_fit failed\n");
        return 1;
    }
    if (vec_capacity(&v) != vec_size(&v)) {
        printf("vec_shrink_to_fit did not shrink properly\n");
        return 1;
    }
    printf("vec_shrink_to_fit passed\n");

    // --- Test vec_deinit ---
    vec_deinit(&v);
    if (v.data != NULL || v.size != 0 || v.capacity != 0) {
        printf("vec_deinit failed\n");
        return 1;
    }
    printf("vec_deinit passed\n");

    printf("All tests passed!\n");
    return 0;
}
