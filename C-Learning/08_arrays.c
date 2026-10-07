/* Lesson 08 — arrays: fixed size, no bounds checking. Author: Adarsh */
#include <stdio.h>

int main(void) {
    int nums[5] = {10, 20, 30, 40, 50};
    int partial[5] = {1, 2};            /* rest are ZERO */
    int zeros[100] = {0};               /* all zero — the idiom */

    printf("%d %d %d\n", nums[0], nums[4], partial[1]);

    /* size: sizeof gives BYTES — divide by element size */
    printf("count: %zu\n", sizeof nums / sizeof nums[0]);

    /* iterate */
    for (int i = 0; i < 5; i++) printf("%d ", nums[i]);
    printf("\n");

    /* NO BOUNDS CHECKING — C trusts you completely: */
    printf("nums[10] is garbage or crash territory: %d\n", nums[10]);
    /* gcc -fsanitize=address catches this at runtime — use it while learning */

    /* 2D arrays: row-major, literal braces */
    int grid[2][3] = {{1, 2, 3}, {4, 5, 6}};
    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) printf("%d ", grid[r][c]);
        printf("\n");
    }
    printf("grid bytes: %zu (2*3*4)\n", sizeof grid);

    /* arrays DECAY to pointers when passed to functions: */
    int arr[3] = {7, 8, 9};
    int *p = arr;                       /* same address! */
    printf("%d %d\n", arr[1], p[1]);
    printf("array size outside: %zu, pointer size: %zu\n",
           sizeof arr, sizeof p);       /* 12 vs 8 — proof they differ */

    /* char arrays initialized from strings get a NUL terminator: */
    char word[6] = "hello";             /* 5 letters + '\0' */
    printf("%s %zu\n", word, sizeof word);

    /* Practice: write sum(arr, len) — len must travel with the pointer! */
    return 0;
}
