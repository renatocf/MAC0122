/*	REPRESENTAÇÃO DE ÁRVORES EM UM VETOR
	
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
	{	}
	^^^^^-- A posição 0 será ignorada
	
	--------------------------------------------------------------------
	
	Chamaremos estas árvores de árvores binárias, pois cada elementos
	leva a dois novos. Consideraremos, por utilidade, que a árvore
	tem m = 12 elementos, começando o índice por '1' (ignoraremos a
	posição 0).
		v[1..m] é um vetor representado uma árvore binária.
	
	--------------------------------------------------------------------
	PAIS E FILHOS

		Diremos que para qualquer índice ou nó 'i':
		* i/2 é o PAI de 'i';
			Usando a divisão truncada de C, que na realidade é o 
			operador 'chão' (arredondamento para baixo).
		
		* 2*i é o FILHO ESQUERDO de 'i';
		
		* 2*i+1 é o FILHO DIREITO de 'i';
		
		* Um nó 'i' tem filho esquerdo se 2*i <= m;
			Em geral, se não há filho esquerdo, o elemento não tem 
			filhos (porque o filho direito é 2*i+1, mas 2*i não
			existe).
		
		* Um nó 'i' tem filho direito se 2*i + 1 <= m;
			Tendo filho direito, o elemento tem dois filhos (como 
			tem o elemento 2*i+1, ele tambem tem o 2*i);
	
	--------------------------------------------------------------------
	RAIZ E FOLHAS
	
	O nó 1 não tem pai e é chamado de RAIZ.
	Um nó 'i' é uma folha se não tem filhos, ou seja, 2*i > m;
	
	--------------------------------------------------------------------
	NÍVEIS
	
	* Cada nível 'p' tem, exceto talvez o último, tem exatamente 
	2^p nós. Cada elemento do nível tem a forma:
	
					2^p, 2^p+1, 2^p+2, ... , 2^(p+1)-1
	
		Ex: para o nível  p=2:
						2², 2²+1, 2³+2, 2³-1
						||   ||    ||    ||
						04   05    06    07
	
	* A qual nível percente o número 'i'?
		2^p <= i < 2^(p+1)
		=> lg 2^p <= çg i <= lg 2^(p+1)
		=> p <= lg i < p+1 
		∴ p = chão(lg i)
	
	* número de níveis da árvore:
		= chão (lg m) + 1 --> somamos '1' porque o primeiro nível é '0'
		  ^^^^^^^^^^^
		  |-- pois o 'm' é o último elemento, e pertence ao último
		  	  nível existente (esteja ele completo ou não)
	
	--------------------------------------------------------------------
	HEAP
	
	Um vetor v[1..m] é um MAX-HEAP se:
	
					v[i/2] >= v[i], ∀ i = 2, 3, ... , m
					(pai)  >= (filho)
	
	De uma forma geral, v[j..m] é um max-heap se:	
				 v[i/2] >= v[i]		(pai)  >= (filho)
	sendo i = 2*j, 2*j+1, 4*j, 4*j+1, ...

	Ou seja, cada subárvore do max-heap é um max-heap.
	--------------------------------------------------------------------
	
	Assim como o mergeSort tinha a função 'intercala' e o quickSort
	tem a função 'separa', o heapSort terá a função 'peneira':
	
	FUNÇÃO PENEIRA
	
	void peneira(int i, int m, int v[])
					 ^		^		^ vetor
					 ^		^ final do vetor (número de elementos dele)
					 ^-- raiz
	
	Há 3 casos possíveis, dentro da estrutura:
	
							(	)
							/	\
						   /	 \
						  /		  \
						 /		   \
					(	)			(	)
					/%%%\			/%%%\		} Representação para que
				   /%%%%%\		   /%%%%%\		} há subárvores abaixo
				  /-------\		  /-------\		} deste nível.
				  
				  
				( 17)				|				( 15)
				/	\               |				/	\
			   /	 \              |			   /	 \
			  /		  \             |			  /		  \
			 /		   \            |			 /		   \
		( 15)			( 16)       |		( 16)			( 17)
		/%%%\			/%%%\       |		/%%%\			/%%%\  
	   /%%%%%\		   /%%%%%\      |	   /%%%%%\		   /%%%%%\ 
	  /-------\		  /-------\     |	  /-------\		  /-------\
	  								|
	  Neste caso, a árvore já segue	|	Neste caso, precisaríamos trocar
	  a lógica do MAX-HEAP			|	o 16 pelo 15, mas como o 17 é 
	  								|	maior que ele, precisamos trocá-
	  								|	lo, assim, para evitar repeti-
	  								|	ções, precisamos ver se o máximo
	  								|	é maior.
	
	O coração e qualquer algoritmo que manipula um max heap é uma função
	que recebe um vetor v[1..m] e um índice 'i' tais que os subvetores 
	v[2*i...m] e v[2*i+1...m] são máximos e rearranja v[1..m] de modo 
	que v[i..m] seja um max heap.
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

void peneira2(int i, int m, int v[])
{
/*1*/	int f = 2*i, x = v[i];
		/* 	Nesse caso, guardamos v[i], achamos a posição dele e só
			trocamos no último caso */
/*2*/	while(f <= m)
		{
/*3*/		if(f < m 					/* 	Excluir quando há só 1 filho */
				&& v[f] < v[f+1]) f++; 	/* 	Vê o filho maior */
/*4*/		if(v[i] > v[f]) break; 		/* 	Não faz nada se o pai é maior */
		
/*5*/		v[i] = v[f];
/*6*/		i = f; f = 2*i;	/* 	Quando fazemos isso, reiniciamos o 
								processo, de modo que a partir da 
								nova posição provável do elemento
								armazenado em 'x', olhamos para os 
								filhos daquela posição tentando en-
								contrar se o 'x' deve descer mais 
								um nível. Quando os filhos forem me-
								nores, paramos. */
	}
/*7*/	v[f/2] = x;
}

/*	CONSUMO DE TEMPO
	
	linhas	| todas as execuções
	1		| = 1
	2		| <= lg m + 1	
	3		| <= lg m
	4		| <= lg m
	5		| <= lg m
	6		| <= lg m
	7		| = 1
	--------|--------------------------
			| <= 5*lg m + 3 = O(lg m)
	
	Assim, o consumo de tempo da peneira é lg m, que é o número de pata-
	mares da árvore - e o máximo de vezes que o 'x' pode descer.
*/
