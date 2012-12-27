#include <stdio.h>
#include <stdlib.h>

#define MAX 500000000

FILE *fp;

#define SIZE 1000


/*
 *  P A R T E  I.   P R O T O T I P O S
 */

void 
mostre_uso(char *nome_prog);

double 
ran1();

/*
 *  P A R T E  II.   M A I N 
 */
int 
main(int argc, char *argv[]) 
{
  register int i;
  int n, valor;
  long int semente;
  
  if (argc < 4) 
    {
      mostre_uso(argv[0]);
      return -1;
    }

  n = atoi(argv[1]);
  
  if (n <= 0 || n > MAX) 
    {
      printf("Numero invalido\n\n");
      return -2;
    }
  
  if (!(fp = fopen(argv[2], "wb"))) 
    {
      printf("Erro na criacao do arquivo %s.\n", argv[2]);
      return -3;
    }

  fwrite(&n, sizeof(int), 1, fp);
  semente = atol(argv[3]);
  srand(semente);
  
  for (i = 0; i < n; i++) 
    {
      valor = ((double) rand() / RAND_MAX) * SIZE;
      if (ran1() < 0.5)
	valor = -valor;
      fwrite(&valor, sizeof(int), 1, fp);
    }
  fclose(fp);
  
  return 0;
  
}


/*
 *  P A R T E  III.   I M P L E M E N T A C A O  
 */
void 
mostre_uso(char *nome_prog)
{
  fprintf(stdout,"%s: Este programa gera um arquivo binario com uma"
	  " sequencia\n"
	  "      de numeros inteiros\n" 
	  "      n x[0] x[1] ... x[n-2] x[n-1]\n\n"
	  "      Uso: gera n <arquivo> semente.\n\n"
	  "           deve-se ter 1 <= n <= %d\n"
	  "           semente e' um inteiro longo para o gerador "
	  "de numeros (pseudo)aleatorios.\n", nome_prog, MAX);
}

double 
ran1()
{
  static long int a = 100001;
  
  a = (a * 125) % 2796203;
  
  return (double) a/2796203;
}
