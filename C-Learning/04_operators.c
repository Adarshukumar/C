/* Lesson 04 — operators. Author: Adarsh */
#include <stdio.h>

int main(void) {
    int a = 7, b = 3;
    printf("%d %d %d %d %d %d\n", a + b, a - b, a * b, a / b, a % b, a * b);

    /* INTEGER DIVISION truncates: 7 / 3 == 2 (not 2.33!) */
    printf("7/3=%d but 7.0/3=%.4f\n", a / b, 7.0 / b);

    /* ++ and -- : pre vs post (same as JS) */
    int i = 5;
    printf("%d ", i++);   /* prints 5, then i becomes 6 */
    printf("%d\n", ++i);  /* i becomes 7, prints 7 */

    /* comparisons give 1 (true) or 0 (false) */
    printf("%d %d %d\n", a > b, a == b, a != b);

    /* logical: && || ! — with SHORT CIRCUIT evaluation */
    int x = 0;
    if (x != 0 && 10 / x > 1) printf("never runs: short-circuit saved us\n");

    /* bitwise — C's specialty: & | ^ ~ << >> */
    printf("%d %d %d\n", 6 & 3, 6 | 3, 6 ^ 3);   /* 2 7 5 */
    printf("1<<4=%d 256>>3=%d\n", 1 << 4, 256 >> 3); /* 16 32 */

    /* assignment shortcuts */
    int n = 10;
    n += 5; n <<= 1; n &= 0xF;
    printf("n=%d\n", n);

    /* ternary */
    int max = (a > b) ? a : b;
    printf("max=%d\n", max);

    /* comma operator + sizeof */
    printf("size of 3.14: %zu\n", sizeof 3.14);

    /* operator precedence: don't memorize — use parentheses */
    printf("%d\n", (a + b) * 2);

    /* Practice: swap two variables WITHOUT a temp (use ^) — see lesson 27. */
    return 0;
}
