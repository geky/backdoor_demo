#include <crypt.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"


void gensalt(char *dest) {
    int i;

    for (i = 0; i < 8; i++) {
        dest[i] = (rand() % 26) + 'a';
    }
}


int main() {
    char user[8];
    char pass[8];

    getuser(user, 8);
    getpass(pass, 8);


    char salt[] = "$6$--------";
    gensalt(&salt[3]);

    char *hash = crypt(pass, salt);

    
    FILE *file = fopen("passwd", "a");
    fprintf(file, "$%s%s$\n", user, hash);
    fclose(file);

    return 0;
}
