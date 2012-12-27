/*	SEGMENTO DE SOMA MÁXIMA
	
	Um segmento de um vetor v[0...n-1] é qualquer subvetor v[e...d].
	
	PROBLEMA: Dado um vetor v[0...n-1] de números inteiros, determinar
	um segmento de soma máxima.
	
	Faremos 3 algoritmos agora:
*/

/* Algoritmo café-com-leite */
void segMax3(int v[], int n, int  *e, int *d, int *smax)
	/* 	A prrimeira ideia deste algoritmo é que para todo i, j, i <= j, 
		calculamos v[i] + ... + v[j]. */
{
	/*1*/	int i, j, k, s;
	/*2*/ 	s = *smax = 0; *e = *d = -1;	
	/*3*/	for(i = 0; /*1*/ i < n; i++) 
			{
	/*4*/		for(j = i; j < n; j++) 
				{
	/*5*/			s = 0; 
	/*6*/			for(k = i; k <= j; k++)
	/*7*/				s += v[k];
				
	/*8*/			if(*smax < s) 
					{
	/*9*/				*smax = s; *e = i; *d = j;
					}
				}
			}
	
	/*	RELAÇÃO INVARIANTE (PROVAR O ALGORITMO):
		
		Para provar que algo funciona, devemos mostrar algo que ocorre.
		RELAÇÃO INVARIANTE:
		em /1/ vale que v[*e...*d] é um segmento de soma máxima *e < i
		
		Sabendo que a relação vale no início de cada rodada, quer dizer
		que vale a característica na última rodada. Logo, quando i == n
		(ou seja, vamos sair do laço), temos o segmento MÁXIMO dentro do
		vetor, com o vetor todo já percorrido. Logo, provamos a relação.
	*/
	
	/*	CONSUMO DE TEMPO (EFICIÊNCIA DO ALGORITMO):
		
		Se a execução de cada linha de código consome '1 unidade' de tem-
		po, o tempo total é:
		
		linha	| Número de execuções da linha
			2	| = 1									(atribuições)
			3	| = n+1 								(1º for)
			4	| = (n+1) + n + ... + 2 + 1 =  
				| = (n+2)*(n+1)/2 < n² 					(2º for)
			5 	| = n + (n-1) + ... + 1 				(atribuição) 
				|	(na última iteração, da saída 
				|	 do laço, não é executado
				| 	 1 vez. Por isso, 'n').
			6	| < n³									(for)
				|	(executamos n vezes para cada 
				|	 n²vezes que o 2º for é execu-
				|	 tado)
			7	| < n³									(atribuição)
				|	(executamos n vezes para cada
				|	 n² vezes que o 2º for 
				|	 é executado)
			8	| < n²									(if)			
				|	(executa n² vezes no pior caso)
			9	| < n²									(atribuições)	
				|	(executa n² vezes no  pior caso)
		--------|--------------------------------------------------------
		  SOMA	| < 2*n³ + 4*n² + n + 2 < 3*n³
		
		
		Sabemos, portanto, que sendo C o nosso tempo constante para cada
		atribuição, o tempo total será < C*n³. Para 'k' elementos, tería-
		mos uma ordem de tempo C*k³. Se dobrarmos o número de elementos
		(2*k), encontramos a ordem de tempo C*(2*k)³ = 8 * C*k³
		
		Assim, a ordem de tempo é O(n³) - conforme aumentamos a entrada,
		sabemos que o tempo de cálculo aumenta n³ vezes.
		
		Essa propriedade é importante pois podemos estimar quanto tempo
		o programa demorará para executar uma entrada (e por esse motivo,
		podemos testar se o programa entrou ou não em loop infinito - o 
		que ocorre se ele passar do tempo).
	*/

	
/*********************************************************************/

	
/* Algoritmo arroz-com-feijão */
void segMax2(int v[], int n, int *e, int *d, int *smax)
	/* Agora, modificaremos o algoritmo */
{
	/*1*/	int i, j, k, s;
	/*2*/ 	s = *smax = 0; *e = *d = -1;	
	/*3*/	for(i = 0; /*1*/ i < n; i++) 
			{
	/*4*/		s = 0;	
	/*5*/		for(j = i; j < n; j++) 
				{	
	/*6*/			s += v[j];
					/* 	Agora, estamos utilizando o valor ANTERIOR para
						calcular o novo valor */
	/*7*/			if(*smax < s) 
					{
	/*8*/				*smax = s; *e = i; *d = j;
					}
				}
			}
}


	/*	RELAÇÃO INVARIANTE (PROVAR O ALGORITMO):
		
		Para provar que algo funciona, devemos mostrar algo que ocorre.
		RELAÇÃO INVARIANTE:
		em /1/ vale que v[*e...*d] é um segmento de soma máxima *e < i
		
		Sabendo que a relação vale no início de cada rodada, quer dizer
		que vale a característica na última rodada. Logo, quando i == n
		(ou seja, vamos sair do laço), temos o segmento MÁXIMO dentro do
		vetor, com o vetor todo já percorrido. Logo, provamos a relação.
	*/
	
	/*	CONSUMO DE TEMPO (EFICIÊNCIA DO ALGORITMO):
		
		Se a execução de cada linha de código consome '1 unidade' de tem-
		po, o tempo total é:
		
		linha	| Número de execuções da linha
			2	| = 1									(atribuições)
			3	| = n+1 								(1º for)
			4	| = n									(atribuições)
			5 	| = n + (n-1) + ... + 2 + 1 < n²
				|	(na última iteração, da saída 		(2º for)
				|	 do laço, não é executado
				| 	 1 vez. Por isso, 'n').
			8	| = n									(if)			
				|	(executa n vezes no pior caso)
			9	| < n									(atribuições)	
				|	(executa n vezes no  pior caso)
		--------|--------------------------------------------------------
		  SOMA	| < 2*n² + 4*n + 2 < 3*n²
		
		
		Sabemos, portanto, que sendo C o nosso tempo constante para cada
		atribuição, o tempo total será < C*n³. Para 'k' elementos, tería-
		mos uma ordem de tempo C*k². Se dobrarmos o número de elementos
		(2*k), encontramos a ordem de tempo C*(2*k)² = 4 * C*k³
		
		Assim, a ordem de tempo é O(n²) - conforme aumentamos a entrada,
		sabemos que o tempo de cálculo aumenta n² vezes.
		
		O algoritmo é, portanto, muito mais rápido que o anterior.	
	*/
	
	
/*********************************************************************/


/*
		*e		*d		j-1			} Este é o segmento de maior soma
	|	|--------|		!		|	} do trecho antes do 'j-1'
									
		*e		*d		  j			} Quando avançamos de 'j' para 'j-1',
	|	|--------|		| !		|	} o máximo ainda é este
									
						j-1			} Este é o trecho máximo desde o seg-
	|	|		|+++++++!		|	} mento máximo até 'j-1'
										
						  j			} Ao avançarmos de 'j-1' para 'j', 
	|	|		|+++++++++!		|	} achamos um novo segmento máximo
									} local.
	
	Em vez de precisarmos percorrer múltiplas vezes o vetor, nós garan-
	timos que até aquela posição temos guardado o segmento máximo até
	a origem e o segmento máximo local. Comparando o local com o máximo,
	podemos ver se este local, na verdade, é o máximo - daí sai a relação
	invariante citada.
*/

/* Novo algoritmo - intermediário para o mais eficiente */

void segMaxI(in v[], int n, int *e, int *d, int *smax)
{
	/*1*/	int i, j, k, s, sk;
	/*2*/	*smax = 0; *e = *d = -1;
	
	/*3*/	for(j = 0; /*1*/ j < n; j++)
			{
	/*4*/		s = sk = 0; i = j+1;
	/*5*/		for(k = j; k >= 0; k--)
				/* Percorreremos para trás a partir de 'j' */
				{
	/*6*/			sk += v[k];
					/* Vamos somando o trecho v[k...j] */
	/*7*/			if(sk > s)
					{
						/* Salvamos em s o maior trecho de k a j */
	/*8*/				s = sk; i = k;
					}
					
					if(s > *smax)
					{
						/* Conferimos se s é o maior trecho do total */
	/*9*/				*smax = s; *e = i; *d = j;
					}
			}
	
	
	/*	RELAÇÃO INVARIANTE (PROVAR O ALGORITMO):
		
		Para provar que algo funciona, devemos mostrar algo que ocorre.
		RELAÇÃO INVARIANTE:
		em /1/ vale que v[*e...*d] é um segmento de soma máxima *e < j
		
		Sabendo que a relação vale no início de cada rodada, quer dizer
		que vale a característica na última rodada. Logo, quando j == n
		(ou seja, vamos sair do laço), temos o segmento MÁXIMO dentro do
		vetor, com o vetor todo já percorrido. Logo, provamos a relação.
	*/
	
	
	/*	CONSUMO DE TEMPO (EFICIÊNCIA DO ALGORITMO):
		
		Se a execução de cada linha de código consome '1 unidade' de tem-
		po, o tempo total é:
		
		linha	| Número de execuções da linha
			2	| = 1									(atribuições)
			3	| = n+1 								(1º for)
			4	| = n									(atribuições)
			5 	| = 2 + 3 + 4 + ... + n = (n)-1 < n²	(2º for)
				|						  (2)
				|	(na última iteração, da saída 	
				|	 do laço, não é executado
				| 	 1 vez. Por isso, 'n').
			6	| < n²									(atribuições)		
				|	(executa n² vezes no pior caso)
			7	| < n²									(if)	
				|	(executa n² vezes no  pior caso)
			8	| < n²									(atribuições)		
				|	(executa n² vezes no pior caso)
			9	| = n									(if)	
				|	(executa n vezes)
			10	| < n									(atribuições)
		--------|--------------------------------------------------------
		  SOMA	| < 4*n² + 4*n + 2 < 3*n²
		
		
		Sabemos, portanto, que sendo C o nosso tempo constante para cada
		atribuição, o tempo total será < C*n³. Para 'k' elementos, tería-
		mos uma ordem de tempo C*k². Se dobrarmos o número de elementos
		(2*k), encontramos a ordem de tempo C*(2*k)² = 4 * C*k³
		
		Assim, a ordem de tempo é O(n²) - conforme aumentamos a entrada,
		sabemos que o tempo de cálculo aumenta n² vezes.
		
		O algoritmo é, portanto, muito mais rápido que o anterior.	
	*/
	
	
/*********************************************************************/
/*		OS ALGORITMOS ANTERIORES FORAM FEITOS NA AULA ANTERIOR		 */
/*********************************************************************/

/* 	Problema
	
	Dado um vetor v[0...n-1] de números inteiros determinar um segmento de
soma máxima:
	 00								n-1
	|  |	|--|--|--|--|--|--|		| |
			*e				 *d
*/

void segMaxI(int v[], int n, int *e, int *d, int *smax)
{
	int i, j, k, sk, s;
	s = *smax = 0; *e = *d = -1;
	for(i = j = 0; /*1*/ j < n; j++)
	{
		s = sk = v[j]; i = j;
		for(k = j-1; k >= 0; k--)
		{
			sk += v[k];
			if(sk > s) { s = sk; i = k; }
		}
		if(/*2*/s > *smax)
		{
			*smax = s; *e = i; *d = j;
		}
	}
}

/*	Até o momento, tivemos 3 algoritmos:
	O primeiro, de proporção de aumento de tempo n³, tinha 3 laços: um pa-
	ra a primeira posição, um para a segunda e outra para somar os elemen-
	tos da primeira até a última posição.
	A relação invariante era que no início da iteração, valia que as va-
	riáveis '*e' e '*d' armazenavam o segmento máximo do início até o pon-
	to 'n'. Na última iteração, o segmento máximo do vetor todo também
	está armazenado no trecho.
	
	O segundo, de proporção de aumento de tempo n², tinha apenas 2 laços:
	em vez de recalcular o segmento várias vezes, usava a memória para 
	armazenar o valor da soma dentro do 2º laço.
	(A eficiência foi aumentada apenas evitando o recálculo).
	
	Mostraremos, agora, porque este terceiro algoritmo é muito mais efi-
	ciente que os anteriores:
	
			*e *d - segmento de soma máxima até o momento
	| |		|---|		| |			|
						j-1 - elemento j-1
	
	Quando avançarmos para o elemento j-1, temos duas possibilidades:
	
			*e *d - segmento máximo até o momento
	| |		|---|		  |	|		|
						   j - elemento 'j'
		- Neste caso, adicionamos 'j' e o segmento máximo continua o mesmo.
	
					*e	   *d
	| |		|	|	|-----|-|	|		|
						   j - elemento 'j'
		- Neste caso, adicionamos 'j' e o segmento máximo passa a ser o 
		  novo.
	
	A ideia do algoritmo é, então, armazenar o segmento máximo até o 
	elemento 'j'. A partir de 'j', vamos voltando para trás, de modo
	a tentar encontrar o segmento máximo até a posição 'j'. Se for
	maior que o atual máximo, ele é atualizado. Caso contrário, ele 
	e mantido. Este processo, então, vai se repetindo.
*/


void segMaxI(int v[], int n, int *e, int *d, int *smax)
{
	int i, j, k, sk, s;
	s = *smax = 0; *e = *d = -1;
	for(i = j = 0; /*1*/ j < n; j++)
	{
		s = sk = v[j]; i = j;
		for(k = j-1; k >= 0; k--)
			/* Calculando o segmento máximo que termina em 'j' */
		{
			sk += v[k];
			if(sk > s) { s = sk; i = k; }
		}
		if(/*2*/s > *smax)
			/* 	Comparamos o segmento máximo local (que termina em 'j')
				com o maior até aquele momento */
		{
			*smax = s; *e = i; *d = j;
		}
	}
}


/* 	Este algoritmo continua sendo O(n²), pois continua a executar um laço
	dentro de o laço (a análie mais cuidadosa deste algoritmo auxilia nis-
	so). Para melhorarmos este tempo, devemos tentar EVITAR recálculos, Ou
	seja, tendo calculado o segmento de soma máxima até j-1, devemos ver se 
	este segmento tem algo para ajudar no recálculo:
	
				segmento máximo até j-1
	|		| |	|-------| |				|
				i		j-1
	
			   ^-- 	Este elemento é negativo, pois caso contrário estaria 
					neste segmento máximo.
			 ^-^-- 	A soma de ambos os segmentos é negativa, pois caso 
					contrário estaria no segmento máximo.
	 ^-^ ... ^-^--  Assim, tudo que está para trás deste segmento é nega-
					tivo (pois caso contrátio seria adicionado).
	
	Assim, temos que em /1/ vale que:
	* para k = 0, 1,2, ... , i-1 vale que:
		v[k] + v[k+1] + ... + v[i-1] <= 0
	
	* para k = i, i+1, ... , j-1, vale que:
		v[i] + v[i+1] + ... + v[k] >= 0
	
	
	Assim, temos que, a partir do segmento máximo até a posição j-1, 
	não teremos pedaços antes que o segmento máximo atual, pois 
	pela definição do segmento máximo, ele estaria neste segmento
	máximo do trecho. Isso, então, é impossível:
	
			 segmento máximo
				!		!
	|		| |	|-------| |				|
				i		j-1
	
			!segmento máximo!
			!				!
	|		|-|-|-------|-|-|				|
				i		   j
	
	Modificendo o algoritmo da seguinte maneira, já o melhoraríamos:
*/


void segMaxI(int v[], int n, int *e, int *d, int *smax)
{
	int i, j, k, sk, s;
	s = *smax = 0; *e = *d = -1;
	for(i = j = 0; /*1*/ j < n; j++)
	{
		s = sk = v[j]; i = j;
						/* 	Trocamos o 0 por 'i', pois este será o seg-
							tudo que havia antes não acrescenta nada */
		for(k = j-1; k >= /**/i/**/; k--)
			/* Calculando o segmento máximo que termina em 'j' */
		{
			sk += v[k];
			if(sk > s) { s = sk; i = k; }
		}
		if(/*2*/s > *smax)
			/* 	Comparamos o segmento máximo local (que termina em 'j')
				com o maior até aquele momento */
		{
			*smax = s; *e = i; *d = j;
		}
	}
}
	
/*	Observemos, agora, que há uma propriedade no segmento analisado: es-
	tamos obrigando, sempre, o 'j' a estar DENTRO do segmento. Mas o 'j'
	pode ou não contribuir para o segmento. Nesse caso, temos:
		
			  segmento máximo
				!		  !
	|		| |	|-------|-|				|
				i		j-1
	
	* segmax + j > 0;
	  Teremos que o segmento de soma máxima vai de i até j-1 e acrestenta-
	  mos ao segmento de soma máxima o 'j'.
	
	* segmax + j< 0;
	  Neste caso, o 'j' não participará do segmento máximo.
	
	Este raciocínio está correto, mas tornamos OBRIGATÓRIA a presença de
	'j' no segmento máximo até o ponto 'j'. Então, podemos, em vez de 
	analisar a soma 'segmax + j', podemos atualizar a segmax e comparar
	se devemos somá-la com o 'j':
	
	* segmax > 0:
		Somamos v[j] ao segmento máximo do trecho.
	* segmax < 0;
		Isso será possível porque, necessariamente, v[j] estará no seg-
		mento máximo. Quando começamos o vetor, se v[j] for menor que 0,
		querendo ou não ele estará no segmento máximo. Se ele for maior
		que 0, será parte do segmento máximo. Vamos analisando portanto,
		o segmento até j incluindo 'j', e salvando os segmentos máximos
		até aquele 'j' em uma variavel SEPARADA.
	
	Com este raciocínio, podemos trocar o 2º for por um 'if':
*/

	
void segMaxI(int v[], int n, int *e, int *d, int *smax)
{
	int i, j, k, sk, s;
	s = *smax = 0; *e = *d = -1;
	for(i = j = 0; /*1*/ j < n; j++)
	{
		if(s < 0) {
			s = v[j]; i = j; /* Atualizamos o trecho, que só contêm 'j' */
		} else s+=v[j];		 /* Vamos somando 'j' e mandamos 'i' */
		
		if(/*2*/s > *smax)
			/* 	Comparamos o segmento máximo local (que termina em 'j')
				com o maior até aquele momento */
		{
			*smax = s; *e = i; *d = j;
		}
	}
}

/*
	NOTAÇÃO ASSINTÓTICA
	
	Sejam T(n) e f(n) funções dos inteiros nos reais. 
	Dizemos que T(n) é O(f(n)) se existem constantes positivas tais
	que T(n) <= c*f(n).
	
	Basicamente, quando achamos uma função de tempo, olhamos apenas para
	o tempo de MAIOR potência - ele descreverá melhor a ordem de tempo,
	pois qualquer função desta ordem, em qualquer momento, SUPERARÁ uma 
	função de potência menor.
	
	Ou seja, qualquer algoritmo O(n³) terá consumo maior que um n²+100000,
	pois para algum 'n', O(n³) superará o n²+100000. Por isso, quaisquer
	constantes são dispensáveis.
	
	A notação assintótica é utilizada PORQUE, geralmente, os problemas 
	computacionais envolvem números muito grandes, nos quais a influência
	de termos de ordens menores que a máxima potência vão sendo dispensá-
	veis.
	
	NOMES DAS CLASSES
	
	O(1)		| cosntante
	O(lg n)		| logarítmica
	O(n)		| linear
	O(n logn)	| n logn
	O(n²)		| quadrático
	O(n³)		| cúbico
	O(2^n)		| exponencial
	O(a^n)		| exponencial
