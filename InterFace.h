#include "header.h"
#include "Login.h"

void Display(void) {
    printf("\n\033[1;34m\t\t\t\t** WELCOME **\033[0m\n\n");  // Bold text in blue
    printf("\033[1;92m1. Login\n\033[0m");  // Bold text in green
    printf("\033[1;32m2. Create New Account\n\033[0m");  // Bold text in light green
    printf("\033[1;31m3. Forgot Password\n\033[0m");  // Bold text in red

    int a;
    printf("\nEnter your choice (1-3, 0 to exit): ");

    scanf("%d", &a);

    switch (a) {
        case 1:
            printf("Log in\n");
            login();
            break;
        case 2:
            printf("New account created\n");
            break;

        case 3:
            printf("REcovered\n");
            break;
        case 0:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid Input\n");
    }
}
