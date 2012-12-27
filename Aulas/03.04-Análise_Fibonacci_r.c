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

/* 	Vamos, agora, analisar o número de chamadas recursivas deste algoritmo.
   	Porém, para facilitar, podemos usar um truque: o número de chamadas 
	recursivas é o dobro do número de somas presentes no algorito. Assim,
	podemos analisar quantas somas são feitas em cada caso:

	T(n) = número de adições feitas por Fibonacci
	
	T(0) = 0
	T(1) = 0
	T(n) = T(n-1) + T(n-2) + 1, n > 2
							 ^-- A 1 soma presente no último 'return'
	
	Estimativa de T(n)?
		T(n) >= (3/2)^n <---- É um tempo exponencial, que vai aumentando
							  de 50% em 50% conforme se aumenta a entrada.
		para n >= 6

	Em comparação, a versão iterativa é proporcional a 'n' (as instruções
	iterativas são realizadas quase no mesmo número de vezes da versão 
	iterativa - ele segue uma proporção [dobrando o número de instruções,
	dobra o tempo, enquanto no outro o tempo aumenta em 50% apenas com 1
	entrada a mais)
