/*	PROBLEMA
	Dado um número 'x' e um vetor crescente v[0...n-1] encontrar um
índice 'm' tal que v[m] == x.

v	| 10 | 20 | 25 | 35 | 38 | 40 | 44 | 50 | 55 | 65 | 99 |
	  00		02		  04		06		  08		10

Ex: se x = 55, resp = 8
	se x = 48, resp = -1 (Resposta de erro depende da implementação)

A alternativa mais trivial para buscar é criar um laço para percorrer o
vetor todo, de modo a encontrar o valor a ser achado. Este algoritmo é
chamado de 'busca sequencial'.
*/

int buscaSequencial(int x, int n, int *v)
{
	int m = 0;	/* Variável auxiliar para percorrer */
	while(m < n && v[m] != x) m++;
	
	if(m == n) return -1; /* Vetor chegou no final */
	return m;
}

/* 	Podemos, já de início, melhorar um pouco o algoritmo, somente alteran-
	do a condição: como o vetor está ordenado, podemos simplesmente parar
	de percorrer assim que acharmos alguém MAIOR que o número buscado. */

int buscaSequencial(int x, int n, int *v)
{
	int m = 0;	/* Variável auxiliar para percorrer */
	while(/*1*/ m < n && x > v[m]) m++;
	
	if(m < n && v[m]==x) return m; 
		/* 	Precisamos verificar de m < m porque, para a última posição,
			acrescentamos 1 e encontramos o valor 'n+1' armazenado em 
			'm'. Isso acarretaria em devolvermos 'n+1', um valor inválido
			para o caso. */
	return -1;
}

/*	RELAÇÃO INVARIANTE
	
	Em /1/, para cada iteração, vale que: v[m-1] < x
	No início da última iteração, m >= n ou x <= v[m].
	Se m >= n, temos que o vetor acabou e o valor não foi encontrado.
	
	v[m-1] < x <= v[m]
	Se v[m] == x, retornamos m. Caso contrário, ultrapassamos o valor, 
	e nãõ encontramos 'x' no vetor ordenado.
*/

/*	CONSUMO DE TEMPO						
											| n + 4 <= c, n >= n0
	linha | número de execuções				| Supondo c == 2
	------|-----------------------			| n + 4 <= 2*n
	  1	  | = 1		| T(n) é O(f(n)) <=>	| Valerá para n >= 8
	  2	  | <= n+1	| ∃ c e n0 tais que 	| 
	  3	  | = 1		| T(n) <= c*f(n)		| Assim, a partir de 'n'
	  4	  | = 1		| para n >= n0			| elementos, teremos a
	------------------------------			| relação assimptótica
		  | <= n+4 = O(n) é linear			| válida.
*/
