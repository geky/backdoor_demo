
#include "string.h"


int streq(char *a, char ta, char *b, char tb) {
    int i = 0;

    while (1) {
        if (a[i] == ta || b[i] == tb)
            return ((a[i] == ta) && (b[i] == tb));

        if (a[i] != b[i])
            return 0;

        i++;
    }
}

int strlen(char *a, char ta) {
    int i = 0;

    while (1) {
        if (a[i] == ta)
            return i;

        i++;
    }
}
