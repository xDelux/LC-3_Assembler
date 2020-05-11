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
char r0[] = "R0";
char r1[] = "R1";
char r2[] = "R2";
char r3[] = "R3";
char r4[] = "R4";
char r5[] = "R5";
char r6[] = "R6";
char r7[] = "R7";
char hash[] = "#";

const char * toBin(char * input) {
    char * SR2 = malloc(6);
    int n;
    sscanf(input, "%d", n);
    if(n < 0) {
        n = n * -1;

    if (input[1] == "-") {
        SR2[0] = "1";
    }
    else {
        SR2[0] = "0";
    }

        // array to store binary number
        int binaryNum[5];

        // counter for binary array
        int i = 0;
        int u = 0;
        while (n > 0) {

            // storing remainder in binary array
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }

        // printing binary array in reverse order
        for (int j = i - 1; j >= 0; j--) {
            SR2[u + 1] = binaryNum[j];
            u++;
        }

    return SR2;
    }
}
const char * segment1(char * input) {
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
const char * reg(char * input) {
    char * seg2bits = malloc(3);
    int r;
    if(r = strcmp(input, r0) == 0) {
        seg2bits = "000";
        return seg2bits;
    }
    if(r = strcmp(input, r1) == 0) {
        seg2bits = "001";
        return seg2bits;
    }
    if(r = strcmp(input, r2) == 0) {
        seg2bits = "010";
        return seg2bits;
    }
    if(r = strcmp(input, r3) == 0) {
        seg2bits = "011";
        return seg2bits;
    }
    if(r = strcmp(input, r4) == 0) {
        seg2bits = "100";
        return seg2bits;
    }
    if(r = strcmp(input, r5) == 0) {
        seg2bits = "101";
        return seg2bits;
    }
    if(r = strcmp(input, r6) == 0) {
        seg2bits = "110";
        return seg2bits;
    }
    if(r = strcmp(input, r7) == 0) {
        seg2bits = "111";
        return seg2bits;
    }
    if(r = strcmp(input[0], hash) == 0) {
        seg2bits = toBin(input);
        return seg2bits;

    }
    return seg2bits;
}


int main() {

    const char *input;
    input = malloc(7);
    char delim[] = " ";
    char delim2[] = ", ";
    printf("Welcome to the scuffed LC-3 Assembler\n");

    scanf ("%[^\n]%*c", input);
    char *ptr = strtok(input, delim);

    const char * seg1bits = segment1(ptr);
    printf("%s ", seg1bits);


    ptr = strtok(NULL, delim2);


    const char * seg2bits = reg(ptr);
    printf("%s ", seg2bits);

    ptr = strtok(NULL, delim2);

    const char * seg3bits = reg(ptr);
    printf("%s ", seg3bits);

    ptr = strtok(NULL, delim);

    const char * seg4bits = reg(ptr);
    printf("%s ", seg4bits);
    return 0;
}

