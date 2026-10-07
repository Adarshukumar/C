/* Lesson 17 — where variables actually live. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

int global_init = 42;        /* .data  — initialized globals */
int global_zero;             /* .bss   — zero-initialized globals */
const char msg[] = "rodata"; /* .rodata — read-only */

void stack_frame(void) {
    int local = 1;           /* stack — dies when function returns */
    printf("stack local at %p\n", (void *)&local);
}

int main(void) {
    printf("code   (text)   : %p\n", (void *)main);
    printf("rodata          : %p\n", (void *)msg);
    printf(".data (init)    : %p\n", (void *)&global_init);
    printf(".bss  (zeroed)  : %p\n", (void *)&global_zero);

    int on_stack = 5;
    int *on_heap = malloc(sizeof(int));
    printf("stack grows down: %p\n", (void *)&on_stack);
    printf("heap  grows up  : %p\n", (void *)on_heap);
    free(on_heap);

    stack_frame();
    stack_frame();           /* SAME address — frame reused! */

    /* THE MAP (low -> high addresses):
       [ text | rodata | data | bss | ...heap grows up... ...stack grows down ]
       - text/rodata: read-only (writing = segfault)
       - data/bss: globals, live for the whole program
       - heap: malloc territory, you manage it
       - stack: locals, automatic, limited (default ~1-8MB) */

    /* stack overflow — the infinite recursion crash: */
    /* void boom(void) { int x[1000]; boom(); } */

    /* sizeof a pointer vs the thing pointed to: */
    int arr[10];
    printf("array=%zu ptr=%zu int=%zu\n", sizeof arr, sizeof(int *), sizeof(int));

    /* Practice: print &local in main and in a called function — see the
       distance between stack frames. */
    return 0;
}
