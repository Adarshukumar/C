/* Lesson 25 — multi-file projects: headers, extern, static. Author: Adarsh

   Real programs split into files. The standard layout for a mini project:

   ---- math_utils.h (the INTERFACE — what others see) ----
   #ifndef MATH_UTILS_H            <- include guard (or #pragma once)
   #define MATH_UTILS_H
   int add(int a, int b);
   double average(const int *nums, int n);
   #endif

   ---- math_utils.c (the IMPLEMENTATION) ----
   #include "math_utils.h"         <- YOUR headers use ""
   int add(int a, int b) { return a + b; }
   double average(const int *nums, int n) {
       int total = 0;
       for (int i = 0; i < n; i++) total += nums[i];
       return total / (double)n;
   }
   static int helper_cache = 0;    <- static = private to THIS file

   ---- main.c ----
   #include <stdio.h>              <- system headers use <>
   #include "math_utils.h"
   int main(void) {
       printf("%d\n", add(1, 2));
       return 0;
   }

   ---- build ----
   gcc -Wall -Wextra main.c math_utils.c -o app

   ---- sharing a GLOBAL across files ----
   config.c:  int setting_count = 0;        <- definition (the memory)
   main.c:    extern int setting_count;     <- declaration (no memory)

   ---- makefile sketch ----
   app: main.o math_utils.o
       gcc main.o math_utils.o -o app
   %.o: %.c
       gcc -Wall -Wextra -c $< -o $@

   This file itself compiles standalone (the project lives in comments). */
#include <stdio.h>

/* include guards stop double-inclusion; #pragma once is the modern shortcut */

/* One more pattern: header-only "module" with static inline */
static inline int twice(int x) { return x * 2; }

int main(void) {
    printf("twice 21 = %d\n", twice(21));
    /* Practice: actually split one earlier lesson into 3 files + build it. */
    return 0;
}
