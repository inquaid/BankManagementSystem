#include "header.h"
//#include "account.h"
#include "SearchOnDatabase.h"
#include "CreateAccount.h"

typedef struct {
    char name[buffer_size];
    char password[32];
    float amount;

}account;

void login() {
//    create();
    account ac;
    int i = 0;
    printf("Username: ");

    getchar();

    fgets(ac.name, buffer_size, stdin);
    ac.name[strcspn(ac.name, "\n")] = 0;

    printf("Password: ");
    while (true) {
        char ch = getch();
        if (ch == '\r' || ch == '\n') {
            ac.password[i] = '\0';
            break;
        }
        ac.password[i++] = ch;

        printf("*");

    }
    if (FindIdPass(ac.name, ac.password)) {
        printf("\nFound\n");
    } else {
        printf("\nNot found\n\033[1;32m1. Create New Account\n\033[0m\033[1;31m2. Exit\n\033[0m");
        int condition;
        scanf("%d", &condition);
        switch (condition) {
            case 1:
                create();
                printf("\ncreated");  // Bold text in light green
                break;
            case 2:
                printf("exited");
                break;
            default:
                printf("Invalid");
        }

    }

//    printf("\nWelcome %s\nYour pass is %s ", ac.name, ac.password);
}