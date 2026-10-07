/* Lesson 02 — variables and the core types. Author: Adarsh */
#include <stdio.h>

int main(void) {
    int age = 21;                 /* signed int, >= 16 bits (usually 32) */
    long long big = 9000000000LL; /* at least 64 bits */
    float price = 9.99f;          /* ~7 digits precision */
    double precise = 3.14159265358979;  /* ~15 digits — default choice */
    char grade = 'A';             /* single byte: a character CODE */
    _Bool ok = 1;                 /* or use <stdbool.h> bool/true/false */

    printf("%d %lld %.2f %.10f %c\n", age, big, price, precise, grade);

    /* unsigned: no negatives, double the positive range */
    unsigned int distance = 4000000000u;
    printf("%u\n", distance);

    /* sizes are platform-dependent — print them, don't memorize */
    printf("short=%zu int=%zu long=%zu long long=%zu\n",
           sizeof(short), sizeof(int), sizeof(long), sizeof(long long));

    /* overflow wraps silently — classic C surprise: */
    unsigned char tiny = 255;
    tiny = tiny + 1;              /* wraps to 0! */
    printf("255 + 1 = %d (wrapped)\n", tiny);

    /* int limits live in <limits.h>, float limits in <float.h> */
    printf("int max: %d\n", 2147483647);

    /* const: cannot be reassigned */
    const double GRAVITY = 9.81;

    /* integers have NO default initialization — this is garbage: */
    int garbage;                  /* uninitialized = random stack value */
    printf("%d %f\n", garbage, GRAVITY);

    return 0;
}

/* Practice: print the size of every type on YOUR machine. */
