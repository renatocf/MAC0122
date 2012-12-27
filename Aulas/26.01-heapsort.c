/*	(1) REPRESENTAÇÃO DE ÁRVORES EM UM VETOR
	--------------------------------------------------------------------

								|	| 1
					-------------	------------
				|	| 2							|	| 3
		---------	--------			---------	--------
		|	| 4			|	| 5			|	| 6			|	| 7
		/	\			/	\			/
	 8 /	 \ 9    10 /	 \ 11	12 /
	|	| 	|	|	|	|	|	|	|	|
	
	
	Vetor linearmente:

	  0   1   2   3   4   5   6   7   8   9   10   11	12
	|///|	|	|	|	|	|	|	|	|	|	 |	  |	   |
	
	A estrutura em árvore é uma estrutura LÓGICA, enquanto o vetor
	linear é uma estrutura FÍSICA.
*/	
	
void peneira(int i, int m, int v[])
	/* 	Nessa situação, vamos trocando o elemento de lugar a cada
		iteração, de maneira a achar a posição de v[i] dentro do
		max-heap */
{
	int f = 2*i, swp;
	
	while(f <= m)
	{
		if(f < m 					/* 	Excluir quando há só 1 filho */
			&& v[f] < v[f+1]) f++; 	/* 	Vê o filho maior */
		if(v[i] > v[f]) break; 		/* 	Não faz nada se o pai é maior */
		
		/* Se chegou aqui, o pai é menor. Trocamos ele pelo filho: */
		swp = v[i]; v[i] = v[f]; v[f] = swp;
		i = f; f = 2*i;		/*	Repetimos o processo, olhando para os
								filhos a partir da nova posição do ele-
								mento que estamos querendo achar a po-
								sição. Se os filhos forem menores, tro-
								camos. Caso contrário, o laço acaba e 
								achamos a nva posição. */
	}
}

/*	(2) CONSTRUÇÃO DE UM HEAP
	--------------------------------------------------------------------
	
	Desejamos, dado uma árvore que não é um heap, criar heaps:
		
				(	)				|	Tendo dois max-heap, é bem
				/	\				|	simples construir, a par-
			   /	 \				|	tir deles, um max-heap, uti-
			  /		  \				|	lizando, para isso, a função
			 /		   \			|	'peneira' criada anterior-
		(	)			(	)		|	mente. Se analisarmos a estru-
		/%%%\			/%%%\		|	tura da árvore, podemos ver 
	   /%%%%%\		   /%%%%%\		|	que as folhas são max-heap 
	  /-------\		  /-------\		|	(já que não têm filhos).
	  
	O algoritmo fica:
*/

int constroiHeap(int i, int m, int v[])
{
		/*	|-- o primeiro que não é heap, a partir da última
			|	folha (que é um heap). Vamos construindo os heaps
			|	até o elemento '1', que significará que é um max 
			|	heap */
	for(i = m/2/*ι*/; i >= 1; i--)
		peneira(i, m, v);
	
	/******************************************************************/
	/*	RELAÇÃO INVARIANTE											  */
	/* 																  */
	/*	Em ι, vale que i+1...n são raízes de um max-heap			  */
	/******************************************************************/
	
	/******************************************************************/
	/*	CONSUMO DE TEMPO											  */
	/*																  */
	/*	De acordo com a nossa análise (grosseira), o constroiHeap	  */
	/*	é m*lg m.													  */
	/*	Porém, com uma análise mais precisa, vemos que a construção é */
	/*	O(lg m), pois o peneira é (lg m/m) e este e m. 				  */
	/******************************************************************/
}


/*	(3) ORDENAÇÃO: HEAPSORT
	
	O heapsort é um tipo de ordenação por seleção. A diferença é que ele
	usa uma ESTRUTURA DE DADOS para poder acelerar um processo.
	
	Para lembrarmos: ORDENAÇÃO POR SELEÇÃO
	|¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨¨
	|  	00		i										n-1
	|	| 38 | 10 | 20 | 44 | 50 | 50 | 55 | 60 | 75 | 85 | 99 |
	|				 	^-- Até o elemento i+1, todos os elementos
	|					 	estão ordenados.
	|	^^^^^^^^^^^^^^^^-- Procuraremos o maior elemento deste intervalo
	|				   	e o colocaremos na posição correspondente (i),
	|				   	colocando o elemento que estava em 'i' no lugar
	|				   	do maior.
	|
	|	Código da ordenação por seleção: */
/*	|*/ 
/*	|*/ void selecao (int i, int v[])
/*	|*/ {
/*	|*/ 	int i, j, max, x;
/*	|*/ 	for(i = n; /*B*/ i >= 2; i--)
/*	|*/ 	{
/*	|*/ 		for(j = i-1; j >= 1; j--;
/*	|*/ 			if(v[j] > v[max]) max = j;
/*	|*/ 		x = v[i]; v[i] = v[max]; v[max] = x;
/*	|*/ 	}
/*	|*/ }
/*	|
	|	Em /B/, vale que:
	|	(i0) v[i+1..n]
	|	(i1) v[i..i] <= v[i+1]
	|______________________________________________________________

	A operação que é realizada mais vezes é a BUSCA por um elemento
	máximo. Isso nos permite uma boa qualidade: se o vetor é um MAX-HEAP
	- então o elemento na raiz é o MAIOR de todos.
	
	Podemos, então, do código da seleção, trocá-la pela estrutura de
	dados que desejamos.
*/

void heapSort(int n, int v[])
{
	/* 	CONSTROI HEAP */

/*1*/	for(i = m/2; i >= 1; i--)
/*2*/		peneira(i, m, v);
			/*	Esse trecho é chamado de PRÉ-PROCESSAMENTO, no qual 
		 	 *	arrumamos os dados para poder fazer algo mais eficiente, 
		 	 *  ainda que não realizemos ainda a ação que desejamos. */
	
/*3*/	for(i = n; i >= 2; i--)
		{
/*4*/		x = v[i]; v[i] = v[1]; v[1] = x;
			/*	O elemento no topo do heap é o maior de todos - trocamos ele
		 	*	com o final do vetor (para que o maior fique no final) */
/*5*/		peneira(1, i-1, v);
			/*	A partir do último elemento NÃO ORDENADO (o i-ésimo foi
		 	*	arrumado anteriormente), rearrumamos o HEAP para ser um
		 	*	MAX-HEAP - isso não é tão trabalhoso, pois o único que está
		 	*	errado é o elemento NO TOPO (que era o último e foi trocado
		 	*	pelo que estava no máximo). Por esse motivo, usamos PENEIRA
		 	*	para que consigamos devolver ele à posição certa */
	}
}

/*	CONSUMO DE TEMPO
	
	linha	| repetições de execuções
	1-2		| n*O(lg n)			= O(n*lg n)
	3-4-5	| n*3 + n*O(lg n)	= O(n*lg n)
	--------|------------------------
			  = 2*n*lg n + 1
			  ∴ T(n) = O(n*lg n)
*/
