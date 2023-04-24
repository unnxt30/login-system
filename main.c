#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "libs/SHA-256.c"
#include "libs/data.h"


int main(){

    printf("Welcome to the login portal...\n");

    while(1){

        printf("Press L to login using your username and password\n");
        printf("Or press S to signup\n");
        printf("==================================================\n");
        printf("Press E to exit the login portal\n");

        char s[10];
        scanf("%s", s);
        char in = s[0];

        switch(tolower(in)){

            case 'l':
                login();
                break;
            
            case 's':
                signUp();
                break;
            
            case 'e':
                printf("Thank you for using the login portal...\n");
                return 0;

            default:
                printf("Invalid option selected...\n");

        }
    }

}


