/*	ORDENAÇÃO POR INSERÇÃO
	
	RELAÇÃO INVARIANTE BÁSICA:
	No início de cada iteração, vale que 'v[0...j-1]' é crescente
	(v[0] <= v[1] <= ... <= v[j-1])
	
	Algoritmos de inserção são bons principalmente quando não conhe-
	cemos todos os dados que temos - ou quando estes dados chegam 
	DINAMICAMENTE ao longo do tempo.
	
	Ex:
	
 x = 37	  i
		  00								  j		        n-1
		| 20 | 25 | 35 | 38 | 40 | 44 | 55 | 37 | 65 | 40 | 10 |
		-----------------------------------
		Está ordenado até j-1
		
	COMPARAÇÃO: 25 < 37
				i
		| 20 | 25 | 35 | 38 | 40 | 44 | 55 | 37 | 65 | 40 | 10 |
		
	COMPARAÇÃO: 35 < 37
					i
		| 20 | 25 | 35 | 38 | 40 | 44 | 55 | 37 | 65 | 40 | 10 |
		
	COMPARAÇÃO: 38 > 37
						 i
		| 20 | 25 | 35 | 38 | 40 | 44 | 55 | 37 | 65 | 40 | 10 |
	
	ACHAMOS A POSIÇãO: REORDENAMOS:
		| 20 | 25 | 35 | 37 | 38 | 40 | 44 | 55 | 65 | 40 | 10 |
	
	REPETIMOS O PROCESSO ATÉ O FINAL DO VETOR
*/

void insercao(int n, int v[])
					 /* int *v - para mostrar que é um endereço na 
						memória */
			 /* int e, int d - também são usados para podermos ordenar
				apenas uma região do vetor */
{
	int j, i, x;
/*01*/	for(j = 1; /*1*/ j < n; j++)
		/* 	J começa com '1' porque todo vetor com 0 elementos já é
			ordenada */
		{
/*02*/		x = v[j]; /* pivô, chave */
/*03*/		for(i = j-1; i >= 0 && v[i] > x; i--)
/*04*/			v[i+1] = v[i];
/*05*/		v[i+1] = x;
		}
}

/*	CONSUMO DE TEMPO
	
	Vamos olhar uma operação significativa dentro do processo mostrado.
	Nesse caso, o que é mais feito são ATRIBUIÇÕES, as quais são muito
	usadas para TROCAR os elementos de lugar.
	
	Vamos ver qual é o MELHOR e o PIOR caso para o algoritmo:
	
	  linha	| ATRIBUIÇÕES
	02		|	 = 1
	03		|	 <= 1+j
	04		|	 <= j-1
	--------|--------------------------------------------------
	TOTAL	|	 <= 2j+1 <= 2*n
	
	  linha | ATRIBUIÇÕES
			|	|-- primeira iteração (inicialização)
 			|	^		^-- última iteração (não é feita)
	01		| = 1 + n - 1 	
	02-04	| <= (n-1) * 2*n <= 2*n²-2*n
	05		| = n-1
	--------|--------------------------------------------------
	TOTAL	| <= 2*n²-1 <= k*n²
						   ^^^^-- Definição de O(n²)
	
	Esse algoritmo é O(n²), ou seja, em geral, a cada vez que dobra-
	mos a amostra, temos um tempo de execução aproximadamente 4 vezes
	maior que o anterior.
	
	Não temos problema em aproximar, pela notação assimptótica, a or-
	dem de tempo do problema: para amostrar muito grandes, é o n² quem
	vai dominar, transformando a influência de outros termos em algo
	muito pequeno.
	
	CONCLUSÃO:
	O 'consumo de tempo' da função insercao NO PIOR CASO é proporcional
	a n².	
	O 'consumo de tempo' da função insercao é O(n²).
	
	-----------------------------------------------------------
	Esquematicamente, temos:
	
	|\				  /|				} O pior caso possível é
	| \				 / |				} quando tivermos a se-
	|  \			/  |				} quência em ordem decres-
	|   \			|  |\				} cente e quisermos que
	|----\			|--|-\				} ele faça o contrário.
	1ª iteração		j-ésima iteração
	 
	Faríamos 1 + 2 + ... + n-1 mudanças, = n*(n-1)/2
	------------------------------------------------------------
*/
