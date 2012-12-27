/* 
 * IMPLEMENTACAO de funcoes de uso geral 
 *
 */

#include <stdio.h>      /* função printf */
#include <stdlib.h>     /* função malloc */
#include <string.h>     /* função strlen */
#include "utils.h" 

/*
  mallocSafe: testa o ponteiro devolvido por malloc
 */
void * mallocSafe (size_t n)
{
  void * pt;
  pt = malloc(n);
  if (pt == NULL) {
    printf("ERRO na alocacao de memoria.\n\n");
    exit(-1);
  }
  return pt;
}

/*
----------------------------------------------------------------------
leString
  Le uma cadeia de caracteres ate encontrar um \n. 
  Devolve a cadeia de caracteres apos trocar \n por \0.
*/
int leString(char str[], int max)
{
  int tam;
  scanf(" ");
  fgets(str, max, stdin);
  tam = strlen(str)-1; 
  str[tam] = '\0';
  return tam;
}
