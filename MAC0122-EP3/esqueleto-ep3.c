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

  Nome:
  NUSP:
  Prof:

  EP3.c
  Calculadora I

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:
  - função mallocc retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO

  A estrutura deste esqueleto esta a seguir.
  Não altere esta estrutura.

  1  MACROS E CONSTANTES                
  2  DECLARACAO DE STRUCTS e TIPOS               
  3  PROTOTIPOS DAS FUNCOES DADAS
  4  PROTOTIPOS DE FUNCOES QUE VOCE DEVE FAZER
  5  M A I N
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER
  7  IMPLEMENTACAO DAS FUNCOES DADAS 

  As partes deste EP que você deverá escrever são:
  
  5  M A I N
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* 
////////////////////////////////////////////////////////////////////// 
  1  MACROS E CONSTANTES 

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* numero maximo de caracteres em um linha */
#define MAX_TAMANHO 80 

/* codigos */
#define NUMERO  '#'
#define SOMA    '+'
#define SUB     '-'
#define MULT    '*'
#define DIV     '/'
#define EXP     '^'
#define NEG     '!'

/* 
////////////////////////////////////////////////////////////////////// 
  2  DECLARACAO DE STRUCTS e TIPOS
 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* ====================================================================== */
/*    Elemento para Fila e Pilha para armazenar numeros e/ou simbolos     */
/* ====================================================================== */
typedef struct celula {
  char  simbolo; 
  float numero;
  struct celula *prox;
} Celula;


/* 
////////////////////////////////////////////////////////////////////// 
  3  PROTOTIPOS DAS FUNCOES DADAS que você não precisa implementar

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

void  * mallocSafe (size_t n);
float strtof(const char *nptr, char **endptr); /* para evitar warning */

/* 
////////////////////////////////////////////////////////////////////// 
  4  PROTOTIPOS DE FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/


Celula * constroiFilaPosfixa (char *linha);
float calculaPosfixa(Celula *cab);

/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  5  M A I N 

////////////////////////////////////////////////////////////////////// 
*/

int main(int argc, char *argv[])
{
  FILE *fentrada;
  char linha[MAX_TAMANHO]; /* recebe linha do arquivo de entrada */

  Celula *cab; /* fila de numeros e operadores */ 
  int i; 
  int contaLinha = 0;
  float numero;

  if (argc != 2) {
    printf("Para usar digite: %s <arquivoEntrada>\n", argv[0]);
    exit(-1);
  }

  fentrada = fopen(argv[1], "r");
  if (fentrada == NULL) {
    printf("Nao consegui abrir o arquivo %s\n", argv[1]);
    exit(-1);
  }
  
  while ( fgets(linha, MAX_TAMANHO, fentrada) != NULL ) {
    contaLinha++;
    i = strlen(linha);

    if (i == 0) {
      printf("Linha %d: vazia \n", contaLinha);
      continue;
    }

    linha[i-1] = '\0'; /* substitui \n for fim do string */
    printf("Linha %d: %s\n", contaLinha, linha);
    
    cab = constroiFilaPosfixa(linha);
    numero = calculaPosfixa(cab);

    printf("Resultado: %f \n\n", numero);
  }

  return 0;
}

/* 
////////////////////////////////////////////////////////////////////// 
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* ====================================================================== 

  Recebe um string linha contendo a expressão posfixa e devolve o
  endereço cab da célula cabeça da fila contruída.

*/

Celula *constroiFilaPosfixa (char *linha)
{
  return NULL; /* pode alterar esta linha */
}

/* ====================================================================== */
/*
  recebe uma fila circular com cabeça cab de números e operadores
  representando um expressão posfixa e calcula e devolve o valor da
  expressão.

 */

float calculaPosfixa(Celula *cab)
{
  return 0; /* pode alterar esta linha */
}


/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  7  IMPLEMENTACAO DAS FUNCOES DADAS

////////////////////////////////////////////////////////////////////// 
*/

/*
  mallocSafe: testa o ponteiro devolvido por malloc
 */
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


