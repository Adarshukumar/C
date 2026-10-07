/* Lesson 30 — the toolbelt: compiler flags, gdb, sanitizers, make. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

int buggy_sum(int *arr, int n) {
    int total = 0;
    for (int i = 0; i <= n; i++)     /* off-by-one: reads arr[n] */
        total += arr[i];
    return total;
}

int main(void) {
    int arr[4] = {10, 20, 30, 40};

    /* COMPILE LIKE A PRO:
       gcc -Wall -Wextra -Wpedantic -g file.c -o app
         -Wall -Wextra : catch the dumb stuff (unused, = vs ==, ...)
         -g            : debug symbols for gdb
         -O2           : optimize (AFTER it works correctly)
       gcc -std=c17     : pin the standard (c99, c11, c17, c23)              */

    /* SANITIZERS — bugs found AT RUNTIME with exact stack traces:
       gcc -fsanitize=address,undefined -g file.c -o app
       AddressSanitizer  : overflows, use-after-free (slows ~2x)
       UBSan             : signed overflow, bad shifts, null derefs          */

    /* Uncomment to feel the sanitizer fire:
       printf("%d\n", buggy_sum(arr, 4));   */

    /* GDB MINIMUM VIABLE SESSION:
       gdb ./app
       (gdb) break main         <- set breakpoint
       (gdb) run                <- start
       (gdb) next / step        <- walk line by line
       (gdb) print arr[0]       <- inspect
       (gdb) bt                 <- backtrace after a crash
       (gdb) quit                                                    */

    /* VALGRIND (Linux/macOS): the leak hunter
       valgrind --leak-check=full ./app                              */

    /* MAKE — only rebuild what changed:
       app: main.o utils.o
       	gcc main.o utils.o -o app
       main.o: main.c utils.h
       	gcc -Wall -Wextra -c main.c
       utils.o: utils.c utils.h
       	gcc -Wall -Wextra -c utils.c
       clean:
       	rm -f *.o app                                                */

    printf("tools learned — now the segfaults fear YOU\n");
    return 0;
}
