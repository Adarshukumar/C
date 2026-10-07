/* Lesson 16 — malloc, calloc, realloc, free. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* malloc: raw bytes, UNINITIALIZED garbage */
    int *a = malloc(5 * sizeof(int));
    if (!a) { perror("malloc"); return 1; }
    for (int i = 0; i < 5; i++) a[i] = i * 10;

    /* calloc: zero-initialized AND takes (count, size) */
    int *z = calloc(5, sizeof(int));       /* all zeros, guaranteed */
    if (!z) { free(a); return 1; }

    /* realloc: grow/shrink — MAY MOVE the block! */
    int *bigger = realloc(a, 10 * sizeof(int));
    if (!bigger) { free(a); free(z); return 1; }   /* old block still valid! */
    for (int i = 5; i < 10; i++) bigger[i] = i * 10;

    for (int i = 0; i < 10; i++) printf("%d ", bigger[i]);
    printf("\nzeros: %d %d\n", z[0], z[4]);

    /* realloc shrinks in place usually: */
    int *smaller = realloc(bigger, 2 * sizeof(int));
    printf("shrink same spot: %d\n", smaller == bigger ? 1 : 0);

    /* THE RULES:
       1. every malloc/calloc/realloc needs exactly one free
       2. free(NULL) is safe and does nothing
       3. use-after-free / double-free = undefined behavior
       4. after free, NULL the pointer (protects later accidents)
       5. sizeof(*p) instead of sizeof(type) — survives type changes:
          int *v = malloc(n * sizeof(*v));                        */

    free(smaller);
    smaller = NULL;
    free(z);
    z = NULL;
    printf("clean exit\n");

    /* Memory leaks hide in error paths — the pattern pros use:
       allocate -> on error goto cleanup -> free everything at the end */

    /* Practice: dynamic int array that grows by doubling; append 1..100. */
    return 0;
}
