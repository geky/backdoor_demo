#include "input.h"

#include <stdio.h>


void getuser(char *dst, int len) {
    int i;
    printf("username: ");

    for (i = 0; i < len; i++) {
        dst[i] = getchar();

        if (dst[i] == '\n') {
            break;
        }
    }

    if (dst[i] != '\n') {
        while (getchar() != '\n');
    }

    dst[i] = 0;
}

void getpass(char *dst, int len) {
    int i;
    printf("password: ");
    printf("\033[30;40m");

    for (i = 0; i < len; i++) {
        dst[i] = getc(stdin);

        if (dst[i] == '\n') {
            break;
        }
    }

    if (dst[i] != '\n') {
        while (getchar() != '\n');
    }

    dst[i] = 0;
    printf("\033[0m");
}
