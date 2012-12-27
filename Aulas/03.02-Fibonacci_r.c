/* NÚMEROS DE FIBONACCI

	F(0) = 0				} BASE
	F(1) = 1				}
	F(n) = F(n-1) + F(n-2)	
	
	 n	|  0  1  2  3  4  5  6
	F(n)|  0  1  1  2  3  5  8
*/

#include<stdio.h>


int
fibonacci_r(int n);

int main(int argc, char *argv)
{
	if(argc == 0 || argc > 1) 
	{
		printf("Coloque o número de argumentos para fibonacci");
		return -1;
	}
	
	fibonacci_r(argv[1]);
	
	return 0;
}


int
fibonacci_r(int n)
{
	if(n == 0) return 0;
	if(n == 1) return 1;
	return fibonacci(n-1) + fibonacci(n-2);
}

/* SIMULAÇÃO DE FIBONACCI:
	
	
	fibonacci(3)
	|-------------------------------|
	|n								|
	|3	fibonacci(2)				|
	|	|-----------------------|	|
	|	|n						|	|
	|	|2	fibonacci(1)		|	|
	|	|	|---------------|	|	|
	|	|	|n				|	|	|
	|	|	|1 retorna 1	|	|	|
	|	|	|---------------|	|	|
	|	|						|	|
	|	|	fibonacci(0)		|	|
	|	|	|---------------|	|	|
	|	|	|n				|	|	|	
	|	|	|0 retorna 0	|	|	|
	|	|	|---------------|	|	|
	|	|						|	|
	|	|	retorna 1 + 0 = 1	|	|
	|	|						|	|
	|	|-----------------------|	|
	|								|
	|	fibonacci(1)				|
	|	|-----------------------|	|
	|	|n						|	|
	|	|1  retorna 1			|	|
	|	|-----------------------|	|
	|								|
	|	retorna 1 + 1 = 2			|
	|								|
	|-------------------------------|


	ÁRVORE DE RECURSÃO
							F(3)	retorna 1 + 1 = 2
							/  \
	   retorna 1 + 0 = 1  F(2) F(1)	retorna 1
						  /  \
			retorna 1	F(1) F(0)	retorna 0

*/
