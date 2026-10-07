/* Lesson 10 — scope and storage classes. Author: Adarsh */
#include <stdio.h>

int counter = 0;          /* GLOBAL: lives for the whole program */

void bump(void) {
    counter++;            /* globals are visible everywhere — use sparingly */
}

void demo_static(void) {
    static int calls = 0; /* static local: initialized ONCE, survives calls */
    calls++;
    printf("static calls: %d\n", calls);
}

void demo_auto(void) {
    int fresh = 0;        /* automatic: recreated (and reset!) every call */
    fresh++;
    printf("auto fresh: %d\n", fresh);
}

int main(void) {
    /* block scope: inner names shadow outer ones */
    int x = 1;
    {
        int x = 2;
        printf("inner x=%d\n", x);
    }
    printf("outer x=%d\n", x);

    /* storage classes you'll actually see:
       auto      - default for locals (nobody writes it)
       static    - file-private global OR persistent local
       extern    - "this global lives in another .c file"
       const     - read-only
       volatile  - "don't optimize away" (hardware/ISR code) */

    bump(); bump(); bump();
    printf("global counter: %d\n", counter);

    demo_static(); demo_static();   /* 1, 2 — remembers! */
    demo_auto();   demo_auto();     /* 1, 1 — resets! */

    /* extern example lives in lesson 25 (multi-file projects) */

    /* Practice: make a static-in-function id generator: next_id() -> 1,2,3... */
    return 0;
}
