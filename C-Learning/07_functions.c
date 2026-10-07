/* Lesson 07 — functions: prototypes, pass by VALUE, recursion. Author: Adarsh */
#include <stdio.h>

/* prototype: declare before use so main can call it */
int add(int a, int b);
void swap_fail(int a, int b);          /* won't work — see why below */
void swap(int *a, int *b);             /* pointer version WORKS */
int factorial(int n);

int main(void) {
    printf("%d\n", add(2, 3));

    /* C is PASS BY VALUE — functions get COPIES: */
    int x = 1, y = 2;
    swap_fail(x, y);
    printf("after swap_fail: x=%d y=%d (unchanged!)\n", x, y);
    swap(&x, &y);                       /* pass ADDRESSES instead */
    printf("after swap:      x=%d y=%d\n", x, y);

    printf("5! = %d\n", factorial(5));
    return 0;
}

int add(int a, int b) { return a + b; }

void swap_fail(int a, int b) {
    int t = a; a = b; b = t;            /* swaps the COPIES — caller sees nothing */
}

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;        /* dereference: swap the REAL variables */
}

int factorial(int n) {
    if (n <= 1) return 1;               /* base case — mandatory! */
    return n * factorial(n - 1);        /* recursion: each call gets own frame */
}

/* Key ideas:
   - every parameter is a copy; & (address-of) + * (dereference) is how you
     reach back into the caller's data
   - no nested functions, no default parameters (unlike C++)
   - void means "no value"; use it for functions with no return */
