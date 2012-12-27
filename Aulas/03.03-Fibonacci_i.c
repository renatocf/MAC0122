/* Façamos agora a versao iterativa */

#include<stdio.h>

int
fibonacci_i(int n);

int main(int argc, char *argv)
{
	if(argc == 0 || argc > 1) 
	{
		printf("Coloque o número de argumentos para fibonacci");
		return -1;
	}
	
	fibonacci_i(argv[1]);
	
	return 0;
}

int 
fibonacci_i(int n)
{
	int anterior, atual, proximo;
	int i;
	anterior = 0; atual = 1;
	
	if(n == 0) return 0;
	if(n == 1) return 1;
	for(i=1, i < n, i++)
	{
		proximo = atual + anterior;
		anterior = atual;
		atual = proximo;
	}
	
	return atual;
}

/* 	Novamente, analisando a comparação entre a versão recursiva e iterati-
	va do algoritmo é que estamos fazendo cálculos repetidos na recursão.
	Na iteração, porém, usamos a memória para fazer o cálculo. Devemos, 
	então, fazer um peso entre memória x tempo para escolher qual o melhor
	algoritmo para o caso.
*/	

