/* Lesson 23 — file I/O: fopen, fprintf, fscanf, fread. Author: Adarsh */
#include <stdio.h>

int main(void) {
    /* WRITE: fopen modes r / w (truncate!) / a (append) / rb / wb / ab */
    FILE *out = fopen("notes_23.txt", "w");
    if (!out) { perror("fopen"); return 1; }     /* ALWAYS check NULL */
    fprintf(out, "Adarsh's file lesson\n");
    fprintf(out, "%d %s %.2f\n", 42, "answer", 3.14);
    fputs("plain line\n", out);
    fputc('X', out);
    fclose(out);                                  /* ALWAYS close */

    /* READ back line by line (the robust way): */
    FILE *in = fopen("notes_23.txt", "r");
    if (!in) { perror("fopen"); return 1; }
    char line[256];
    while (fgets(line, sizeof line, in))         /* stops at \n or EOF */
        printf("read: %s", line);
    fclose(in);

    /* FORMATTED read: fscanf returns the matched count */
    in = fopen("notes_23.txt", "r");
    int n; char word[32]; double d;
    if (fscanf(in, "%*[^\n]\n") == 0) {}         /* skip line 1 via scan-set */
    if (fscanf(in, "%d %31s %lf", &n, word, &d) == 3)
        printf("parsed: %d %s %.2f\n", n, word, d);
    fclose(in);

    /* BINARY I/O: fwrite/fread move raw bytes */
    int nums[5] = {1, 2, 3, 4, 5};
    FILE *bin = fopen("data_23.bin", "wb");
    fwrite(nums, sizeof(int), 5, bin);
    fclose(bin);

    int back[5];
    bin = fopen("data_23.bin", "rb");
    size_t got = fread(back, sizeof(int), 5, bin);
    fclose(bin);
    printf("binary round-trip: %zu items, first=%d\n", got, back[0]);

    /* random access: fseek / ftell */
    bin = fopen("data_23.bin", "rb");
    fseek(bin, 2 * (long)sizeof(int), SEEK_SET);   /* 3rd int (SEEK_SET/END/CUR) */
    int third;
    fread(&third, sizeof(int), 1, bin);
    printf("third int: %d, pos=%ld\n", third, ftell(bin));
    fclose(bin);

    /* error + EOF flags: ferror(fp), feof(fp) — feof only true AFTER a failed read */
    remove("notes_23.txt"); remove("data_23.bin");

    /* Practice: append-mode log: open "a", write 3 lines, reopen and count. */
    return 0;
}
