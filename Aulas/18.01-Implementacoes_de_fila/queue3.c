/* 
 * queue3.c
 * Fila implementada com lista sem cabeça
 *
 * CÓDIGO-FONTE: Funções para manipular a fila.
 * ATENÇÃO:	Esta implementação permite mani-
 * 			pular apenas uma fila por vez.
 */

/*	Esta implementação não terá limitações do tipo de vetores
	(com relação ao tamanho). Usaremos a alocação dinâmica de 
	memória e os ponteiros/endereços para fazer a fila. */


/** BIBLIOTECAS ***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "item.h"
#include "mallocSafe.h"

/** VARIÁVEIS GLOBAIS *********************************************/
/*queue2*//* Agora, temos estruturas para guardar endereços da
			 célula seguinte, além do conteúdo desejado */
typedef struct queueNode *Link	/* Ponteiro para queue node 	  */
struct queueNode {
	int conteudo;
	Link prox;
}
Link ini, fim;	/* 	Guardam o início e o fil da fila 			  */


/** FUNÇÕES *******************************************************/
void queueInit(int n)
	/*	Inicia a fila */
{
	/*queue2*//* Como a lista é sem cabeça, inicialmente apontamos
				 para nada */
	ini = NULL;
}


int queueEmpty()
	/*	Diz se a fila está vazia */
	/*queue1*//* Se ela estiver vazia, ela será igual a NULL */
{
	return ini == NULL;
}

/*
void queuePut(Item conteudo)
	\%	Coloca um elemento no vetor %\
{
	\%queue1%\\% Estamos colocando uma verificação para o erro
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
						trecho: (fim+1) % N == ini %\
	if(ini == NULL)
	{
		ini = fim = mallocSafe(sizeof(struct queueNode));
		\% 	Se estiver vazia, devemos criar de um modo 
			diferente %\
		ini->conteudo = conteudo; 	\% Conteúdo %\
		ini->prox = NULL;			\% O próximo da cé
									   lula criada é NULL %\
		return; 					\% Sai da função %\
	}
	fim->prox = mallocSafe(sizeof(struct queueNode));
		\%	Criamos uma nova 'queueNode' no final %\
	fim = fim->prox;			\% 	O fim, agora, é a nova 
									célula recém-criada %\
	fim->prox = NULL;			\%	Como é o final, não aponta 
									para nada %\
	fim->conteudo = conteudo;	\% 	Colocamos os dados na célula
									nova %\
} */
/*	PARA SUBSTITUIR A FORMA ACIMA, CRIAREMOS ALGO MAIS REDUZIDO,
	COM UMA FUNÇÃO PARA ALOCAR CHAMADA 'NEW' */

Link new(int conteudo)
{
	static Link p;
	p = mallocSafe(sizeof(*p));
	p->conteudo = conteudo;
	
	return p;
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
	if(ini == NULL)
	{
		ini = fim = new(conteudo);
		/* 	Se estiver vazia, devemos criar de um modo 
			diferente */
		ini->prox = NULL;			/* O próximo da cé
									   lula criada é NULL */
		return; 					/* Sai da função */
	}
	fim->prox = mallocSafe(sizeof(struct queueNode));
		/*	Criamos uma nova 'queueNode' no final */
	fim = fim->prox;			/* 	O fim, agora, é a nova 
									célula recém-criada */
	fim->prox = NULL;			/*	Como é o final, não aponta 
									para nada */
	fim->conteudo = conteudo;	/* 	Colocamos os dados na célula
									nova */
} 


Item queueGet()
	/*	Pega o primeiro elemento da fila */
	/*queue1*//* Em relação à antiga, temos que o ponto é que 
				 devemos garantir a circulação, quando chegamos
				 ao final */
{
	Link p = ini; /* Auxiliar para o 'free' */
	Item conteudo = ini->conteudo;
	
	ini = ini->prox;
	free(p);
	return conteudo;
}


void queueFree()
	/*	Libera a fila */
	/*queue2*//* Liberamos célula a célula */
{
	while(ini != NULL)
	{
		Link t = ini->prox;
		ini = ini->prox->prox;
		free(t);
	}
}
