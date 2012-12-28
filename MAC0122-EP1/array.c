#include<stdio.h>

int main(void)
{
    int array[10] = {-5, -4, -3, -2, -1, 1, 2, 3, 4, 5};
    int i=0, soma = 0;
    for(i = 0; i < 10; i++)
        soma += array[i];
    printf("%d", soma);
    
    return 0;
}
