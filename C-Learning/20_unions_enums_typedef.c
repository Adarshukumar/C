/* Lesson 20 — unions, enums, typedef. Author: Adarsh */
#include <stdio.h>

typedef union {              /* union: ALL members share ONE memory block */
    int i;
    float f;
    char bytes[4];
} Value;                     /* size = largest member (4 bytes here) */

typedef enum {               /* enum: named integer constants */
    STATUS_OK = 0,
    STATUS_NOT_FOUND = 404,
    STATUS_ERROR = 500
} Status;

typedef struct {             /* tagged union: the C way to do variants */
    enum { SHAPE_CIRCLE, SHAPE_SQUARE } kind;
    union {
        double radius;
        double side;
    };
} Shape;

const char *status_text(Status s) {
    switch (s) {
        case STATUS_OK:        return "ok";
        case STATUS_NOT_FOUND: return "missing";
        case STATUS_ERROR:     return "server error";
    }
    return "unknown";
}

int main(void) {
    /* union: one value, many interpretations */
    Value v;
    v.i = 0x40490FDB;                       /* float bits of pi-ish */
    printf("as int:   %d\n", v.i);
    printf("as float: %.6f\n", v.f);
    printf("as bytes: %02x %02x %02x %02x\n",
           v.bytes[0], v.bytes[1], v.bytes[2], v.bytes[3]);
    printf("union size: %zu (struct would be 8+)\n", sizeof(Value));

    /* enums are ints underneath */
    Status s = STATUS_NOT_FOUND;
    printf("%d -> %s\n", s, status_text(s));
    for (Status st = STATUS_OK; st <= STATUS_ERROR; st++)
        printf("  %zu: %s\n", (size_t)st, status_text(st));

    /* tagged union in action */
    Shape c = {.kind = SHAPE_CIRCLE, .radius = 2.0};
    Shape q = {.kind = SHAPE_SQUARE, .side = 3.0};
    for (int i = 0; i < 2; i++) {
        Shape sh = i ? q : c;
        double area = (sh.kind == SHAPE_CIRCLE)
                          ? 3.14159 * sh.radius * sh.radius
                          : sh.side * sh.side;
        printf("shape %d area: %.2f\n", i, area);
    }

    /* typedef on functions too: */
    typedef int (*Compare)(const void *, const void *);

    /* Practice: tagged union Token { NUMBER, WORD, OP } and a printer. */
    return 0;
}
