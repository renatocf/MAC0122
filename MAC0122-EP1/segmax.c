/***************************************************************/
/**                                                           **/
/**   Renato Cordeiro Ferreira                      7990933   **/
/**   Exercício-Programa 01                                   **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

/*
 *  P A R T E I.   P R O T O T I P O S
 */

void
segmax(int sequencia[], int n, int *ls, int *rs, long *soma);

void
mostre_uso(char *nome_prog);


/*
 * P A R T E II.  M A I N
 */
int
main(int argc, char *argv[])
{
  FILE *fp;        /* para o arquivo com a sequencia */
  int    n;        /* comprimento da sequencia */
  int  *sequencia; /* para armazenar a sequencia */
  int   l, r;      /* inicio l e fim r do segmento de soma maxima */
  long  soma;      /* valor da maior soma de um segmento */
  clock_t start;   /* instante em que a funcao segmax foi chamada */
  clock_t end;     /* instante em que a funcao segmax voltou da chamada */
  double elapsed;  /* para o calculo do tempo gasto por segmax */

  if (argc < 2)
    {
      mostre_uso(argv[0]);
      return -1;
    }
  if (!(fp = fopen(argv[1],"rb")))
    {
      fprintf(stderr,"%s: erro na abertura do arquivo %s.\n", argv[0], argv[1]);
      return -2;
    }
  if (!(fread(&n, sizeof(int), 1, fp)))
    {
      fprintf(stderr,"%s: erro na leitura do arquivo %s.\n", argv[0], argv[1]);
      return -3;
    }
  if (n <= 0)
    {
      fprintf(stderr,"Valor de n nao permitido.\n");
      return -4;
    }

  /* aloque um vetor de n posicoes */
  if ((sequencia = (int *) malloc(n * sizeof(int))) == NULL)
    {
      fprintf(stderr,"%s: espaco insuficiente.\n", argv[0]);
      return -5;
    }

  /* leia a sequencia */
  if (fread(sequencia, sizeof(int), n, fp) < n)
    {
      fprintf(stdout,"O arquivo %s nao esta completo.\n", argv[1]);
      return -6;
    }
  fclose(fp);

  /* comece a cronometrar */
  start = clock();

  /* encontre o segmento de soma maxima */
  segmax(sequencia, n, &l, &r, &soma);

  /* pare o relogio */
  end = clock();
  elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;

  fprintf(stdout,"\n O arquivo de entrada \"%s\" contem %d numeros.\n"
	  " Foi encontrada uma subsequencia de soma maxima com\n"
	  " Inicio: %d\n"
	  "  Final: %d\n"
	  "   Soma: %ld\n"
	  "  Tempo: %f s (nao incluido tempo com leitura)\n\n"
          ,argv[1], n, l, r, soma, elapsed);

  return 0;

}


/*
 * P A R T E III.  I M P L E M E N T A C A O   D A S   F U N C O E S
 */



/*
 * S E G M A X: A funcao segmax recebe:
 *
 *          - um inteiro positivo n e
 *          - um vetor de inteiros sequencia[0..n-1]
 *
 * e devolve:
 *
 *          - apontadores de inteiros ls, rs e soma, tais que
 *
 *            (1) o valor de *ls e *rs esta entre -1 e n-1
 *
 *            (2) o valor
 *
 *            *soma = sequencia[*ls] + sequencia[*ls+1] + ... +
 *                                     sequancia[*rs]
 *
 *            e' maximo.
 *
 *            Caso o vetor sequencia so' tenha inteiros
 *            nao-positivos a funcao devolve *ls = *lr = -1 e
 *            *soma = 0.
 *
 */
void
segmax(int sequencia[], int n, int *ls, int *rs, long *soma)
	/* A função segmax recebe uma sequência de inteiros gerados aleatoria-
	 * mente com n termos e devolve a maior soma possível de um segmento
	 * iniciado na posição ls e terminado em rs (ls e rs ponteiros para 
	 * as variáveis externas à função que armazenam estas posições). */
{
	int pivo = 0; 		   /* O 'pivo' demarca a primeira posição de uma 
							* subsequência a ser verificada pela função */
	int posicao_atual = 0; /* A variável 'posicao_atual' marca o limite 
							* final do vetor verificado na iteração cor-
							* respondente, dado um certo 'pivo'. 		*/
	long soma_atual = 0;   /* 'soma_atual' é uma variável auxiliar para 
							* guardar uma soma que pode ou não substituir
							* o valor apontado pelo ponteiro 'soma'. 	*/
	
	*ls = -1, *rs = -1; *soma = 0;
		/* Valores-padrão para caso todos os elementos do vetor forem 
		   negativos (n=esta situação, o laço não os afeta). */
	
	for(posicao_atual = 0; posicao_atual < n; posicao_atual++)
	{
		soma_atual += sequencia[posicao_atual];
		
		if(soma_atual <= 0)
		{
			pivo = posicao_atual + 1; 
			soma_atual = 0;
			continue;
		}
		if(soma_atual > *soma)
		{
			printf("%ld ", soma_atual);
			*soma = soma_atual;
			*ls = pivo;
			*rs = posicao_atual;
		}	
	}
}


/*---------------------------------------------------------*/
void
mostre_uso(char *nome_prog)
{
  fprintf(stdout," \n%s: este programa recebe uma sequencia de n numeros"
	  " inteiros\n"
	  "   x[0], x[1], x[2], ... , x[n-2], x[n-1],\n"
	  " e devolve indices l e r tais que a soma\n"
	  "   x[l] + x[l+1] + ... + x[r-1] + x[r]\n"
	  " e' maxima.\n\n"
	  " Uso: segmax <arquivo de entrada>.\n\n"
	  " O arquivo deve ser binario e ter formato\n"
	  "   n x[0] x[1] ... x[n-2] x[n-1]\n"
	  " onde n eh um inteiro positivo.\n\n",  nome_prog);
}
