/*	PROBLEMA
	Dado um número 'x' e um vetor crescente v[0...n-1] encontrar um
índice 'm' tal que v[m] == x.

v	| 10 | 20 | 25 | 35 | 38 | 40 | 44 | 50 | 55 | 65 | 99 |
	  00		02		  04		06		  08		10

Ex: se x = 55, resp = 8
	se x = 48, resp = -1 (Resposta de erro depende da implementação)

Implementemos, agora, um algoritmo mais eficiente que a busca sequencial
para buscar elementos.
*/

int buscaBinaria(int x, int n, int *v)
{
	/* 	Nossa intenção será usar o fato de que o vetor está ordenado
		para reduzir o intervalo olhado a trechos menores, usando 
		como pivô o valor do meio.
		
		Sendo x = 48	
		v	| 10 | 20 | 25 | 35 | 38 | 40 | 44 | 50 | 55 | 65 | 99 |
			  ^e                       ^m                       ^d
		
		v	| 10 | 20 | 25 | 35 | 38 | 40 | 44 | 50 | 55 | 65 | 99 |
			                                ^e        ^m        ^d
				
		v	| 10 | 20 | 25 | 35 | 38 | 40 | 44 | 50 | 55 | 65 | 99 |
			                                ^e   ^d
											^m
			
		v	| 10 | 20 | 25 | 35 | 38 | 40 | 44 | 50 | 55 | 65 | 99 |
				                                 ^e  
												 ^d
												 ^m

		v	| 10 | 20 | 25 | 35 | 38 | 40 | 44 | 50 | 55 | 65 | 99 |
			                                	 ^e  
									   		^d
			Já verificamos TUDO: o vetor acabou.
	*/
	
	int e /*valor da esquerda*/, m /*meio*/, d /*valor da direita*/;
	e = 0; d = n-1;
	while(/*1*/ e <= d) {
		m = (e+d)/2;
		if(v[m]==x) return m; /* se 'v[m]' for o valor buscado */
		if(v[m] < x) e = m+1; /* dispensamos o trecho esquerdo, menor
								 que o valor buscado */
		else d = m-1;		  /* dispensamos o trecho direito, maior
								 que o valor buscado */
	}
	return -1; /* o valor não foi achado, e todo o vetor foi percorrido */
}

/* 	RELAÇÃO INVARIANTE
	
	Em todo o laço, vale que d-e >= 0, pois 'e' é só acrescido e 'd' é
	só decrescido. Quando d-e<0, o laço para, e isso sempre acontece. Um
	dos valores só não é modificado se achamos o valor.
	
	Em /1/ vale v[e-1] < x < v[d+1]
	// Colocamos e-1 e d+1 porque a afirmação v[e] <= x <= v[d] pode
	// ser falsa, por exemplo, se em nosso caso colocássemos x = 5.
	// Se supormos que v[e-1] = -∞ e v[d+1] = +∞, fazemos uma suposição
	// razoável (por causa do lixo) e que torna os argumentos válidos.
	
	Na última iteração, e > d e vale: x > v[e-1], x < v[d+1].
	Neste caso, saímos do laço, pois percorremos todo o vetor, e chega-
	mos ao retorno -1.
*/

/*	ANÁLISE DO TEMPO
	
	Vamos considerar, inicialmente, o que ocorre com o número de elemen-
	tos considerados na busca conforme buscamos o número.
	
	iteração | d-e+1 (conta o nº de elementos)
		1	 |	n
		2	 |	<= n/2
		3	 |	<= (n/2)/2 <= n/4 <= n/2²
	    4    |	<= n/2³ (pelo processo análogo)
	   ...   |	...
		k	 |	<= k/2^(k-1)
	
	Assim, temos que, para k iterações:
	1 <= n/2^(k-1) 					
	<=> 2^k-1 <= n 					lg - notação para base de 2
	<=> lg(2^(k-1)) <= lg n			
	<=> k+1 <= lg n					
	<=> k <= 1 + lg n = O(lg n)		
	
	O consumo de tempo do algoritmo, no pior caso, é lg n.
	O consumo de tempo do algoritmo é O(lg n).
	
	Para T(n) é O(f(n)) <=> ∃ c e n0 tais que T(n) <= c*f(n) para n >= n0
*/

/* 	Podemos fazer uma BUSCA BINÁRIA RECURSIVA para fazer tudo: */

int buscaBinaria_r(int x, int d, int e, int *v)
{
	int m;
	if(d < e) return -1; /* O problema já acabou */
	m = (e+d)/2;
	if(v[m]==x) return m; /* retornamos 'm' se achado. */
	if(v[m] < x)
		return buscaBinaria_r(x, m+1, d, v); /* dispensando a esquerda */
	return buscaBinaria_r(x, e, m-1, v); /* dispensando o lado direito */
}

/* 	Para melhorar o código, generalizando-o e o tornando mais prático,
	podemos criar um protótipo (uma 'casca') que seja mais intuitiva, 
	na forma: */
	
int buscaBinaria(int x, int n, int *v)
{
	return buscaBinaria_r(x, 0, n-1, *v);
}

/*	Tentar implementar busca binária recursiva com ponteiros */
