/* Lesson 15 — double pointers (int **): pointers by reference. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

/* allocate INSIDE a function: the caller's pointer must be modified,
   so pass a POINTER TO that pointer */
int make_array(int **out, size_t n) {
    int *tmp = malloc(n * sizeof(int));
    if (tmp == NULL) return -1;         /* error code instead of crashing */
    for (size_t i = 0; i < n; i++) tmp[i] = (int)(i * i);
    *out = tmp;                          /* write through: caller's var now set */
    return 0;
}

int main(void) {
    int x = 42;
    int *p = &x;
    int **pp = &p;                       /* pp -> p -> x */

    printf("%d %d %d\n", x, *p, **pp);   /* all 42 */
    **pp = 7;                            /* changes x through both levels */
    printf("x is now %d\n", x);

    /* the canonical use: functions that ALLOCATE for you */
    int *nums = NULL;
    if (make_array(&nums, 5) != 0) {     /* & of my pointer */
        fprintf(stderr, "allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) printf("%d ", nums[i]);
    printf("\n");
    free(nums);

    /* why not just return the pointer? style choice — error codes via
       return + data via out-param scales better in real APIs */

    /* argv IS a char** — an array of string pointers:
       main(int argc, char **argv) : argv[0]=program, argv[1]=first arg */

    /* 2D-ish layouts: array of pointers (rows can differ in length) */
    int row0[3] = {1, 2, 3}, row1[2] = {4, 5};
    int *rows[2] = {row0, row1};
    printf("%d %d\n", rows[0][2], rows[1][1]);

    /* Practice: rewrite make_array to also report the size via an out-param. */
    return 0;
}
