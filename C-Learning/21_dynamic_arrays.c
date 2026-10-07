/* Lesson 21 — build a growable array (like vector<T>/list). Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;        /* elements in use */
    size_t capacity;    /* allocated slots */
} IntVec;

IntVec vec_new(void) { return (IntVec){NULL, 0, 0}; }

int vec_push(IntVec *v, int value) {
    if (v->size == v->capacity) {
        size_t new_cap = v->capacity ? v->capacity * 2 : 4;   /* double */
        int *tmp = realloc(v->data, new_cap * sizeof(int));
        if (!tmp) return -1;          /* OOM: old data still valid */
        v->data = tmp;
        v->capacity = new_cap;
    }
    v->data[v->size++] = value;
    return 0;
}

int vec_get(const IntVec *v, size_t i) {
    if (i >= v->size) { fprintf(stderr, "out of range\n"); exit(1); }
    return v->data[i];
}

void vec_free(IntVec *v) { free(v->data); *v = vec_new(); }

int main(void) {
    IntVec v = vec_new();
    for (int i = 1; i <= 10; i++)
        if (vec_push(&v, i * i) != 0) return 1;

    printf("size=%zu cap=%zu\n", v.size, v.capacity);
    for (size_t i = 0; i < v.size; i++) printf("%d ", vec_get(&v, i));
    printf("\n");

    /* amortized O(1) appends: doubling means each element copies ~once
       on average over the whole growth sequence */

    vec_free(&v);
    printf("freed, size=%zu\n", v.size);

    /* This is EXACTLY what dynamic arrays are in every language:
       Python list, JS array, C++ vector — same trick, hidden. */

    /* Practice: add vec_pop, vec_insert(v, idx, val) and vec_remove(v, idx). */
    return 0;
}
