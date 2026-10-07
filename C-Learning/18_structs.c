/* Lesson 18 — structs: your own data types. Author: Adarsh */
#include <stdio.h>
#include <string.h>

struct Student {           /* definition — a blueprint, no memory yet */
    int id;
    char name[50];
    double gpa;
    int marks[6];
};

/* initialization styles */
struct Student make_student(int id, const char *name) {
    struct Student s = {.id = id, .gpa = 3.5};   /* designated init */
    strncpy(s.name, name, sizeof s.name - 1);
    return s;                    /* returning structs: COPIES all fields */
}

double average(const struct Student *s) {   /* pass by POINTER = no copy */
    int total = 0;
    for (int i = 0; i < 6; i++) total += s->marks[i];   /* -> = (*ptr).field */
    return total / 6.0;
}

int main(void) {
    /* three ways to create + init */
    struct Student a = {1, "Adarsh", 3.8, {90, 85, 88, 92, 79, 95}};
    struct Student b = make_student(2, "Riya");
    struct Student c = {.id = 3, .name = "Kiran", .gpa = 3.2};  /* rest zeroed */

    /* access: dot for values, arrow for pointers */
    struct Student *p = &a;
    printf("%s gpa=%.1f\n", a.name, a.gpa);
    printf("%d via arrow\n", p->id);

    b.marks[0] = 88; b.marks[1] = 91; b.marks[2] = 84;
    b.marks[3] = 90; b.marks[4] = 86; b.marks[5] = 89;
    printf("Riya avg: %.1f\n", average(&b));

    /* assignment copies the WHOLE struct (arrays inside too!): */
    c = a;
    c.marks[0] = 0;
    printf("a.marks[0]=%d c.marks[0]=%d (independent)\n", a.marks[0], c.marks[0]);

    /* nested structs */
    struct Address { char city[30]; int pin; };
    struct Person { char name[50]; struct Address addr; };
    struct Person me = {"Adarsh", {"Delhi", 110001}};
    printf("%s, %s %d\n", me.name, me.addr.city, me.addr.pin);

    /* arrays of structs — the workhorse of real C programs: */
    struct Student class_of[3] = {a, b, c};
    for (int i = 0; i < 3; i++) printf("#%d %s\n", class_of[i].id, class_of[i].name);

    /* sizeof includes possible PADDING for alignment: */
    struct Padded { char c; int i; char d; };
    printf("Padded: %zu bytes (not 6 — alignment!)\n", sizeof(struct Padded));

    /* Practice: struct Rectangle + area/perimeter functions taking pointers. */
    return 0;
}
