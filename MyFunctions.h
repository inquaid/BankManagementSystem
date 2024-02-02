#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define HASH_OFFSET 31

typedef struct account {
    char name[50];
    unsigned int hash;
} account;

unsigned int simpleHash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = hash * HASH_OFFSET + *str;
        str++;
    }
    return hash;
}

bool FindUserName(const char *name) {
    FILE *fp;
    fp = fopen("Username.txt", "r");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        if (!strcmp(buffer, name)) {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);

    return false;
}

bool CheckPassword(const char *name, const char *PW) {
    unsigned int hashedPassword = simpleHash(PW);
    char hashedPasswordStr[100];
    snprintf(hashedPasswordStr, sizeof(hashedPasswordStr), "%u", hashedPassword);

    FILE *fp;
    fp = fopen("Accounts.txt", "r");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        buffer[strcspn(buffer, "\n")] = 0;
        char storedName[50], storedPassword[100];
        sscanf(buffer, "Name: %[^,], Hashed Password: %s", storedName, storedPassword);
        if (!strcmp(storedName, name) && !strcmp(storedPassword, hashedPasswordStr)) {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}


void CreateAccount() {
    char name[50], password[100];
    printf("Name: ");
    scanf("%[^\n]", name);
    getchar();

    printf("Password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    FILE *fp = fopen("Username.txt", "a");
    fprintf(fp, "%s\n", name);
    fclose(fp);

    FILE *accountFile = fopen("Accounts.txt", "a");
    unsigned int hashedPassword = simpleHash(password);
    fprintf(accountFile, "Name: %s, Hashed Password: %u\n", name, hashedPassword);
    fclose(accountFile);
}


void interface() {
    char name[50], password[100];
    printf("Username: ");
    scanf("%[^\n]", name);
    getchar();
    if (FindUserName(name)) {
        printf("FOUND\n");
        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = 0;
        if (CheckPassword(name, password)) {
            printf("Welcome");
        } else {
            printf("Wrong Password");
        }

    } else {
        printf("NOT FOUND.\nWant to create an account?\nIf yes, press y else n: ");
        char c;
        scanf("%c", &c);
        getchar();
        if (c == 'y') {
            CreateAccount();
        } else {
            printf("See you later\n");
        }

    }
}
