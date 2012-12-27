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

  - implementação de interface para pilha retirada de: http://www.ime.usp.br/~coelho/mac0122-2012/aulas/programas/notacao-polonesa/stack3/
  - implementação de pilha retirada de: http: //www.ime.usp.br/~coelho/mac0122-2012/aulas/programas/notacao-polonesa/stack3/ 

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/* 
 * queue.h
 *
 * INTERFACE: Funções para manipular a fila
 * ATENÇÃO:	  Esta implementação permite a manipulação de múltiplas fi-
			  las ao mesmo tempo.
 */

typedef struct queue *Queue;

Queue queueInit();
int   queueEmpty(Queue);
void  queuePut(Queue, Item);
Item  queueGet(Queue); 
void  queueFree(Queue);
