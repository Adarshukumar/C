/* Lesson 24 — the preprocessor: #define, #include, #if. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 50            /* simple object-like macro */
#define SQUARE(x) ((x) * (x))  /* function-like macro — PARENTHESES MATTER! */
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define STRINGIFY(x) #x        /* # turns the token into a string */
#define JOIN(a, b) a##b        /* ## glues tokens together */

/* conditional compilation — feature flags & portability */
#define VERBOSE 1

int main(void) {
    printf("MAX_NAME is %s = %d\n", STRINGIFY(MAX_NAME), MAX_NAME);
    printf("square 5: %d\n", SQUARE(5));
    printf("min: %d\n", MIN(3, 9));

    int joined_max_XX = 77;    /* JOIN(max_, XX) would make max_XX */
    printf("token glue: %d\n", joined_max_XX);

    /* the parentheses disaster, demonstrated safely:
       SQUARE(2+3) with bad macro x*x would give 2+3*2+3 = 11.
       Our ((x)*(x)) gives (2+3)*(2+3) = 25. ALWAYS parenthesize. */
    printf("%d\n", SQUARE(2 + 3));

#if VERBOSE
    printf("[verbose] detailed logging on\n");
#else
    printf("[quiet] minimal output\n");
#endif

#ifdef _WIN32
    printf("compiled on Windows\n");
#elif defined(__linux__)
    printf("compiled on Linux\n");
#elif defined(__APPLE__)
    printf("compiled on macOS\n");
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024       /* define-if-missing default */
#endif
    printf("buffer: %d\n", BUFFER_SIZE);

/* macros vs const vs inline functions:
   #define PI 3.14        -> textual, no type, no scope
   const double PI = 3.14 -> typed, scoped — prefer this
   static inline int sq(int x) { return x*x; }  -> typed — prefer this */

#undef VERBOSE
#if !defined(VERBOSE)
    printf("VERBOSE is now gone\n");
#endif

    /* Practice: macro SWAP(type, a, b) and CLAMP(v, lo, hi). */
    return 0;
}
