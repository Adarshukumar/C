/* Lesson 01 — hello, machine. Author: Adarsh
   Compile: gcc 01_first_program.c -o hello && ./hello          */
#include <stdio.h>      /* preprocessor: pull in standard I/O declarations */

int main(void) {        /* execution ALWAYS starts at main */
    printf("Hello, machine! I am Adarsh.\n");   /* \n = newline */
    printf("C was born in 1972 and still runs the world.\n");

    printf("int size: %zu bytes\n", sizeof(int));
    printf("char size: %zu byte\n", sizeof(char));
    printf("double size: %zu bytes\n", sizeof(double));

    return 0;           /* 0 = success, reported to the OS */
}

/* What actually happens:
   1. preprocessor  -> expands #include, #define (text processing)
   2. compiler      -> translates C to assembly for YOUR cpu
   3. assembler     -> assembly to object code (.o)
   4. linker        -> glues object files + libraries into one executable

   Compile flags I always use:
   gcc -Wall -Wextra -g file.c -o prog
   (-Wall -Wextra: show warnings; -g: debug symbols for gdb) */
