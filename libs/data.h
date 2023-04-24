typedef struct Node{
    char* username;
    char* password;
    struct Node* next;
} node;

#define SIZE 100
#define len 8

typedef char* string;

node* table[SIZE];

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

node* found(string input, int pass){

    if(pass){

        int index = hashFunction(input);



    }else{



    }

    return NULL;

}

