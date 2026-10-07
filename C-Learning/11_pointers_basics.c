/* Lesson 11 — POINTERS: the boss fight. Author: Adarsh
   A pointer is just a variable holding a MEMORY ADDRESS. That's all. */
#include <stdio.h>

int main(void) {
    int x = 42;
    int *p = &x;          /* p holds the ADDRESS of x (& = address-of) */

    printf("x     = %d   (the value)\n", x);
    printf("&x    = %p   (x's address)\n", (void *)&x);
    printf("p     = %p   (same address, stored in p)\n", (void *)p);
    printf("*p    = %d   (dereference: value AT that address)\n", *p);

    /* *p IS x — write through the pointer changes x: */
    *p = 99;
    printf("x is now %d\n", x);

    /* p itself can be reassigned: */
    int y = 7;
    p = &y;
    printf("*p = %d now\n", *p);

    /* NULL = "points to nothing". Check before dereferencing: */
    int *q = NULL;
    if (q == NULL) printf("q points nowhere (safe to check!)\n");
    /* *q would crash — null dereference, the most famous C crash */

    /* uninitialized pointers hold GARBAGE addresses: */
    int *bad;             /* NEVER dereference without assigning first */
    printf("bad=%p (garbage)\n", (void *)bad);

    /* sizes: a pointer is just an address (8 bytes on 64-bit), no matter
       what it points to: */
    printf("%zu %zu %zu\n", sizeof(int *), sizeof(char *), sizeof(double *));

    /* read declarations right-to-left:
       int *p        : p is a pointer to int
       int **pp      : pp is a pointer to a pointer to int
       int *arr[5]   : arr is an array of 5 pointers to int
       int (*p)[5]   : p is a pointer to an array of 5 ints */

    /* Practice: draw box-and-arrow diagrams of x, p, and *p on paper. */
    return 0;
}
