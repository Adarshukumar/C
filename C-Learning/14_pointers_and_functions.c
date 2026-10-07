/* Lesson 14 — pointers as function parameters: out-params & more. Author: Adarsh */
#include <stdio.h>

void get_min_max(int *arr, int n, int *out_min, int *out_max);
void print_array(const int *arr, int n);   /* const = "I won't modify" */

int main(void) {
    /* returning MULTIPLE values: use pointer out-params */
    int data[6] = {4, -2, 9, 3, -7, 1};
    int lo, hi;
    get_min_max(data, 6, &lo, &hi);     /* pass addresses to fill in */
    printf("min=%d max=%d\n", lo, hi);

    /* const in parameters documents intent AND catches bugs: */
    print_array(data, 6);

    /* const rules:
       const int *p       -> can't modify *p (pointer to const)
       int * const p      -> can't move p (const pointer)
       const int *const p -> neither */

    /* function returning a pointer — BEWARE of returning locals: */
    /* int *bad(void) { int x = 5; return &x; }   dead stack! never! */
    /* fine: return heap memory or a static/global */

    /* pointer to const string walking: */
    const char *s = "const walk";
    while (*s) putchar(*s++);   /* allowed: *s++ READS */
    putchar('\n');

    /* Practice: refactor print_array to take (const int *start, const int *end). */
    return 0;
}

void get_min_max(int *arr, int n, int *out_min, int *out_max) {
    *out_min = *out_max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *out_min) *out_min = arr[i];
        if (arr[i] > *out_max) *out_max = arr[i];
    }
}

void print_array(const int *arr, int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}
