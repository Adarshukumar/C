/* Lesson 09 — strings are char arrays with a NUL. Author: Adarsh */
#include <stdio.h>
#include <string.h>

int main(void) {
    /* every string ends with '\0' (byte 0) — functions find the end via it */
    char s1[] = "hello";                /* size 6: h e l l o \0 */
    char s2[10] = "hi";
    char *s3 = "constant";              /* pointer to a string LITERAL (read-only!) */

    printf("%zu %zu\n", sizeof s1, strlen(s1));  /* 6 bytes vs 5 letters */

    /* the core <string.h> functions */
    char dst[20];
    strcpy(dst, "copy me");             /* dst = source (dst must be big enough!) */
    strcat(dst, " + more");             /* append */
    printf("%s (len %zu)\n", dst, strlen(dst));

    printf("cmp: %d\n", strcmp("apple", "banana"));  /* <0 since a<b */
    printf("find e: %s\n", strchr("hello", 'e'));    /* first occurrence */
    printf("needle: %s\n", strstr("hello world", "world"));

    /* safe versions with size limits — use these in real code */
    strncpy(dst, "short", sizeof dst - 1);
    dst[sizeof dst - 1] = '\0';

    /* char-by-char is the best way to *understand* strings: */
    char msg[] = "C!";
    for (int i = 0; msg[i] != '\0'; i++)
        printf("%d:'%c' ", msg[i], msg[i]);
    printf("\n");

    /* reverse in place with two indices */
    char word[] = "abcdef";
    for (int i = 0, j = (int)strlen(word) - 1; i < j; i++, j--) {
        char t = word[i]; word[i] = word[j]; word[j] = t;
    }
    printf("reversed: %s\n", word);

    /* string literals live in read-only memory — NEVER: */
    /* s3[0] = 'X'; */                    /* segfault! */

    /* Practice: my_strlen, my_strcpy, my_strcmp WITHOUT <string.h>. */
    return 0;
}
