/* Lesson 29 — the bugs that will find you (learn to recognize them). Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    /* 1) OFF-BY-ONE: <= in a < loop */
    int a[5] = {0};
    for (int i = 0; i <= 5; i++) { /* i==5 writes PAST the end! */
        if (i < 5) a[i] = i;       /* (guarded here so the demo runs clean) */
    }
    printf("rule: n elements -> indices 0..n-1\n");

    /* 2) UNINITIALIZED reads: garbage now, mystery crash later */
    int total;
    /* printf("%d\n", total); <- UB. Always init: int total = 0; */

    /* 3) USE-AFTER-FREE */
    int *p = malloc(sizeof(int));
    *p = 42;
    free(p);
    /* *p = 7;  <- UB! */ p = NULL;

    /* 4) DOUBLE FREE */
    /* free(p); free(p); <- crash. NULL after free makes free(NULL) safe. */

    /* 5) MEMORY LEAK: losing the last pointer to heap memory */
    /* for (;;) { malloc(1024); }  <- RAM gone. valgrind finds these. */

    /* 6) DANGLING POINTER TO STACK LOCAL */
    /* int *bad(void) { int x = 5; return &x; }  <- dead on return */

    /* 7) BUFFER OVERFLOW via strcpy/gets */
    char dst[8];
    /* strcpy(dst, "way longer than eight characters"); <- OVERFLOW */
    strncpy(dst, "safe", sizeof dst - 1); dst[sizeof dst - 1] = '\0';
    /* gets() is REMOVED from the standard — fgets forever */

    /* 8) INTEGER DIVISION surprise: 5/2 == 2, not 2.5 */
    printf("%d vs %.1f\n", 5 / 2, 5 / 2.0);

    /* 9) = vs == inside if */
    int mode = 0;
    if (mode == 1) {}          /* correct */
    /* if (mode = 1) {}  <- assigns, always truthy! gcc -Wall warns */

    /* 10) STRING != comparison: strcmp, never == */
    char word[] = "yes";
    if (word == "yes") printf("never true: different pointers\n");
    if (strcmp(word, "yes") == 0) printf("strcmp works\n");

    /* 11) sizeof on a pointer parameter (got the POINTER size, not array) */
    /* inside f(int arr[]): sizeof arr == 8, NOT the array length! */

    /* 12) returning addresses of locals, forgetting realloc can MOVE,
           signed overflow, assuming struct layout... the list goes on. */

    /* Your defenses: -Wall -Wextra -g, sanitizers, valgrind, small tests. */
    printf("stay paranoid, stay compiling clean\n");
    return 0;
}
