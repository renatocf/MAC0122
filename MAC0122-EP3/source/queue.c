/*
 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome: Renato Cordeiro Ferreira 
  NUSP: 7990933
  Prof: José Coelho da Pina

  queue.c
  Calculadora I

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.

  - função mallocc retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html
  - função mallocSeguro retirada de: http://www.ime.usp.br/~hitoshi/mac0122-2012/ep3/esqueleto-ep3.c
  - implementação de pilha retirada de:http: //www.ime.usp.br/~coelho/mac0122-2012/aulas/programas/notacao-polonesa/stack3/ 

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/


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


/** PROTÓTIPOS ****************************************************/
void * mallocSeguro (size_t n);


/** ESTRUTURAS ****************************************************/
struct queue {
	Link final;
};
typedef struct queue *Queue;


/** IMPLEMENTAÇÕES ************************************************/
Queue queueInit()
	/* 	Cria a fila e retorna um ponteiro para ela */
{
	Queue fila;		/*	Nova fila */
		
	fila = (Queue) mallocSeguro(sizeof(*fila));
	fila->final->prox = fila->final;
	
	return fila;
}


int queueEmpty(Queue fila)
	/*	A função mostra se a fila está vazia */
{
	return fila->final->prox == fila->final;
}


void queuePut(Queue fila, char simbolo, float numero) 
{
	Link nova;
	nova = (Link) mallocSeguro(sizeof(*nova));
	
	fila->final->simbolo = simbolo;
	fila->final->numero = numero;
	nova->prox = fila->final->prox;
	fila->final = nova;
}

/*
void queueGet(Queue fila)
	 	A função devolve um número  
{
	Link primeiro_da_fila;
	char simbolo;
	int numero;
		
	primeiro_da_fila = fila->final->prox;
	simbolo = primeiro_da_fila->simbolo;
	numero = primeiro_da_fila->numero;
	fila->final = primeiro_da_fila->prox;
	
	free(primeiro_da_fila);	
}
*/

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
void * mallocSeguro (size_t n)
{
  void * pt;
  pt = malloc(n);
  if (pt == NULL) {
    printf("ERRO na alocacao de memoria.\n");
    exit(-1);
  }
  return pt;
}
