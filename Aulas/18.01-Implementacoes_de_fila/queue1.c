/* 
 * queue1.c
 * Fila implementada com vetor
 *
 * CÓDIGO-FONTE: Funções para manipular a fila.
 * ATENÇÃO:	Esta implementação permite mani-
 * 			pular apenas uma fila por vez.
 */

/*	ESQUEMA DO VETOR:
	
	|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|
	
	Só podemos usá-lo até o final (n vezes, o tamanho dele).
	Depois desse limite, esta implementação não faz nada.
*/


/** BIBLIOTECAS ***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "mallocSafe.h"

/** VARIÁVEIS GLOBAIS *********************************************/
int ini, fim;	/* 	Guardam o início e o fil da fila 			  */
int *q;			/* 	Ponteiro para a fila (queue), não iniciali-
					zado ainda 									  */

/** FUNÇÕES *******************************************************/
void queueInit(int n)
	/*	Inicia a fila */
{
	q = mallocSafe(n * sizeof(int));
	ini = fim = 0;
}

int queueEmpty()
	/*	Diz se a fila está vazia */
{
	return ini == fim;
}

void queuePut(Item conteudo)
	/*	Coloca um elemento no vetor */
{
	q[fim++] = conteudo;
}

Item queueGet()
	/*	Pega o primeiro elemento da fila */
{
	Item conteudo = q[ini++];
	return conteudo;
}

void queueFree()
	/*	Libera a fila */
{
	free(q);
}
