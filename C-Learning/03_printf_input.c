/* Lesson 03 — printf format codes and scanf input. Author: Adarsh */
#include <stdio.h>

int main(void) {
    /* format specifiers: %d int, %f double(float), %c char, %s string,
       %zu sizeof, %p pointer, %x hex, %o octal, %% a literal percent */
    printf("%d %c %s %f %x\n", 42, 'A', "text", 3.14, 255);

    /* width, precision, flags */
    printf("[%5d]\n", 42);        /* pad to width 5:    [   42] */
    printf("[%-5d]\n", 42);       /* left-align:        [42   ] */
    printf("[%05d]\n", 42);       /* zero-pad:          [00042] */
    printf("[%.2f]\n", 3.14159);  /* 2 decimals:        [3.14] */
    printf("[%8.2f]\n", 3.14159); /* width + precision  [   3.14] */

    /* reading input with scanf — MUST pass ADDRESSES (&) */
    int age;
    char name[50];                       /* fixed buffer, see lesson 09 */
    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {        /* scanf returns matches found */
        printf("that was not a number\n");
        return 1;
    }
    printf("You are %d years old.\n", age);

    /* %s stops at whitespace. For full lines: */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);   /* flush the newline */
    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        printf("Hello, %s", name);        /* fgets keeps the \n */
    }

    return 0;
}

/* scanf is sharp-edged (bad input poisons the buffer) — fine for learning,
   real programs use fgets + strtol/sscanf. Practice both. */
