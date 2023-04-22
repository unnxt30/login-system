#include <stdio.h>


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

int main(void)
{
    printf("%i\n", isspecial('j'));
}
