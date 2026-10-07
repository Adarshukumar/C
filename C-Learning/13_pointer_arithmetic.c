/* Lesson 13 — pointer arithmetic & the heap preview. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>     /* malloc/free live here */

int main(void) {
    /* arithmetic valid WITHIN an array (one past the end is OK to point at) */
    int arr[4] = {5, 10, 15, 20};
    int *end = arr + 4;                 /* one past last — legal, don't read */
    for (int *p = arr; p != end; p++) printf("%d ", *p);
    printf("\n");

    /* subtracting pointers gives element COUNT: */
    printf("span: %td elements\n", end - arr);

    /* pointer comparisons: p < q iff p points to earlier memory */
    int *mid = arr + 2;
    printf("mid>arr: %d\n", mid > arr);

    /* the heap: memory YOU control (lesson 16 goes deep) */
    int *heap = malloc(4 * sizeof(int));    /* request 16 bytes */
    if (heap == NULL) {                     /* malloc CAN fail! */
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) heap[i] = (i + 1) * 100;
    for (int i = 0; i < 4; i++) printf("%d ", heap[i]);   /* heap[i] works — pointer! */
    printf("\n");
    free(heap);          /* ALWAYS free what you malloc — or leak */
    heap = NULL;         /* dangling-pointer protection idiom */

    /* dangling pointer demo (the bug, not the practice): */
    int *dangling = malloc(sizeof(int));
    *dangling = 5;
    free(dangling);
    /* *dangling = 6; */   /* USE-AFTER-FREE — undefined behavior! */
    dangling = NULL;

    /* stack vs heap, in one breath:
       stack: automatic, fast, freed at } return, limited size
       heap:  manual, flexible, lives until free(), limited by RAM */

    /* Practice: malloc an array of 10 ints, fill squares, free — with
       NULL checks and the set-to-NULL idiom. */
    return 0;
}
