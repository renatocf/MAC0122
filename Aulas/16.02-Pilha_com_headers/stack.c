#include<stdio.h>
#include<stdlib.h>
#include "item.h"

Item *s;	/* variável global correspondente ao item */
int t;		/* variável 't' */

void stackInit(int n)
	/*	Inicia a pilha com o tamanho de 'n' elementos passado */
{
	s = malloc(n * sizeof(Item));
	t = 0; /* Não há elementos na pilha */
}

int stackEmpty()
	/*	Retorna que a pilha está vazia */
{
	return t==0;
}

void stackPush(Item item)
	/* 	Adiciona um elemento à pilha, colocando-o no topo dela e aumen-
		tando a variável que guarda o nº de elementos presente na pilha
		(que também mostra a última posição livre no topo).
{
	s[t++] = item;
}

Item stackPop()
	/* 	Retira um elemento da pilha e diminui o número do topo dela */
{
	return s[--t];
}

Item stackTop()
	/* 	Retorna o último elemento da pilha */
{
	return s[t-1];
}

void stackFree()
	/* 	Limpa a pilha e deixa o ponteiro para ela vazio (por motivos 
		de segurança */
{
	free(s);return NULL;
}
