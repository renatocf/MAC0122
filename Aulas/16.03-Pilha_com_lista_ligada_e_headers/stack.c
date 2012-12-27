#include<stdio.h>
#include<stdlib.h>
#include "item.h"

typedef struct stackNode* Link;
struct stackNode {
	/* 	Struct para criar a lista
		ligada com células de con-
		teúdo do tipo Item e que
		estão ligadas para outros
		'struct stackNode*' */
	Item conteudo;
	Link prox;
}

Link tp;

void stackInit(int n)
	/* 	Iniciando a "pilha" - na realidade, a lista ligada. 
		O fato de ser uma lista faz com que não seja neces-
		sário o nº de elementos, mas como a implementação
		está diferente, então devemos mantê-la, mesmo sem
		utilizá-la. */
{
	tp = malloc(sizeof(struct stackNode));
	/* Ou podemos fazer: tp = malloc(sizeof(*tp)); */
	tp->prox = NULL.
}

void stackEmpty()
	/* Pilha vazia */
{
	return tp->prox = NULL;
}

void stackPush(Item item)
	/* 	Adicionando elementos no topo da "pilha" */
{
	Link nova = malloc(sizeof *nova); /* Criamos uma nova célula */
	nova->conteudo = item;	/* 	A célula recebe o conteúdo desejado */
	nova->prox = tp->prox;	/* 	Ligamos na nossa nova o último elemento
								da lista */
	tp->prox = nova;		/*	Terminamos de fazer a ligação, rompendo
								a antiga e, depois, religando */
}

Item stackPop()
	/* Retirando elementos do "topo" da pilha */
{
	Item item = tp->prox->conteudo;
		/* Auxiliar para guardar o conteúdo do próximo a tp */
	Link p = tp->prox;
		/* Auxiliar para guardar o próximo do topo - o último elemento */
	tp->prox = p->prox;	/* 	Retirando, da pilha, o 'p' - elemento que
							criamos para armazenar o próximo de 'tp' */
	free(p); p = NULL;	/* 	Livra a célula correspondente ao último
							elemento da pilha */
	return item; /* Retorna o conteúdo da pilha, retirando
					o elemento que havia lá */
}

Item stackTop() {
	return tp->prox->conteudo;
	/* retorna o último elemento da pilha */
}

void stackFree()
	/* Libera a pilha */
{
	Link p;
	while(tp != NULL)
	{
		p = tp;				
		tp = tp->prox;		
		free(p); p = NULL;	/* Liberando o elemento do topo */
	}
}
