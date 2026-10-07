/* Lesson 05 — if/else and switch. Author: Adarsh */
#include <stdio.h>

int main(void) {
    int temp = 31;

    if (temp > 35)      printf("Very hot\n");
    else if (temp > 25) printf("Warm\n");      /* this one runs */
    else if (temp > 10) printf("Cool\n");
    else                printf("Cold\n");

    /* == vs = — THE classic C bug: */
    int x = 5;
    if (x == 10) printf("no\n");       /* comparison */
    /* if (x = 10)  */                  /* assigns! truthy! compiles fine! */
    /* gcc warns with -Wall: "suggest parentheses around assignment" */
    /* trick: write constants first — if (10 == x) */

    /* switch: integer/char cases only, break required */
    char grade = 'B';
    switch (grade) {
        case 'A': printf("excellent\n"); break;
        case 'B': printf("good\n");      break;
        case 'C': printf("okay\n");
        case 'D': printf("pass-ish\n");  break;  /* fall-through on purpose: C shows "okay\npass-ish" */
        default:  printf("see me\n");
    }

    /* switch on ranges? C can't — use if/else. Fall-through grouping: */
    int month = 7;
    switch (month) {
        case 12: case 1: case 2:
            printf("winter\n"); break;
        case 6: case 7: case 8:
            printf("summer\n"); break;
        default:
            printf("in between\n");
    }

    /* ternary as an expression (C has no ternary chains limit) */
    int score = 74;
    const char *status = score >= 50 ? "pass" : "fail";
    printf("%s\n", status);

    /* goto exists — used for error cleanup in Linux kernels, else avoid */
    int err = 1;
    if (err) goto cleanup;
    printf("unreachable\n");
cleanup:
    printf("cleanup ran\n");

    /* Practice: convert a numeric grade 0-100 to A/B/C/D/F using switch on
       score/10 (integer division trick). */
    return 0;
}
