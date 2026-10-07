/* Lesson 28 — const, volatile, restrict — type qualifiers. Author: Adarsh */
#include <stdio.h>

void print_data(const int *data, int n) {   /* promise: read-only use */
    /* data[0] = 5;  <- compile error: const protects callers */
    for (int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n");
}

int main(void) {
    /* const fundamentals */
    const int fixed = 42;
    /* fixed = 7; */                       /* error */

    /* the four pointer flavors — read RIGHT to LEFT: */
    int x = 1, y = 2;
    const int *p1 = &x;        /* pointer to const int: can't write *p1 */
    int *const p2 = &x;        /* const pointer: can't move p2 */
    const int *const p3 = &x;  /* neither */
    const int *p4 = &x;        /* same type as p1 */

    p1 = &y;                   /* fine: pointer moves */
    /* *p1 = 9; */             /* error: pointee const */
    *p2 = 9;                   /* fine: pointee writable */
    /* p2 = &y; */             /* error: pointer const */
    (void)p3; (void)p4;
    printf("x=%d y=%d\n", x, y);

    /* const arrays (common in real code): */
    const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("feb: %d\n", days_in_month[1]);
    print_data(days_in_month, 12);

    /* string literals + const: */
    const char *s = "read-only";           /* writing s[0] = UB */

    /* volatile: "value may change without my code doing it"
       — hardware registers, variables shared with signal handlers */
    volatile int *hardware_reg = (volatile int *)0x0;  /* illustrative only */
    (void)hardware_reg;
    /* without volatile, the compiler might cache reads and DELETE
       your loop: while (*hardware_reg == 0) {} */

    /* restrict: "only THIS pointer accesses this data" (optimization hint) */
    void my_memcpy(unsigned char *restrict dst, const unsigned char *restrict src, int n) {
        for (int i = 0; i < n; i++) dst[i] = src[i];
    }
    unsigned char buf[4] = {1, 2, 3, 4}, out[4];
    my_memcpy(out, buf, 4);
    printf("copied: %u %u\n", out[0], out[3]);

    /* Practice: mark every parameter in your earlier lessons const-correctly. */
    return 0;
}
