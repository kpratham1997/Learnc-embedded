#include <stdio.h>
#include <string.h>

int main() {
    char password[20]; // Assuming a maximum password length of 20 characters

    printf("Enter the password: ");
    scanf("%s", password);

    if (strcmp(password, "12345") == 0) {
        printf("Hello Prathamesh\n");
    } else {
        printf("Access Denied\n");
    }

    return 0;
}
