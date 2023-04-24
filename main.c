#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "libs/SHA-256.c"
#include "libs/data.h"

#define N 100


#define true 1
#define false 0
typedef char* string;

void signUp();
void login();

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

typedef struct 
{
    char *name;
    char *password;
}
user;

user Users[N];

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

    string pass1 = malloc(8);
    string pass2 = malloc(8);


    printf("Do you want to Generate a password? y/n: ");
    
    char *c = malloc(256);
    scanf("%s", c);

    if(c[0] == 'y')
    {
        strcpy(pass1, generate_password());
    }

    else
    {   
        while(1)
        {
            printf("Enter your Password you want to set: ");
            scanf("%s", pass1);

            printf("Re-enter your password: ");
            scanf("%s", pass2);
            

            if(strcmp(pass1,pass2))
            {
                printf("Passwords don't match enter again.\n");
            }
            else if(check_pass(pass1))
            {
                printf("Your Password should be of length 8 and must contain atleast one Uppercase and special character\n");
            }
            else
            {
                break;
            }
            
        }   
    } 

    // while(1){

    //     printf("Please enter a strong password:\n");
    //     scanf("%s", pass1);
    //     printf("Re-enter your password:\n");
    //     scanf("%s", pass2);

    //     if(!strcmp(pass1, pass2)){
    //         printf("The passwords do not match.\n");
    //     }else{
    //         break;
    //     }

    string hash_pass = SHA256(pass1);

    int index = hashFunction(username);
    Users[index].name = username;
    Users[index].password = hash_pass; 

}



    //insert(username, hash);



void login(){

    return;

}

