#include<stdio.h>

int main(int argc, char *argv[])
{
    int i;
    for(i = 1; i < argc-1; i++)
    {
        printf("%s%s", argv[i], " ");
    }
    printf("%s%s", argv[argc-1], "\n");
    
    return 0;
}
