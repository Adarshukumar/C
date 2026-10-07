/* Lesson 19 — structs on the heap + linked structures. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {              /* typedef: drop the 'struct' keyword */
    int data;
    struct Node *next;             /* self-referential pointer */
} Node;

Node *node_new(int data) {
    Node *n = malloc(sizeof(Node));
    if (!n) return NULL;
    n->data = data;
    n->next = NULL;
    return n;
}

void list_push(Node **head, int data) {   /* double pointer: modify head */
    Node *n = node_new(data);
    if (!n) return;
    n->next = *head;
    *head = n;
}

int list_sum(const Node *head) {
    int total = 0;
    for (const Node *cur = head; cur != NULL; cur = cur->next)
        total += cur->data;
    return total;
}

void list_free(Node *head) {              /* free every node we made */
    while (head) {
        Node *next = head->next;          /* save before freeing! */
        free(head);
        head = next;
    }
}

int main(void) {
    typedef struct { int x, y; } Point;   /* anonymous struct typedef */
    Point p = {3, 7};
    printf("point: %d,%d (%zu bytes)\n", p.x, p.y, sizeof(Point));

    /* heap struct: outlives the function, arrow access */
    Point *hp = malloc(sizeof(Point));
    if (hp) { hp->x = 10; hp->y = 20; printf("heap: %d,%d\n", hp->x, hp->y); free(hp); }

    /* struct pointers inside arrays — build a small list: */
    Node *head = NULL;
    for (int i = 1; i <= 4; i++) list_push(&head, i * 10);
    for (Node *cur = head; cur; cur = cur->next) printf("%d -> ", cur->data);
    printf("NULL\n");
    printf("sum: %d\n", list_sum(head));
    list_free(head);

    /* arrow is sugar: p->field == (*p).field */
    /* Practice: add list_length() and list_contains() to this file. */
    return 0;
}
