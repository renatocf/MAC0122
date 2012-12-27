/* 
 * queue.c
 * Pilha implementada com lista circular com cabeça
 *
 * CÓDIGO-FONTE: Funções para manipular a fila
 * ATENÇÃO:	  Esta implementação permite a manipula-
 * 			  ção de múltiplas filas ao mesmo tempo.
 */


/** BIBLIOTECAS ***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "item.h"


/** PROTÓTIPOS*****************************************************/
void * mallocSafe (size_t n);


/** ESTRUTURAS ****************************************************/
struct queueNode {
	Item conteudo;
	struct queueNode *prox;
};
typedef struct queueNode *Link;


struct queue {
	Link final;
};
typedef struct queue * Queue;


/** IMPLEMENTAÇÕES ************************************************/
Queue queueInit()
	/* 	Cria a fila e retorna um ponteiro para ela */
{
	Queue fila;		/*	Nova fila */
		
	fila = (Queue) mallocSafe(sizeof(*fila));
	fila->final->prox = fila->final;
	
	return fila;
}


int queueEmpty(Queue fila)
	/*	A função mostra se a fila está vazia */
{
	return fila->final->prox == fila->final;
}


void queuePut(Queue fila, Item conteudo) 
{
	Link nova;
	nova = (Link) mallocSafe(sizeof(*nova));
	
	fila->final->conteudo = conteudo;
	nova->prox = fila->final->prox;
	fila->final = nova;
}


Item queueGet(Queue fila)
	/* 	A função devolve o conteúdo do primeiro da fila, retirando-o
		dela. */
{
	Link primeiro_da_fila;
	Item conteudo;
	
	primeiro_da_fila = fila->final->prox;
	conteudo = primeiro_da_fila->conteudo;
	fila->final = primeiro_da_fila->prox;
	
	free(primeiro_da_fila);
	
	return conteudo;
}


void queueFree(Queue fila)
	/* 	Libera a pilha e todos os elementos que estiverem nela. */
{
	Link morta;
	while(fila->final->prox != fila->final)
	{
		morta = fila->final->prox;
		fila->final->prox = morta->prox;
		free(morta);
	}
	
	free(fila->final);
}


/** MALLOC SAFE ***************************************************/
void * mallocSafe (size_t n)
{
  void * pt;
  pt = malloc(n);
  if (pt == NULL) {
    printf("ERRO na alocacao de memoria.\n");
    exit(-1);
  }
  return pt;
}
