#include "header.h"
#include "account.h"


typedef struct  {
    char name[buffer_size];
    char password[32];
    float amount;

} account2;

void create() {
    FILE *fp = fopen("Database.txt", "a");
    account2 ac;
    printf("Enter you name: ");
    getchar();

    fgets(ac.name, buffer_size, stdin);
    ac.name[strcspn(ac.name, "\n")] = 0;

    int i = 0;
    printf("Enter a password: ");
    while (true) {
        char ch = getch();
        if (ch == '\r' || ch == '\n') {
            ac.password[i] = 0;
            break;
        }
        ac.password[i++] = ch;
        printf("*");
    }

    char store[buffer_size];
    snprintf(store, sizeof(store), "Name: %s, HashedPassword: %s\n", ac.name,ac.password);
//    printf("%s\n%s\n%s",ac.name,ac.password,store);
    fprintf(fp,store);
}