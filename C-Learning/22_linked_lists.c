/* Lesson 22 — linked lists: nodes + pointers = structure. Author: Adarsh */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *push_front(Node *head, int data) {
    Node *n = malloc(sizeof(Node));
    if (!n) return head;
    n->data = data;
    n->next = head;
    return n;                       /* new head */
}

Node *push_back(Node *head, int data) {
    Node *n = malloc(sizeof(Node));
    if (!n) return head;
    n->data = data; n->next = NULL;
    if (!head) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;   /* walk to the tail */
    cur->next = n;
    return head;
}

Node *find(Node *head, int target) {
    for (Node *cur = head; cur; cur = cur->next)
        if (cur->data == target) return cur;
    return NULL;
}

Node *remove_value(Node *head, int target) {   /* returns new head! */
    Node **indirect = &head;                    /* pointer-to-pointer walk */
    while (*indirect && (*indirect)->data != target)
        indirect = &(*indirect)->next;
    if (*indirect) {
        Node *victim = *indirect;
        *indirect = victim->next;
        free(victim);
    }
    return head;
}

void print_list(const Node *head) {
    for (const Node *cur = head; cur; cur = cur->next)
        printf("%d -> ", cur->data);
    printf("NULL\n");
}

void free_list(Node *head) {
    while (head) { Node *next = head->next; free(head); head = next; }
}

int main(void) {
    Node *list = NULL;
    for (int i = 1; i <= 4; i++) list = push_back(list, i);
    list = push_front(list, 0);
    print_list(list);

    Node *hit = find(list, 3);
    printf("found %d at %p\n", hit->data, (void *)hit);

    list = remove_value(list, 2);
    print_list(list);
    free_list(list);

    /* array vs linked list:
       array:  O(1) index, O(n) insert middle, contiguous memory
       list:   O(n) index, O(1) insert (given the node), grows one node at a time */

    /* Practice: reverse the list in place (three pointers: prev/cur/next). */
    return 0;
}
