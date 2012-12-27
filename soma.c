#include<stdio.h>
#include<stdlib.h>

void somaElementos(int *v, int i, int *soma);


int main(void)
{
	int n;
	int i; int soma;
	int *v; /*v[5] = {1, 2, 3, 4, 5};*/
	
	printf("Digite o número de elementos do vetor:\n");
	scanf("%d", &n);
	v = malloc(n * sizeof(int));
	
	for(i = 0; i < n; i++)
	{
		printf("insira o %dº elemento do vetor:\n", (i+1));
		scanf("%d", &v[i]);
	}
	
	soma = i = 0;
	somaElementos(v, i, &soma);
	
	printf("A soma dos elementos do vetor é: %d", soma);
	
	free(v);
	
	return 0;
}

void somaElementos(int *v, int i, int *soma)
{
	if(i < 5) {
		*soma += *(v+i); 
		somaElementos(v, i+1, soma);
	}
}
