#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "hash/SHA-256.c"

#define N 100
#define len 8

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


int main(void)
{   
    // char choice;
    // printf("Enter s -> Sign-Up or l -> Log-in: ");
    // scanf("%c", &choice);

    char username[20] ;
    char Pass[8];
    printf("Enter your username: ");
    fgets(username, 20, stdin);

    printf("Do you want to Generate a password? y/n: ");
    char c;
    scanf("%c", &c);

    if(c == 'y')
    {
        strcpy(Pass, generate_password());
    }
    else
    {   
        while(1)
        {
            printf("Enter your Password you want to set: ");
            scanf("%s", Pass);
            if(check_pass(Pass))
            {
                printf("Your Password should be of length 8 and must contain atleast one Uppercase and special character\n");
            }
            else
            {
                return 0;
            }
            
        }        
    }

    for(int i = 0; i<strlen(username);i++)
    {
        printf("%c", username[i]);
    }
    // int code = hashFunction(username);
    // printf("%i\n", code);
    // Users[code].name = username;
    // Users[code].password = Pass;

}
