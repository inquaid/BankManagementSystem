#include "header.h"

bool FindIdPass(char *username, char *UserPassWord) {

    FILE *fp = fopen("Database.txt", "r");

    char DBname[50]="", DBpass[3200]="";
    char buffer[buffer_size];

    while (fgets(buffer, buffer_size, fp) != NULL) {
        sscanf(buffer, "Name: %[^,], HashedPassword: %s", DBname, DBpass);
//        printf("\n\t%s\t%s",DBname,DBpass);
        if (!strcmp(DBname, username) && !strcmp(DBpass, UserPassWord)) {
            return true;
        }
    }
//    printf("\t%s\t%s\n",DBname,DBpass);
    return false;

}