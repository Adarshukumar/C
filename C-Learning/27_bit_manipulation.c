/* Lesson 27 — bits: the C superpower. Author: Adarsh */
#include <stdio.h>

void print_bits(unsigned int v) {
    for (int i = 31; i >= 0; i--) putchar((v >> i) & 1 ? '1' : '.');
    putchar('\n');
}

int main(void) {
    unsigned int a = 0b1010, b = 0b0110;    /* binary literals (GCC/clang ok) */

    printf("a=%u b=%u\n", a, b);
    print_bits(a); print_bits(b);
    print_bits(a & b);      /* AND: bits set in BOTH -> 0010 */
    print_bits(a | b);      /* OR: bits set in EITHER -> 1110 */
    print_bits(a ^ b);      /* XOR: bits that DIFFER -> 1100 */
    print_bits(~a);         /* NOT: flip every bit */
    print_bits(a << 1);     /* left shift = multiply by 2 */
    print_bits(a >> 1);     /* right shift = divide by 2 */

    /* masks: test, set, clear, toggle ONE bit */
    unsigned int flags = 0;
    int READABLE = 1 << 0, WRITABLE = 1 << 1, EXEC = 1 << 2;   /* 1,2,4 */
    flags |= WRITABLE | READABLE;         /* set */
    printf("readable? %d\n", (flags & READABLE) != 0);   /* test */
    flags &= ~WRITABLE;                   /* clear */
    flags ^= EXEC;                        /* toggle */
    printf("flags=%u exec=%d\n", flags, (flags & EXEC) != 0);

    /* classics */
    printf("is 64 power of 2? %d\n", (64 & (64 - 1)) == 0);
    printf("popcount(255) = ");
    unsigned int v = 255, count = 0;
    while (v) { count += v & 1; v >>= 1; }
    printf("%u\n", count);

    printf("swap without temp: ");
    int x = 5, y = 9;
    x ^= y; y ^= x; x ^= y;               /* XOR swap (interview trivia) */
    printf("%d %d\n", x, y);

    /* n-th bit extraction and packing two small numbers in one int: */
    unsigned char hi = 0xAB, lo = 0xCD;
    unsigned short packed = (hi << 8) | lo;    /* 0xABCD */
    printf("packed: %04X -> hi=%02X lo=%02X\n", packed,
           (packed >> 8) & 0xFF, packed & 0xFF);

    /* Practice: reverse the bits of an 8-bit number. */
    return 0;
}
