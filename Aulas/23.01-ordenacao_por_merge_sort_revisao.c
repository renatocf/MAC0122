/*	Usando os princípios de intercalação vistos anteriormente, podemos
	utilizar uma RECURSÃO e o princípio de DIVIDIR-E-CONQUISTAR para 
	podermos pegar partes menores do nosso problema (o vetor) para
	ordená-lo. Então, o que faremos é pegar um vetor de 'n' elementos
	e dividí-lo em partes cada vez MENORES, até chegarmos a 1 elemento
	(pois 1 elemento sempre está ordenado). Aí, vamos intervalando.
	
	Este algoritmo é chamado MERGE SORT:
*/


void intercala(int p, int q, int r, int v[])
{
	int i, j, k, *w; /* vetor auxiliar */
	w = mallocSafe( (r-p) * sizeof(int));
				/*  ^^^^^-- Tamanho do trecho de vetor */
	for(i = 0, k = p; k < q; i++, k++)
		w[i] = v[k];
		 /* ^^^^^-- j é a última posição de 'w': ela é sempre -1*/
	for(j = r-p-1; k < r; j--, k++)
		w[j] = v[k];
	
	/*  	   ^^^^^-- Início do vetor */
	i = 0; j = r-p-1;
	for(k = p; k < r; k++)
		if(w[i] < w[j])
			v[k] = w[i++];
		else v[k] = w[j--];
	
	/* 	Vamos percorrendo o vetor, sendo que comparamos os menores ele-
		mentos e vamos comparando cada um deles. */
	
	free(w);
}
/*	A intercalação é de complexidade O(n) */



void mergeSort(int p, int r, int v[])
{
/*1*/	if(p < r-1)
		/* 	Temos 'n' elementos, sendo n = r-p (o nº de elementos do tre-
			cho). Preciamos que n > 1, ou 1 < n, ou 1 < r-p, ou p < r-1. 
			O algoritmo para quando houver 1 elemento no vetor chamado. */
		{
/*2*/		q = (r-p)/2;
/*3*/		mergeSort(p, q, v); /* Lado esquerdo */
/*4*/		mergeSort(q, r, v); /* Lado direito */
/*5*/		intercala(p, q, r, v); /* Intercalação */
		}
}


/*	CORREÇÃO DO ALGORITMO
	
	Este algoritmo funciona porque o 'intercala' funciona.
	Nós podemos justificar pela indução:
	* Base: o algoritmo funciona para 1 elemento, pois quando o vetor
			tem 1 elemento, ele está ordenado..
	* Passo: Suponhamos que o algoritmo funciona para 'n-1' elementos.
			 (Os 'n-1' elementos estão ordenados). Mostremos que ele 
			 funciona para 'n' elementos:
		Como 'n-1' está ordenado, o algoritmo volta a partir dele.
		Como o n-ésimo elemento é único, ele está ordenado.
		
		Como a intercalação está correto, ele ordena todo o vetor.
		Logo, o vetor acaba ordenado.
	Assim, provamos que o algoritmo está correto.
*/


/*	CONSUMO DE TEMPO DO ALGORITMO
	
	Seja T(n) = consumo de tempo para ordenar 'n' elementos
	
	linha	| 
	1		| = O(1)
	2		| = O(1)
	3		| = T( [n/2] )
	4		| = T( [n/2] )
	5		| = O(n)
	TOTAL	| = T([n/2]) + T([n/2]) + O(n)
	
	Não temos, inicialmente, como calcular T([n/2]) ou T([n/2]).
	Vamos analisar, então, a árvore de recursão, analisando APENAS
	o que cada patamar realiza:
	
				|---------------|---------------|					O(n)
				//								\\					
		|-------|-------|				|-------|-------|			O(n/2)
			//		\\						//		\\				
	|---|---|		|---|---|		|---|---|		|---|---|		O(n/4)
	//		\\		//		\\		//		\\		//		\\		
	|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|	O(n/8)
									...								...
	|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|	O(1)
	
	Cada bloco separado realiza, por si mesmo, a principal ação que 
	é a de intercalar os elementos, sendo que o último patamar rea-
	liza a ação de não fazer nada (pois 1 elemento já é intercalado).
	
	Somando tudo, temos que o primeiro patamar tem 1 elemento de O(n),
	o segundo 2 elementos de O(n/2), ..., n elementos de O(1). Ou
	seja, sendo 'k' o número de patamares, temos:
	
	T(n) = 1*O(n) + 2*O(n/2) + ... + n*O(1) } k elementos
	T(n) = O(n) + O(n) + ... + O(n) 		 } k elementos
	∴ T(n) = k*O(n)
	
	Vamos, agora, analisar o valor de k:
	Se o vetor tem 'k' elementos, queremos dividir 'n' por 2 múltiplas 
	vezes até que só haja 1 elemento (ou tentar chegar o mais próximo
	disso). Então:
	
	(n/2)/2/2/2/2/2.../2 = 1
	n/2^k = 1 ↔  2^k = 1 ↔  k = lg n
	
	Logo, temos que 'k' vale aproximadamente lg n.
	Assim, T(n) = k*O(n) = lg n * O(n)
	Que é definido por O(n*lgn)
	
	Assim, o Merge Sort é de complexidade O(n*lgn)
*/
		
					
