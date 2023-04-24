typedef struct Node{
    char* username;
    char* password;
    struct Node* next;
} node;

typedef char* string;

#define true 1
#define false 0

#define SIZE 100
#define len 8

typedef char* string;

node *table[SIZE];

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

int hashFunction(char *user)
{   
    int sum = 0;
    for(int i = 0; i<len; i++)
    {
        sum += ascii(user[i]);
    }

    return sum % strlen(user);
}

//checks if a password is valid.
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

//generates a strong password.
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

node* found(string input, int pass){

    if(pass){

        int index = hashFunction(input);



    }else{



    }

    return NULL;

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

    string hash_pass = SHA256(pass1);
    int index = hashFunction(username);
    printf("%i\n", index);

    node *tmp = malloc(sizeof(node));
    tmp ->username = username;
    tmp ->password = hash_pass;
    table[index] = tmp;
    

    printf("%s : %s\n", table[index]->username, table[index]->password);

}




void login(){

    return;

}

