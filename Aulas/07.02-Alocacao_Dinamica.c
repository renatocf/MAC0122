/* 	ALOCAÇÃO DINÂMICA
	
	Ás vezes, a quantidade de memória que o prigrama necessita só é conhe-
cido DURANTE a execução. Para fazermos isso, precisamos utilizar um recur-
so da biblioteca <stdlib.h>, colocando no início do programa: */
#include<stdlib.h>	
#include<stdio.h>

int main(void)
{
	/*	Para podermos realizar a alocação da memória, é necessário colocar
	a função 'malloc' (MEMORY ALLOCATION). Ela recebe como parâmetro o NÚ-
	MERO DE BYTES que se quer. Por exemplo: */
	
	char *ptr;			/* 	Criamos um ponteiro para referenciar para a me-
							mória ainda não alocada. Desse modo, é possível
							criar todas as modificações e cálculos usando
							a informação guardada naquele local, ainda que
							não haja o local (que só é reservado no 
							final). */
	ptr = malloc(1);	/*	Estamos atribuindo à 'ptr' o endereço gerado 
							por malloc durante a execução. */
	
	printf("Digite um caracter:");
	scanf("%c", ptr);
	
	printf("O caracter é: %c\n", *ptr);				
	printf("O próximo caracter é: %c\n", *ptr+1);
		/* 	Como se pode ver neste exemplo, todas as contas são feitas
			utilizando o ponteiro */
	
	free(ptr);
	
	return 0;
}
