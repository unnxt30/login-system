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

int hash(char *user)
{   
    int sum = 0;
    for(int i = 0; i<len; i++)
    {
        sum += ascii(user[i]);
    }

    return sum % 3;
}

node* found(string input, int pass){

    if(pass){

        int index = hash(input);



    }else{



    }

    return NULL;

}

