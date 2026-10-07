/* Lesson 12 — pointers and arrays are best friends. Author: Adarsh */
#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;         /* array DECAYS to &arr[0] here — no & needed */

    /* these are ALL the same element: */
    printf("%d %d %d %d\n", arr[2], *(arr + 2), p[2], *(p + 2));

    /* indexing IS pointer arithmetic in disguise: arr[i] == *(arr + i) */

    /* walk with a pointer */
    for (int *q = arr; q < arr + 5; q++) printf("%d ", *q);
    printf("\n");

    /* pointer arithmetic scales by ELEMENT SIZE: */
    printf("p=%p p+1=%p (diff %zu bytes = one int)\n",
           (void *)p, (void *)(p + 1), sizeof(int));

    /* arrays decay in functions — size info is LOST: */
    printf("in main: %zu bytes\n", sizeof arr);       /* 20 */
    printf("decay test: %zu\n", sizeof (arr + 0));    /* 8 — it's a pointer now */

    /* this is why C functions take (arr, len) pairs: */
    double prices[] = {9.99, 19.99, 4.50};
    double total = 0;
    for (size_t i = 0; i < sizeof prices / sizeof prices[0]; i++)
        total += prices[i];
    printf("total: %.2f\n", total);

    /* &arr vs arr — same address, different TYPES:
       arr    -> int*      (pointer to first element)
       &arr   -> int(*)[5] (pointer to the whole array) */

    /* string walking with pointers (lesson 09 revisited): */
    char *s = "walk";
    while (*s) putchar(*s++);   /* prints until NUL */
    putchar('\n');

    /* Practice: write arr_sum(int *a, int n) using ONLY pointer movement. */
    return 0;
}
