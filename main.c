#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//The necessary variable to check for the specific instructions
char add[] = "ADD";
char and[] = "AND";
char brn[] = "BRn";
char brz[] = "BRz";
char brp[] = "BRp";
char brnz[] = "BRnz";
char brnp[] = "BRnp";
char brzp[] = "BRzp";
char brnzp[] = "BRnzp";
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
char binaryNum[5];

//Converts the input num to binary
const char * toBin(char * input) {
    memmove(&input[0], &input[1], strlen(input) - 0);
    int isNegative = 0;
    strcpy(binaryNum,"");
    int n = atoi(input);
    int k, c;
    if(n < 0) {
        n = n * (-1);
        isNegative = 1;
    }

    for (int c = 0; c < 5; ++c) {
        k = n >> c;
        if (k & 1)
            strcat(binaryNum, "1");
        else
            strcat(binaryNum, "0");
    }

    if (isNegative == 1) {
        for (int i = 0; i < strlen(binaryNum); i++) {
            if (binaryNum[i] == '1') {
                for (int j = i+1; j < strlen(binaryNum); j++) {
                    if (binaryNum[j] == '1'){
                        binaryNum[j] = '0';
                    }
                    else {
                        binaryNum[j] = '1';
                    }
                }
                break;
            }
        }
    }
    strrev(binaryNum);
    return binaryNum;
}
//Converts the first instructions to binary
const char * segment1(char * input) {
    char * seg1bits = malloc(4);
    if (strcmp(input, add) == 0) {
        seg1bits = "0001";
    }
    if (strcmp(input, and) == 0) {
        seg1bits = "0101";
    }
    if (strcmp(input, brn) == 0) {
        seg1bits = "0000100";
    }
    if (strcmp(input, brz) == 0) {
        seg1bits = "0000010";
    }
    if (strcmp(input, brp) == 0) {
        seg1bits = "0000001";
    }
    if (strcmp(input, brnz) == 0) {
        seg1bits = "0000110";
    }
    if (strcmp(input, brnp) == 0) {
        seg1bits = "0000101";
    }
    if (strcmp(input, brzp) == 0) {
        seg1bits = "0000011";
    }
    if (strcmp(input, brnzp) == 0) {
        seg1bits = "0000111";
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
//Converts the reg or num to binary
const char * reg(char * input) {
    char * seg2bits = malloc(10);
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
    if(strchr(input, '#') != NULL) {
        seg2bits = (toBin(input));

    }
    return seg2bits;
}


int main() {

    int stop = 0;

    while(stop == 0) {

        int count = 0;
        char *input = malloc(1000);
        char delim[] = " ";
        char delim2[] = ", ";

        const char * seg1bits;
        const char * seg2bits;
        const char * seg3bits;
        const char * seg4bits;

        scanf ("%[^\n]%*c", input);

        if (input == "stop") {
            stop = 1;
        }

        for (int i = 0; i < strlen(input); ++i) {
            if (input[i] == ' ')
                count++;
        }

        if (count == 1) {
            char *ptr = strtok(input, delim);

            char * seg1bits = segment1(ptr);
            printf("%s", seg1bits);

            ptr = strtok(NULL, delim2);

            char * seg2bits = reg(ptr);
            printf("%s\n", seg2bits);
            continue;
        }
        if (count == 2) {
            char *ptr = strtok(input, delim);

            char * seg1bits = segment1(ptr);
            printf("%s", seg1bits);

            ptr = strtok(NULL, delim2);

            char * seg2bits = reg(ptr);
            printf("%s", seg2bits);

            ptr = strtok(NULL, delim2);

            char * seg3bits = reg(ptr);
            printf("%s", seg3bits);

            if (seg1bits == "1001") {
                printf("111111\n");
                continue;
            }
            continue;
        }
        if (count == 3) {
            char *ptr = strtok(input, delim);

            char * seg1bits = segment1(ptr);
            printf("%s", seg1bits);

            ptr = strtok(NULL, delim2);

            char * seg2bits = reg(ptr);
            printf("%s", seg2bits);

            ptr = strtok(NULL, delim2);

            char * seg3bits = reg(ptr);
            printf("%s", seg3bits);

            ptr = strtok(NULL, delim);

            char * seg4bits = reg(ptr);

            if(strlen(seg4bits) > 3) {
                printf("1%s\n", seg4bits);
                continue;
            }
            else {
                printf("000%s\n", seg4bits);
                continue;
            }
        }
    }
    return 0;
}

