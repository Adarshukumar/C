/* Lesson 26 — function pointers: behavior as data. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
int sub(int a, int b) { return a - b; }

/* callbacks: pass behavior INTO a function */
int apply(int (*op)(int, int), int a, int b) {   /* parameter is a fn ptr */
    return op(a, b);
}

/* qsort — THE standard-library showcase (needs comparisons as callbacks) */
int compare_ints(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);            /* -1, 0, 1 — no overflow risk */
}

typedef int (*BinOp)(int, int);          /* typedef makes it readable */

int main(void) {
    /* declare, assign, call — note the (*name)(params) shape */
    int (*op)(int, int) = add;
    printf("%d\n", op(2, 3));            /* call through the pointer */
    op = mul;
    printf("%d\n", op(2, 3));

    /* dispatch table — the classic replacement for switch statements */
    BinOp ops[3] = {add, sub, mul};
    const char *names[3] = {"add", "sub", "mul"};
    for (int i = 0; i < 3; i++)
        printf("%s(10,3) = %d\n", names[i], ops[i](10, 3));

    /* callbacks in action: */
    printf("apply: %d %d\n", apply(add, 7, 2), apply(mul, 7, 2));

    /* qsort with our comparator: */
    int arr[6] = {42, 7, 19, 3, 88, 1};
    qsort(arr, 6, sizeof(int), compare_ints);
    for (int i = 0; i < 6; i++) printf("%d ", arr[i]);
    printf("\n");

    /* descending? flip the comparison: */
    int compare_desc(const void *a, const void *b);   /* prototype */
    qsort(arr, 6, sizeof(int), compare_desc);
    for (int i = 0; i < 6; i++) printf("%d ", arr[i]);
    printf("\n");

    /* read it right-to-left:
       int (*fp)(int,int)  : fp is a POINTER to function(int,int)->int
       int *fp(int,int)    : fp is a FUNCTION returning int* (different!) */

    /* Practice: map(int *arr, int n, int (*fn)(int)) applying fn to each. */
    return 0;
}

int compare_desc(const void *a, const void *b) {
    return compare_ints(b, a);            /* reuse by swapping args */
}
