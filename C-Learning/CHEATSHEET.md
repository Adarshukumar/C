# C Cheatsheet — by Adarsh

## Program skeleton
```c
#include <stdio.h>
int main(void) { printf("hi\n"); return 0; }
```
Compile: `gcc -Wall -Wextra -g file.c -o app`

## printf codes
`%d int · %u unsigned · %ld long · %f double · %lf scanf-double ·
%c char · %s string · %p pointer · %zu sizeof · %x hex · %.2f precision · %5d width`

## Pointers
```c
int x = 5;      int *p = &x;       /* & = address of */
*p = 9;                             /* * = value at   */
int **pp = &p;                      /* pointer to pointer */
NULL check: if (!p) ...             /* before deref! */
```

## Arrays & strings
```c
int a[5] = {0};                     /* zero-init */
size_t n = sizeof a / sizeof a[0];
char s[] = "hi";                    /* {'h','i','\0'} */
strlen strcpy strcat strcmp strchr strstr strncpy
```

## Functions
```c
int add(int, int);                          /* prototype */
void swap(int *a, int *b);                  /* out/in params */
int (*cmp)(const void*, const void*);       /* function pointer */
```

## malloc family
```c
int *v = malloc(n * sizeof *v);
int *z = calloc(n, sizeof(int));   /* zeroed */
v = realloc(v, new_n * sizeof *v); /* may MOVE */
if (!v) { /* handle */ }
free(v); v = NULL;                 /* always */
```

## Structs
```c
typedef struct { int id; char name[50]; } Student;
Student s = {.id = 1};             /* designated init */
Student *p = &s; p->id = 2;        /* arrow for pointers */
```

## Control flow
```c
if/else · switch(x){case 1: ...; break;} ·
for(int i=0;i<n;i++) · while · do{}while() · break · continue
```

## Files
```c
FILE *f = fopen("x.txt", "r|w|a|rb|wb");
if (!f) { perror("fopen"); return 1; }
fprintf(f, "%d\n", n);  fgets(line, sizeof line, f);
fwrite/fread  fseek/ftell  fclose(f)
```

## Preprocessor
```c
#define MAX 100
#define SQ(x) ((x)*(x))
#ifndef H #define H #endif          /* include guards */
#ifdef _WIN32 ... #endif
```

## Memory map
`[text|rodata|data|bss | heap↑ ... ↓stack]` · locals=stack · malloc=heap · globals=data/bss

## Bits
```c
flags |= BIT;   flags &= ~BIT;   flags ^= BIT;   if (flags & BIT)
x << 1 == x*2;  x >> 1 == x/2;   n & (n-1) == 0 -> power of two
```

## Debug
`gcc -fsanitize=address,undefined -g` · `gdb ./app` (break/run/next/print/bt) · `valgrind --leak-check=full`

— Adarsh
