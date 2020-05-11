#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char add[] = "ADD";
char and[] = "AND";
char br[] = "BR";
char ld[] = "LD";
char ldr[] = "LDR";
char not[] = "NOT";
char st[] = "ST";

const char * segment1(char *input) {
    char * seg1bits = malloc(4);
    if (strcmp(input, add) == 0) {
        seg1bits = "0010";
    }
    if (strcmp(input, and) == 0) {
        seg1bits = "0101";
    }
    if (strcmp(input, br) == 0) {
        seg1bits = "0000";
    }
    if (strcmp(input, ld) == 0) {
        seg1bits = "0010";
    }
    if (strcmp(input, ldr) == 0) {
        seg1bits = "0110";
    }
    if (strcmp(input, not) == 0) {
        seg1bits = "1001";
    }
    if (strcmp(input, st) == 0) {
        seg1bits = "0011";
    }
    return seg1bits;
}

int main() {

    int result;
    char *input;
    input = malloc(4);
    printf("Welcome to the scuffed LC-3 Assembler\n");

    scanf("%s", input);

    const char * seg1bits = segment1(input);
    printf("%s\n", seg1bits);
    return 0;
}

