/*	ORDENAÇÃO POR SELEÇÃO
	
	Agora, nosso objetivo será achar o maior elemento do vetor e colo-
	cá-lo na posição CORRESPONDENTE.
	
	  00		i										n-1
	| 38 | 10 | 20 | 44 | 50 | 50 | 55 | 60 | 75 | 85 | 99 |
					 ^-- Até o elemento i+1, todos os elementos
						 estão ordenados.
	^^^^^^^^^^^^^^^^-- Procuraremos o maior elemento deste intervalo
					   e o colocaremos na posição correspondente (i),
					   colocando o elemento que estava em 'i' no lugar
					   do maior.
	
	RELAÇÕES INVARIANTES|
	(i0) v[i+1...n-1] é crescente.
	(i1) v[0...1] <= v[i+1...n-1]
		 --> abreviação para ∀ v[i], i = 0...i e ∀ v[j], j = i+1...n,
			 v[i] <= v[j];
	
		j <----   i
	|			| ? | <= <= <= <= <= <= |
				 ^^^-- Seleção
*/

void selecao(int n, int v[])
{
	int i, j, x, max;
/*1*/	for(i = n-1; i > 0; i--)
		{
/*2*/		max = i; /* Até percorrermos, o máximo é 'i' */
/*3*/		for(j = i-1; j >= 0; j--)
/*4*/			if(v[j] > v[max]) max = j; /*novo máximo*/
/*5*/		x = v[i]; v[i] = v[max]; v[max] = x; /*troca de posição*/
		}
}

/* 	COMPLEXIDADE DO ALGORITMO (ORDEM DE TEMPO)
	
	linha	| 
	1		| = n
			| ^-- Quantidade de vezes que o loop é executado
	2		| = n-1
			| ^-- quantas vezes atribuímos a 'max'
	3		| = (n-1) + (n-2) + ... + 1 = (n-1)*n/2 = (n²-n)/2
			| ^-- Corresponde às decrementações
	4		| = (n-2) + (n-3) + ... + 1 = (n-2)*(n-1)/2 = (n²-3n-2)/2
			| ^-- corresponde à comparações
	5		| = n - 1
	--------|---------------------------------------------------------
	TOTAL	| 3*n - 2 + n² - 2*n + 1
			| = n² + n - 1 = O(n²)
	
	Como este algoritmo tem muitos IGUAIS, o algoritmo, em geral, não
	flutua em relação à amostra - e por isso, em geral, perde para 
	outros tipos de algoritmos.
*/
