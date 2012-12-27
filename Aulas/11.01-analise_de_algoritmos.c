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
