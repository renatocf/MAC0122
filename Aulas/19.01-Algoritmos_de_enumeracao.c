/*	PROBLEMA DAS 'N' RAINHAS
	
	Problema: Dado 'n' determinar todas as maneiras de dispormos 'n' ra-
	inhas em um tabuleiro de dimensão n x n de maneira que elas NÃO se
	ataquem.	
	
	MOVIMENTOS DA RAINHA:	|	| ^	|	|
							|	| | |	|
							| <-|-Q-|-> |
							|	| |	|	|
							|	| ^ |	|
	
		
		|---|---|---|---|---|---|---|---|	
	1	|	|	|	| Q	|	|	|	|	|	
		|---|---|---|---|---|---|---|---|	
	2	|   |   |   |   |   |   | Q |   |	Exemplo para 8 rainhas
		|---|---|---|---|---|---|---|---|	de como realizar um po-
	3	|   |   | Q |   |   |   |   |   |	sicionamento.
		|---|---|---|---|---|---|---|---|	
	4	|   |   |   |   |   |   |   | Q |	
		|---|---|---|---|---|---|---|---|	
	5	|   | Q |   |   |   |   |   |   |		
		|---|---|---|---|---|---|---|---|	
	6	|   |   |   |   | Q |   |   |   |	
		|---|---|---|---|---|---|---|---|	
	7	| Q |   |   |   |   |   |   |   |	
		|---|---|---|---|---|---|---|---|	
	8 	|   |   |   |   |   | Q |   |   |	
		|---|---|---|---|---|---|---|---|	
		  1	  2   3   4   5   6   7   8 
	
	Primeiro, podemos pensar em alguns exemplos pequenos:
	
	- n = 1		- n = 2		- n = 3			- n = 4
							
		|---|	|---|---|	|---|---|---|	|---|---|---|---|
		| Q	|	| Q |   |	| Q |	|	|   | Q	|	|	|	|
		|---|	|---|---|	|---|---|---|   |---|---|---|---|
				| * | * |	| *	| *	| Q	|   | *	| *	| Q	|	|
      POSSÍVEL	|---|---|	|---|---|---|   |---|---|---|---|
							| *	| *	| *	|   | *	| *	| *	| *	|
				|---|---|	|---|---|---|   |---|---|---|---|
				|	| Q |					|	|	|	|	|
				|---|---|	|---|---|---|	|---|---|---|---|
				| *	| *	|	|	| Q	|	|
				|---|---|	|---|---|---|	|---|---|---|---|
							| *	| *	| *	|   |	| Q	|	|	|
                            |---|---|---|   |---|---|---|---|
                            |	|	|	|   | *	| *	| *	| Q	|
                            |---|---|---|   |---|---|---|---|
							                | Q	| *	| *	| *	|
							|---|---|---|	|---|---|---|---|
                            |	|	| Q	|   | *	| *	| Q	| *	|
                            |---|---|---|   |---|---|---|---|
                            | Q	| *	| *	|	
                            |---|---|---|		 POSSÍVEL
                            | *	| *	| *	|
                            |---|---|---|
	
	Existem (64) ~= 44 bilões de maneiras de dispormos 8 peças em um 
			(08)
	tabuleiro 8x8. 
	Suponha que para verificar se uma configuração é válida gastamos
	10^-3s.
	
	44.000.000 seg ~= 733.333 min ~= 12.222 horas ~= 509 dias
	
	-----------------------------------------------------------------
	
	Como cada linha pode conter apenas uma rainha, 'i' é colocada na
	coluna s[i] da linha i.
	
	Existem 8^8 = 16.777.216 possibilidades. Para verificá-las, gasta-
	ríamos (com 1 seg para cada verificação), gastaríamos:
	16.777.216 ~= 285 min ~= 1,8 horas
	
		|---|---|---|---|---|---|---|---|		|---| }	
	1	|	|	|	| Q	|	|	|	|	| 1		| 4	| }	
		|---|---|---|---|---|---|---|---| 		|---| }	
	2	|   |   |   |   |   |   | Q |   | 2		| 7 | }	Esta é a matriz 
		|---|---|---|---|---|---|---|---| 		|---| }	com a configura-
	3	|   |   | Q |   |   |   |   |   | 3		| 3 | }	ção das linhas.
		|---|---|---|---|---|---|---|---| 		|---| }	
	4	|   |   |   |   |   |   |   | Q | 4		| 8 | }	Existem 8^8 con-
		|---|---|---|---|---|---|---|---| 		|---| }	figurações pos-
	5	|   | Q |   |   |   |   |   |   | 5		| 2 | }	síveis para ca-
		|---|---|---|---|---|---|---|---| 		|---| }	da caso.
	6	|   |   |   |   | Q |   |   |   | 6		| 5 | }	
		|---|---|---|---|---|---|---|---| 		|---| }	
	7	| Q |   |   |   |   |   |   |   | 7		| 1 | }	
		|---|---|---|---|---|---|---|---| 		|---| }	
	8 	|   |   |   |   |   | Q |   |   | 8		| 6 | }	
		|---|---|---|---|---|---|---|---|		|---| }	
		  1	  2   3   4   5   6   7   8  	      8 	
	
	--------------------------------------------------------------------
	
	No entanto, não pensamos em todas as possibilidades (só eliminamos
	as possibilidades da linha, mas há outras a serem sliminadas (como
	colunas ou diagonais). Assim, temos 8! possibilidades.
	
	Se cada uma das 40.320 possibilidades (8!) demorar 10^-3 segundos,
	demoraríamos apenas cerca de 10 seg para fazer todos os testes.
	
	--------------------------------------------------------------------
	
	Façamos, agora, algum teste para extrairmos dele alguma lógica sis-
	temática para os testes:
	
	 	|---|---|---|---|	|---|			  +----( )				
     1	|  	|	|	|	|	|	|			 /
    	|---|---|---|---|	|---|	       1/ 
     2	|  	|  	|  	|	|	|	|	      ( )-------------------+
    	|---|---|---|---|	|---|	     / | \					|
     3	|  	|  	|  	|  	|	|  	|	   1/ 2| 3\					|
    	|---|---|---|---|	|---|	  (x) (x) ( )------+	   ( )
     4	|	|	|	|	|	|	|	         / | \     |	   / \
    	|---|---|---|---|	|---|	       1/ 2| 3\   4|	 1/	 2\
		  1	  2   3   4		  s	 	      (x) (x) (x) (x) 	 (x)  ( )
	
	Nós vamos fazendo tentaticas cirando estas estruturas chamadas de
	'árvores de opções'. Este tipo de processo é chamado, em inglês, de
	'backtracking', pois a cada erro, voltamos para trás e refazemos
	o caminho a partir do nódulo passado. Por isso, também são chamados
	de algoritmos de 'tentativa e erro'.
	
	Pela função de CONTAR o número de possibilidades, são conhecidos
	também como 'algoritmos de enumeração'. 
	
	-------------------------------------------------------------------
	
	Criemos, agora, um pedaço de código para criar este algoritmo:
*/

/** BIBLIOTECAS *******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "mallocSafe.h"

/** DEFINIÇÕES ********************************************************/
#define TRUE 1
#define FALSE 0


/** FUNÇÕES AUXILIARES ************************************************/
void mostreTabuleiro(int n, int i, int *s);
	/* 	Imprime o tabuleiro com o tamanho 'n', a partir da estrutura 
		's', com a última peça em 'i'. */

int solucaoParcial(int i, int *s);
	/* 	Cria uma solução parcial para a linha 'i', já tendo a confi-
		guração 's' do tabuleiro. */



/** FUNÇÃO PRINCIPAL **************************************************/
void nRainhas(int n)
{
	int testouTudo = FALSE;	/*  Variável pseudo-booleana para 
								testar se tudo já foi feito		  */
	int i;					/* 	Índice da linha 'i' 			  */
	int j;					/*	Índice da coluna 'j' 			  */
	int nJogadas;			/*	Quantidade de jogadas feitas 	  */
	int nSolucoes;			/*	Quantidade de soluções encontra-
								das pelo programa				  */
	int *s 					/*	Armazena os valores das colunas 
								(usaremos 'n+1' para que o primei-
								ro índice seja '1', facilitando a 
								leitura do código. 				  */
	
	/** INICIALIZAÇÕES ************************************************/
	s= mallocSafe((n+1)*sizeof(int));
	i = j = 1;
	
	/*	RELAÇÂO INVARIANTE: Até a posição i-2, todas as posições 
		são garantidamente válidas. */
	while(!testouTudo) 	/* 	Forma econômica para while(testouTudo ==
							FALSE) */
	{
		/*if(i == 1 && j == n+1) \%caso 1%\ */
		if(i == 0) /* caso 1 */
			/* 	Ele roda uma vez a mais que o caso acima. Porém, este
				faz testes a menos. Ele funciona porque voltamos até
				o ponto do passado em que, na realidade, tentamos 
				testar uma linha que NÃO existe. */
		{
			testou Tudo = TRUE;
		}
		else if(j = n + 1 || solucaoParcial(i-1, s)) /* caso 2 */
		/*	caso 2: quando as colunas já chegaram até o final,
			sendo que temos, nesta situação, já testadas to-
			das as posições. Se estamos assim, e j == n+1, isso
			significa que já percorremos toda a linha, e deve-
			mos voltar. */	
		{
			/*** BACKTRACK ********************************************/ 
			j = s[--i] + 1;	/* 	Primeiro, decrementamos 'i', pois em 
								's', que funciona como uma pilha, tes-
								tamos todas as possibilidades para o 
								que já havia sido feito para uma rainha
								em s[i-1] Em seguida, avançamos nosso
								'j', (das colunas), a partir de 'i+1',
								para testarmos.  */
		}
		else if(i == n+1) /* caso 3 */
		{
			nSolucoes++; /* Encontramos uma solução, pois avan-
							çamos corretamente até n+1 */
			mostreTabuleiro(n, , s);
			j = s[--i] + 1;
				/* Fazemos um backtrack, tentando continuar */
		}
		else /* Avança */ /* caso 4 */
		{
			s[i++] = j; /* Chegamos ao final e deu certo */
			j = 1;		/* Começamos a testar, agora, a partir
						   da última linha */
		}
	} /* fim do while */
}
