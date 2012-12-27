	void insercao(int n, int v[])
	{
		int i, j, x;
/*1*/	for(i = 1; /*inv*/i<n; i++)
		{
/*2*/		x = v[i];
/************************************************************/
/*3*/												/* Trecho a */
/*4*/		for(j = i-1; j >= 0 && v[j] > x; j--)	/* ser subs-*/
/*5*/			v[j+1] = v[j];						/* tituído  */
/************************************************************/
/*6*/		v[j+1] = x;
		}
	}

/*	A relação invariante da inserção é que até o ponto 'i' todos os
 *	vetores estão ordenados. 
 *	Vamos retornando até achar o ponto de inserir o elemento. Porém,
 *	para isso utilizamos uma BUSCA SEQUENCIAL. Ela, claramente, pode ser
 *	melhorada, utilizando, em vez dela, uma BUSCA BINÁRIA. Implementemos
 *	o algoritmo correspondente: */

/*	A busca binaria recebe (x, i, v) e devolve um índice 'j':
		v[j] < x < v[j+1]	- RELAÇÃO INVARIANTE */
	
	void insercaoiBinaria(int n, int v[])
	{
		int i, j, x;
/*1*/	for(i = 1; /*inv*/i<n; i++)
		{
/*2*/		x = v[i];
/*3*/		j = buscabinaria(x, i, v); /* Implementando a busca binaria*/
/*4*/		for(k = i; k > j+1; k--)	
/*5*/			v[k] = v[k-1];						
/*6*/		v[j+1] = x;
		}
	}
	
int buscaBinaria(int x, int n, int v[])
	/* 	RELAÇÃO INVARIANTE:
		Em \%inv%\ vale que:
		| |<|<|<|<|    |*|    |>|>|>|>| |
		v[e] < x <= v[d] */
{
	int e, m, d;
	e = -1; d = n; /* extremos do vetor */
	while(/*inv*/ )
	{
		m = (e + d) / 2; /* meio */
		if(v[m] < x) e = m; /* atualiza o lado esquerdo */
			/* 	buscamos para ver, de acordo com a relação invariante,
				até que número do meio é menor que 'x'. */
		else d = m; /* atualiza o lado direito */
	}
	
	return e;
		/* 	Retornamos o lado esquerdo porque ele sempre será estrita-
			mente MENOR que o número olhado. Assim, quando "procurarmos"
			um número (apesar de estarmos querendo a SUPOSTA posição de-
			le, e não saber se ele está ou não no vetor, como na busca 
			binária tradicional), acabaremos devolvendo a posição do
			número ANTERIOR à possível posição do número. Ou seja, o nú-
			mero devolvido é o estritamente menor que o buscado. Isso,
			porém, torna o algoritmo de inserção INSTÁVEL, pois a ordem
			de aparecimento dos números não é preservada (só seria se
			trocássemos 'if(v[m] < x)' por 'if(v[m] <= x)' - mas deve-
			ríamos, aí, trocar a relação invariante e alguns índices.*/
}

/*	ANÁLISE DE COMPLEXIDADE
	
	Busca Binária: 	Consumo de tempo proporcional a lg n, O(lg n)
					no pior ou no melhor caso.
	
	Inserção Binária:
	
	PIOR CASO
	(vetor na ordem inversa)
	Linha	| consumo de tempo
	  1		| = n								= n
	  2		| = n (sem considerar constantes)	= n
	  3		| = lg1 + lg2 + lg3 + ... + lg n 	~ n*lg n
	  4		| <= 1 + 2 + 3 + ... + n-1 			~ n²
	  5		| <= n²								= n²
	  6		| = n								= n
	--------|---------------------------------------------
			| <= 2*n² + n*lg + 3n = O(n²)
	
	MELHOR CASO
	(vetor ordenado)
	Linha	| consumo de tempo
	  1		| = n								= n
	  2		| = n (sem considerar constantes)	= n
	  3		| = lg1 + lg2 + lg3 + ... + lg n 	~ n*lg n
	  4		| <= 1 + 1 + 1 + ... + 1 			~ n
	  5		| = 0 (acaba não sendo executado)	
	  6		| = n								= n
	--------|---------------------------------------------
			| <= n*lg + 4n = O(n*lg n)
	
	Em comparação com a INSERÇÃO normal, temos que no MELHOR caso,
	a inserção normal ganha (pois é constante). A inserção binária
	tem um "problema" (algo muito relativo, pois depende da entra-
	da colocada): ele roda sempre, na busca, em 'lg n', indepen-
	dente da ordenação do vetor.
*/
