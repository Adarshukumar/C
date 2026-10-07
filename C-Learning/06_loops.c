/* Lesson 06 — loops: for, while, do-while. Author: Adarsh */
#include <stdio.h>

int main(void) {
    /* for: init; condition; update */
    for (int i = 0; i < 5; i++) printf("%d ", i);
    printf("\n");

    /* countdown with two variables */
    for (int i = 0, j = 10; i < j; i++, j--)
        printf("(%d,%d) ", i, j);
    printf("\n");

    /* while: check first */
    int n = 3;
    while (n > 0) printf("%d ", n--);
    printf("\n");

    /* do-while: runs AT LEAST once (menu loops love this) */
    int choice = 0;
    do {
        choice++;
        printf("menu iteration %d\n", choice);
    } while (choice < 2);

    /* break / continue */
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) continue;   /* skip evens */
        if (i > 7) break;           /* stop past 7 */
        printf("%d ", i);
    }
    printf("\n");

    /* nested: multiplication table */
    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col <= 3; col++)
            printf("%3d", row * col);
        printf("\n");
    }

    /* C has no labeled break — use a flag or goto */
    int found = 0;
    int grid[2][2] = {{1, 2}, {3, 4}};
    for (int r = 0; r < 2 && !found; r++)
        for (int c = 0; c < 2; c++)
            if (grid[r][c] == 3) { found = 1; break; }
    printf("found=%d\n", found);

    /* infinite loop + break is idiomatic for servers */
    int ticks = 0;
    for (;;) {
        if (++ticks >= 2) break;
    }
    printf("ticked %d times\n", ticks);

    /* Practice: print all prime numbers below 50. */
    return 0;
}
