/* 
 * queue2.c
 * Fila implementada com vetor circular
 *
 * CÓDIGO-FONTE: Funções para manipular a fila.
 * ATENÇÃO:	Esta implementação permite mani-
 * 			pular apenas uma fila por vez.
 */

/*	A vantagem dessa implementação é que poderemos tratar o vetor
	como algo contínuo (um círculo). Queremos, portanto, que não
	haja uma limitação de apenas ocuparmos posições a frente do
	'fim'. Conforme liberarmos para trás, poderemos inserir os
	elementos atrás de volta na fila, "circulando" por ela e 
	podendo reaproveitá-la. 
	
	ESQUEMA:
	
	\% 	O vetor é linear, mas faremos ele "pular" do início para o
		fim para que possa ser aproveitado por vários elementos %\
	
	-----------------------------> Sentido de circulação
	 _____
	 |   | "Pulo" dado no vetor 
	|_| |_|_|_|_|_|_|_|_|_|_|_|_|_|
	|_|							|_|
	|_|							|_|
	|_|							|_|
	|_|							|_|
	|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_| */


/** BIBLIOTECAS ***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "mallocSafe.h"

/** VARIÁVEIS GLOBAIS *********************************************/
int ini, fim;	/* 	Guardam o início e o fil da fila 			  */
int *q;			/* 	Ponteiro para a fila (queue), não iniciali-
					zado ainda 									  */
int N;			/*	Serve para manipularmos como o 'n', mas com
					um elemento a mais (para a desambiguação)	  */

/** FUNÇÕES *******************************************************/
void queueInit(int n)
	/*	Inicia a fila */
{
	/*queue1*//* Agora, estamos implementando deixando um espaço
				 a mais no vetor, de modo que ele retire as ambi-
				 guidades relativas ao início/fim no vetor com
				 implementação circular. */
	N = n+1;
	q = mallocSafe(N * sizeof(int));
	ini = fim = 0;
}

int queueEmpty()
	/*	Diz se a fila está vazia */
	/*queue1*//* Continua a mesma em relação à outra pilha */
{
	return ini == fim;
}

void queuePut(Item conteudo)
	/*	Coloca um elemento no vetor */
{
	/*queue1*//* Estamos colocando uma verificação para o erro
				 'queue overflow'. Para o vetor circular, ten-
				 tamos fazer as seguintes operações:
				 #	fim + 1 == ini
					Chegamos à sitação em que, ao avançarmos
					num ponto qualquer, não teremo mais espa-
					ço para prosseguir.
				 #	fim == n-1 e ini = 0
					Situação igual à original, em que chegamos
					ao final e o 'ini' é o 0 - não temos mais
					espaço para adicionar elementos. 
				 	>	Resumimos estes comandos com o seguinte
						trecho: (fim+1) % N == ini */
	if((fim+1) % N == ini)
	{
		printf("queue overflow");	/* 	Mensagem de erro */
		exit(EXIT_FAILURE);			/* 	Saída de erro, com cons-
										tante da stdlib.h */
	}
	q[fim++] = conteudo;
	if(fim == N) fim = 0;
		/*	É o comando que diz para "voltarmos" ao início, ro-
			dando pelo vetor. */
}

Item queueGet()
	/*	Pega o primeiro elemento da fila */
	/*queue1*//* Em relação à antiga, temos que o ponto é que 
				 devemos garantir a circulação, quando chegamos
				 ao final */
{
	Item conteudo = q[ini++];
	if(ini == N) ini = 0;
		/*	Garante que voltemos ao início */
	return conteudo;
}

void queueFree()
	/*	Libera a fila */
	/*queue1*//* Continua igual */
{
	free(q);
}
