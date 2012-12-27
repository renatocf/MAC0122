#include <stdlib.h>     /* funcao exit */
#include <stdio.h>
#include <string.h>     /* funcao strspn e strncpy */
#include <ctype.h>      /* funcao isdigit */

#include "filmes.h"
#include "iofilmes.h"

/* maior linha dos arquivos de entrada tem uns 240 caracteres */
#define TAMLINHA 300 

/* funcoes rIndex e erroLeitura sao usadas apenas neste arquivo */
static char *rIndex(char *pal, char letra); 
static void  erroLeitura(char *msg, char *lin);

/*
----------------------------------------------------------------------
Funcao carregaLista
   Carrega uma lista de filmes a partir de um arquivo de entrada.
   O nome do arquivo deve ser lido.
*/

void carregaLista(Lista *lista)
{
  FILE *arq;
  char linha[TAMLINHA+1], *alinha, *blinha;
  char dist[11];
  int votos;
  char nome[TAMNOME+1];
  int ano;
  float nota;
  char nome_arq[101];
  int cont = 0; /* conta número de filmes lidos */

  printf("Digite o nome do arquivo: ");
  scanf(" %s", nome_arq);
  printf("Nome do arquivo de entrada: %s\n", nome_arq);
  arq = fopen(nome_arq, "r");
  if (arq == NULL) {
    printf("\nArquivo %s nao encontrado\n\n", nome_arq);
    exit(-1);
  }

  while(fgets(linha, TAMLINHA, arq) != NULL) {
    alinha = linha; /* apontador para linha */

	/* verifica se a linha contem um filme.  
	   Deve começar com 6 espaços
	   e ter um digito ou ponto na setima posicao */
    if (
	strspn(linha, " ") == 6 && /* 6 caracteres brancos */
	( linha[6] == '.' || 
	 (linha[6] >= '0' && linha[6] <= '9')
	  )	                   /* inicio da distribuicao */
	) {
      alinha += 6; /* pula brancos */

      /* distribuicao, 10 caracteres */
      strncpy(dist, alinha, 10);
      dist[10] = '\0';
      alinha += 10; /* pula distribuicao */

      /* votos e nota, ocupam 16 posições */
      if (sscanf(alinha, "%d %f", &votos, &nota) != 2) {
	erroLeitura("votos ou nota invalidos", linha);
	continue;
      }
      alinha += 16; /* pula votos e nota */

      /* pula brancos e tabs */
      while (*alinha == ' ' || *alinha == '\t') alinha++;

      /* encontra ultimo '{' e joga comentarios fora */
      blinha = rIndex(alinha, '{');
      if (blinha != NULL) *blinha = '\0'; 

      /* procura o ano no que sobrou da linha */
      blinha = rIndex(alinha, '(');
      if (blinha == NULL) {
	erroLeitura("ano ausente", linha);
	continue;
      }

      /* nao eh ano: eh (mini), (TV) ou (V) */
      if (!isdigit(blinha[1]) && blinha[1] !=  '?') {
	*blinha = '\0';			/* joga fora */
	blinha = rIndex(alinha, '(');   /* pega o parenteses  anterior */
	if (blinha == NULL) {
	  erroLeitura("ano ausente", linha);
	  continue;
	}
      }
      blinha++;				/* pula o parenteses */

      if (sscanf(blinha, "%d", &ano) != 1) {
	/* pode ser ano ignorado */
	if (strspn(blinha, "?") == 4)
	  ano = 9999;
	else {
	  erroLeitura("ano invalido", linha);
	  continue;
	}
      }

      blinha[-2] = '\0'; /* joga fora pedaco final da linha com o ano */

      /* O que sobra eh o nome */
      strncpy(nome, alinha, TAMNOME);
      nome[TAMNOME] = '\0';

      insereFilme(lista, criaFilme(dist, votos, nota, nome, ano));
      cont++;
      if (cont % 1000 == 0) {
	printf(".");     /* indicador de progresso */
	fflush(stdout);  /* imprime o '.' sem esperar que a linha toda fique pronta */
      }
    }
  }

  printf("\n");
  fclose(arq);
}

/*
----------------------------------------------------------------------
gravaLista
  Grava a lista de filmes no arquivo nome, no formato:
     - 6     espacos
     - %s    dist
     - %7d   votos
     - %7.1  nota
     - %s    nome
     - (%d)  ano

  Exemplo
       0.0.003003      29   7.0  Always a Bridesmaid (2000)
*/

void gravaLista(Lista *lista) 
{
  FILE *arq;
  char nome_arq[101];
  Filme *f;

  printf("Digite o nome do arquivo: ");
  scanf(" %s", nome_arq);
  printf("Nome do arquivo de saida: %s\n", nome_arq);
  arq = fopen(nome_arq, "w");
  if (arq == NULL) {
    printf("\nNao foi possivel criar o arquivo %s.\n\n", nome_arq);
    exit(-1);
  }

  for (f=lista->ini; f!=NULL; f=f->prox)
    fprintf(arq, "      %s %7d %7.1f\t%s\t(%d)\n", 
	    f->dist, f->votos, f->nota, f->nome, f->ano);

  fclose(arq);
}

/*
----------------------------------------------------------------------
Funcao rIndex
  Devolve apontador para endereco do ultimo simbolo de pal que eh 
  igual a letra; ou devolve NULL se nao existir simbolo igual a letra
*/

char *rIndex(char *pal, char letra) 
{
  int index;
     
  index = strlen(pal);
  while (index > 0) {
    index--;
    if (pal[index] == letra)
      return &pal[index];
  }

  return NULL;
}



/*
----------------------------------------------------------------------
Funcao erroLeitura
*/

void erroLeitura(char *msg, char *lin)
{
  fprintf(stderr, "Entrada invalida ignorada(%s):\n\t%s\n", msg, lin);
}

/*
----------------------------------------------------------------------
Funcao mostraUmFilme
  Imprime as informacoes sobre um filme
*/
void mostraUmFilme(Filme *f)
{
  if (f != NULL){
    printf(
	   "--------------------------------------------------------------------------------\n"
	   "%s (ano %d):\n"
	   "\t nota %4.1f "
	   "\t %6d votos "
	   "\t distribuicao [%s] \n",
	   f->nome, f->ano,f->nota, f->votos, f->dist);
  }
  else
    printf("--------------------------------------------------------------------------------\n");
}

/*
----------------------------------------------------------------------
Funcao mostraLista
   Imprime uma lista de filmes.
*/
void mostraLista(Lista *lista)
{
  Filme *f;
  int cont = 0;

  if (lista->ini == NULL) 
    {
      printf("Lista de filmes vazia.\n");
      return;
    }

  for (f = lista->ini; f != lista->fim->prox; f = f->prox) {
    mostraUmFilme(f);
    cont++;
  }
  mostraUmFilme(NULL);
  printf("Total de filmes: %d\n", cont);
}

