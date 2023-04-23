#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "libs/SHA-256.c"
#include "libs/data.h"

#define N 100
#define len 8

#define true 1
#define false 0
typedef char* string;

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

        switch(in){

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

void signUp(){

    printf("Please enter a username:\n");
    string username = malloc(32);

    while(1){
        scanf("%s", username);
        if(found(username, false)){
            printf("The chosen username already exists. Please enter another username.\n");
        }else{
            break;
        }
    }

    string pass1 = malloc(32);
    string pass2 = malloc(32);

    while(1){

        printf("Please enter a strong password:\n");
        scanf("%s", pass1);
        printf("Re-enter your password:\n");
        scanf("%s", pass2);

        if(!strcmp(pass1, pass2)){
            printf("The passwords do not match.\n");
        }else{
            break;
        }

    }
he conflict editor on GitHub to resolve competing line change merge conflicts between branches that are part of a pull reques
    string hash = SHA256(pass1);

    insert(username, hash);

}

node* found(string input, int pass){



    return NULL;

}

int ascii(char c)
{
    return (int) c;
}

int isspecial(char c)
{
    char special[] = "!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";

    for(int i = 0; i<32; i++)
    {
        if(c == special[i])
        {
            return 1;
        }
    }
    return 0;
}


//checks if the password is valid.
int check_pass(char* passwd)
{   
    int upper = 0;
    int special = 0;

    if(strlen(passwd)<8)
    {
        return 1;
    }

    for(int i = 0; i < len; i++)
    {   
        if(isupper(passwd[i]))
        {
            upper++;
        }

        if(isspecial(passwd[i]))
        {
            special ++;
        }
    }

    if(special < 1 || upper <1)
    {
        return 1;
    }

    return 0;
}

char *generate_password(void)
{
   const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`";
   const int password_length = 8;
   
   srand(time(NULL));
   
   char* password = malloc(sizeof(char) * (password_length + 1));
   int has_uppercase = 0, has_special = 0;
   
   while (!has_uppercase || !has_special) {
      for (int i = 0; i < password_length; i++) {
         password[i] = charset[rand() % sizeof(charset)];
         if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
         }
         if (strchr("!@#$%^&*()_+-={}[]|\\:;\"'<>,.?/~`", password[i]) != NULL) {
            has_special = 1;
         }
      }
   }
   password[password_length] = '\0';
   
   return password;
}


int hashFunction(char *user)
{   
    int sum = 0;
    for(int i = 0; i<len; i++)
    {
        sum += ascii(user[i]);
    }

    return sum % 3;
}

typedef struct 
{
    char *name;
    char *password;
}
user;

user Users[N];
