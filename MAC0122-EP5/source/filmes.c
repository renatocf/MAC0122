#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "filmes.h"
#include "iofilmes.h"

#define TRUE  1
#define FALSE 0

/******************************************************************/
/*	    PROTÓTIPOS DE FUNÇÕES AUXILIARES DE USO INTERNO			  */
/******************************************************************/
static Filme *separa(Lista *lista);
static void troca(Filme **end_i, Filme **end_j, Lista **end_lista);

/*
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

   IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER

////////////////////////////////////////////////////////////////////// 
*/

/*
----------------------------------------------------------------------
Funcao quickSort(Lista *l)
  Ordena a lista em ordem decrescente de nota utilizando o 
  algoritmo Quicksort adaptado para listas encadeadas.
*/
void quickSort(Lista *lista)
{
	/** VARIÁVEIS *****************************************************/
		Lista *esquerda; /*	Lista para os elementos maiores que 'i'	 */
		Lista *direita;	 /* Lista para os elementos menores que 'i'	 */
		Filme *ini;		 /* Apontador para primeiro filme da lista	 */
		Filme *fim;		 /* Apontador para o último filme da lista	 */
		Filme *i;		 /* Filme com nota pivô para as sublistas
							devolvido pelo algoritmo de separação	 */
		
		ini = lista->ini; fim = lista->fim;
	
	/** BASE DA RECURSÃO **********************************************/
		if(ini == NULL || fim == NULL) return; /* Lista vazia 		 */
		if(ini == fim) return;		 		   /* Apenas 1 elemento  */
		if(fim->prox == ini) return; 		   /* Começo precede fim */
		
	/** SEPARAÇÃO *****************************************************/
		i = separa(lista);
		
	/** PASSO DA RECURSÃO *********************************************/
		esquerda = (Lista *) mallocSafe(sizeof(*esquerda));
		direita = (Lista *) mallocSafe(sizeof(*direita));
		
		esquerda->ini = lista->ini; esquerda->fim = i->ant;
		direita->ini = i->prox; direita->fim = lista->fim;
		
		quickSort(esquerda);  /* Filmes com nota maior que i->nota */
		quickSort(direita);	  /* Filmes com nota menor que i->nora */ 
		
		/* Atualiza início e fim */
		lista->ini = esquerda->ini; lista->fim = direita->fim;
		
	/** LIBERAÇÃO DE MEMÓRIA ******************************************/
		free(esquerda); esquerda = NULL;
		free(direita); direita = NULL;
}

/* 
----------------------------------------------------------------------
Funcao achaFilme
  Devolve TRUE se o filme f ja esta na lista e 
  devolve FALSE em caso contrario. 
*/
int achaFilme(Lista *lista, Filme *f)
{
	/** VARIÁVEIS *****************************************************/
	Filme *atual;
	char *caracterAtual = f->nome;
	int tNome;

	for(caracterAtual = f->nome, tNome = 0; *caracterAtual != '\0';
		tNome++, caracterAtual++);
	
	if(lista->ini == NULL) return FALSE;
	for(atual = lista->ini; atual != NULL; atual = atual->prox)
	{
		if(achaPalavra((unsigned char *) f->nome, tNome, 
			(unsigned char *) atual->nome, TAMNOME) == TRUE
			&& atual->ano == f->ano 
			&& atual->nota == atual->nota)
			return TRUE;
	}
	
	return FALSE;
}

/* 
----------------------------------------------------------------------
Funcao achaPalavra
	Devolve TRUE quando acha a 1a ocorrencia e
	devolve FALSE em caso contrario.
*/
int  achaPalavra(unsigned char *pal, int tPal, unsigned char *texto, int tTex)
{
	int i, j;
	
	for(i = 0; i < tTex-tPal; i++)
	{
		for(j = 0; j < tPal && texto[i+j] == pal[j]; j++); 
		if(j == tPal) return TRUE;
	}
	return FALSE;
}


/*
----------------------------------------------------------------------
Funcao criaLista
   Cria uma lista de filmes vazia
*/

Lista *criaLista()
{
  Lista *lista;

  lista =  mallocSafe(sizeof(Lista));

  lista->ini = NULL;
  lista->fim    = NULL;

  return lista;
}


/*
----------------------------------------------------------------------
Funcao criaFilme
   Cria uma celula para armazenar um filme
*/

Filme *criaFilme(char *d, int v, float n, char *nm, int a)
{
  Filme *f;

  f = mallocSafe(sizeof(Filme));

  strncpy(f->dist, d, 10);
  f->dist[10] = '\0';

  strncpy(f->nome, nm, TAMNOME);
  f->nome[TAMNOME] = '\0';

  f->votos = v;
  f->nota  = n;
  f->ano   = a;

  f->prox = f->ant = NULL;	/* paranoia */
  return f;
}

/*
----------------------------------------------------------------------
Funcao insereFilme
	Insere um filme na lista, mas nao verifica se ha filmes duplicados
*/
void insereFilme(Lista *lista, Filme *entrada)
{
  Filme *f;

  if (lista != NULL && !achaFilme(lista, entrada)) {
    f = lista->fim;
    if (f != NULL) {
      f->prox = entrada;
      entrada->ant = f;
      lista->fim = entrada;
    }
    else {
      lista->ini = lista->fim = entrada;
      entrada->ant = entrada->prox = NULL;
    }
  }
}


/*
----------------------------------------------------------------------
Funcao separa
	Recebe uma lista de elementos e devolve um ponteiro para o filme
	'i' que separa os filmes à esquerda com notas maiores ou iguais
	à nota de 'i' e os filmes à direita com notas menores.
*/
static Filme *separa(Lista *lista)
{
	/** VARIÁVEIS *****************************************************/
		Filme *i;	/* Posição que mantêm a relação invariante		 */
		Filme *j;	/* Batedor para percorrer a analisar a lista	 */
		Filme *cab; /* Auxiliar para manter a relação invariante	 */
		Filme *ini; /* Apontador para o primeiro filme da lista		 */
		float nota; /* Guarda a nota que separa os filmes			 */
		
		cab = (Filme *) mallocSafe(sizeof(*cab));
		ini = lista->ini; cab->prox = ini; 
		i = cab; nota = lista->fim->nota;
		
	/** SEPARA ********************************************************/
		for(j = ini; /*ι*/ j != NULL; j = j->prox) 
		{
			if(j->nota >= nota) 
			{
				i = i->prox;
				troca(&i, &j, &lista);
			}
		}
		
		/*------------------------------------------------------------
		  RELAÇÃO INVARIANTE: 										 
		  Em ι, vale que todos os elmentos da lista até 'i' têm notas 
		  maiores ou iguais a 'i'. De 'i->prox' até 'fim', todos têm 
		  notas menores. Resumidamente:								 
		  															 
		  		(ini->...)->nota >= i->nota > (..->fim)->nota 		 
		------------------------------------------------------------*/
		
	/** LIBERAÇÃO DE MEMÓRIA ******************************************/
		free(cab); cab = NULL; j = NULL; ini = NULL;
	
	return i;
}


/*
----------------------------------------------------------------------
Funcao troca
	Recebe o endereço de um filme 'i', o endereço de um filme 'j' e 
	uma lista. Iverte as referências de 'i' e 'j' dentro da lista.
*/
static void troca(Filme **end_i, Filme **end_j, Lista **end_lista)
{
	/** VARIÁVEIS *****************************************************/
		Filme *i; 	   	/* Primeiro elemento da lista a ser trocado	 */
		Filme *j; 	   	/* Segundo elemento da lista a ser trocado	 */
		Filme *swp;    	/* Auxiliar para a troca de 'i' e 'j'		 */
		Lista *lista;	/* Auxiliar para o conteúdo da lista		 */
		Filme *swp_e1; 	/* Auxiliar para a esquerda de 'i'			 */
		Filme *swp_e2; 	/* Auxiliar para a esquerda de 'j'			 */
		Filme *swp_d1; 	/* Auxiliar para a direita de 'i'			 */
		Filme *swp_d2; 	/* Ausiliar para a direita de 'j'			 */
	
	/** TROCAS INVÁLIDAS **********************************************/
		if(end_i == NULL || end_j == NULL) return;
		if( (i = *end_i) == NULL || (j = *end_j) == NULL) return;
		
	/** TROCAS DE POSIÇÃO *********************************************/
		swp_e1 = i->ant; swp_d1 = i->prox;
		swp_e2 = j->ant; swp_d2 = j->prox;
		lista = *end_lista;
		
		if(swp_d1 == j || swp_e2 == i) /* 2 elementos */ 
		{
			/*1*/ j->prox = i; 
			/*2*/ j->ant = swp_e1;
			/*3*/ i->prox = swp_d2; 
			/*4*/ i->ant = j;
			/*5*/ if(swp_e1 != NULL) swp_e1->prox = j;
			/*6*/ if(swp_d2 != NULL) swp_d2->ant = i;
		}
		else /* 3 ou + elementos */
		{
			/*1*/ j->prox = swp_d1; 
			/*2*/ j->ant = swp_e1;
			/*3*/ i->prox = swp_d2; 
			/*4*/ i->ant = swp_e2;
			/*5*/ if(swp_e1 != NULL) swp_e1->prox = j;
			/*6*/ if(swp_d2 != NULL) swp_d2->ant = i;
			/*7*/ if(swp_e2 != NULL) swp_e2->prox = i;
			/*8*/ if(swp_d1 != NULL) swp_d1->ant = j;
		}
		
	/** ORGANIZAÇÃO DE REFERÊNCIAS **********************************/
		swp = *end_i; *end_i = *end_j; *end_j = swp; swp = NULL;
		if(lista->ini == *end_j) lista->ini = *end_i; 
		if(lista->fim == *end_i) lista->fim = *end_j;	
	
	/** LIBERAÇÃO DE MEMÓRIA ******************************************/
		swp_e1 = NULL; swp_d1 = NULL; swp_e2 = NULL; swp_d2 = NULL;
		i = NULL; j = NULL; swp = NULL; lista = NULL;
}


/*
------------------------------------------------------------------------
Funcao adicionaFilme
	Questiona o usuario sobre as caracteristicas do filme. Procura se
	ele existe e, em caso negativo, o adiciona ao fim da lista.
*/
void adicionaFilme(Lista *lista)
{
	/** VARIÁVEIS *****************************************************/
		Filme *novo; /* Apontador para o novo filme que será criado  */
		char *nome; char *dist; int votos; float nota; int ano;

		nome = (char *) mallocSafe(sizeof(TAMNOME+1));
		dist = (char *) mallocSafe(11*sizeof(char));
		
    /** INFORMAÇÕES DO FILME ******************************************/
    	printf("Digite o nome do filme: ");
		leString(nome, TAMNOME+1);
		
		printf("Digite o ano: ");
		scanf("%d", &ano);
		
		printf("Digite a nota: ");
		scanf("%f", &nota);
		
		printf("Digite o numero de votos: ");
		scanf("%d", &votos);
		
		printf("Digite a distribuicao: ");
		leString(dist, 11);
		
	/** INSERÇÃO ******************************************************/
		novo = criaFilme(dist, votos, nota, nome, ano);
		
		/* Filmes repetidos não são inseridos */
		if(achaFilme(lista, novo) == TRUE) 
		{
			free(novo); novo = NULL;
			return;
		}

		/* Coloca o filme não-listado no final */
		insereFilme(lista, novo);
		mostraUmFilme(novo);
	
	/** LIBERAÇÃO DE VARIÁVEIS ****************************************/
		nome = NULL; dist = NULL; novo = NULL;

}


/*
------------------------------------------------------------------------
Funcao buscaFilme
	Questiona o usuario sobre as caracteristicas do filme. Procura se
	ele existe e, em caso negativo, o adiciona ao fim da lista.
*/
void buscaFilme(Lista *lista)
{
	/** VARIÁVEIS *****************************************************/
		Filme *aux;				/* 	Auxiliar para percorrer a lista	 */
		char *nome_procurado;	/* 	Filme buscado pelo usuário		 */
		char *caracterAtual;	/*	Auxiliar para contar 'tNome'	 */
		char opcao[3];			/*	Identifica o filme encontrado	 */
		int tNome;				/* 	Auxiliar para tamanho do nome da
									função auxiliar 'achaPalavra'	 */
		
		nome_procurado = (char *) mallocSafe((TAMNOME+1)*sizeof(char));
		aux = lista->ini;
	
	/** INFORMAÇÕES DO FILME PROCURADO ********************************/
		printf("Digite parte do nome a ser procurado: ");
		leString(nome_procurado, TAMNOME+1);
		printf("%s\n", nome_procurado);
		for(caracterAtual = nome_procurado, tNome = 0; 
			*caracterAtual != '\0'; caracterAtual++, tNome++);
	
	/** LISTA VAZIA ***************************************************/
		if(lista->ini == NULL)
		{
			printf("A lista esta vazia!");
			return;
		}
		
	/** BUSCA DO FILME ************************************************/
		for(aux = lista->ini; aux != lista->fim->prox; aux = aux->prox)
		{
			if(achaPalavra((unsigned char *) nome_procurado, tNome, 
				(unsigned char *) aux->nome, TAMNOME) == TRUE)
			{
				mostraUmFilme(aux); 
				printf("Esse eh o filme procurado? [s/n] ");
				leString(opcao, 3);
				if(!strcmp(opcao, "s")) break;
			}
		}
		
		if(aux == lista->fim->prox)
			printf("\n\nFilme nao encontrado\n");
		
	/** LIBERAÇÃO DE MEMÓRIA ******************************************/
		free(nome_procurado); nome_procurado = NULL; aux = NULL;
}


/*
------------------------------------------------------------------------
Funcao removeFilme
	Questiona o usuario sobre as caracteristicas do filme. Procura se
	ele existe e, em caso negativo, o adiciona ao fim da lista.
*/
void removeFilme(Lista *lista)
{
	/** VARIÁVEIS *****************************************************/
		Filme *aux;				/* 	Auxiliar para percorrer a lista	 */
		char *nome_procurado;	/* 	Filme buscado pelo usuário		 */
		char *caracterAtual;	/*	Auxiliar para contar 'tNome'	 */
		char opcao[3];			/*	Identifica o filme encontrado	 */
		int tNome;				/* 	Auxiliar para tamanho do nome da
									função auxiliar 'achaPalavra'	 */

		nome_procurado = (char *) mallocSafe((TAMNOME+1)*sizeof(char));
		aux = lista->ini;
	
	/** INFORMAÇÕES DO FILME PROCURADO ********************************/
		printf("Digite parte do nome a ser procurado: ");
		leString(nome_procurado, TAMNOME+1);

		for(caracterAtual = nome_procurado, tNome = 0; 
			*caracterAtual != '\0'; tNome++, caracterAtual++);
	
	/** LISTA VAZIA ***************************************************/
		if(lista->ini == NULL)
		{
			printf("A lista esta vazia!");
			return;
		}
		
	/** BUSCA DO FILME ************************************************/
		for(aux = lista->ini; aux != lista->fim->prox; aux = aux->prox)
		{
			if(achaPalavra((unsigned char *) nome_procurado, tNome, 
				(unsigned char *) aux->nome, TAMNOME) == TRUE)
			{
				mostraUmFilme(aux); 
				printf("Esse eh o filme procurado? [s/n] ");
				leString(opcao, 3);
				if(!strcmp(opcao, "s"))
				{
					if(aux->prox != NULL)
						aux->prox->ant = aux->ant;
					else lista->fim = aux->ant;
					
					if(aux->ant != NULL)
						aux->ant->prox = aux->prox;
					else lista->ini = aux->prox;
					
					free(nome_procurado); free(aux);
					nome_procurado = NULL; aux = NULL;
					return;
				}
			}
		}
		
		if(aux == lista->fim->prox)
			printf("\n\nFilme nao encontrado\n");	
	
	/** LIBERAÇÃO DE MEMÓRIA ******************************************/
		free(nome_procurado); nome_procurado = NULL; aux = NULL;
}


/*
------------------------------------------------------------------------
Funcao mostraTopMenores
	A função mostraTopMenores recebe uma lista de filmes. Pergunta ao
	usuário quantos filmes ele deseja exibir, qual a nota máxima e o
	mínimo de notas para que ele seja incluído na lista.
*/
void mostraTopMenores(Lista *lista)
{
	/** VARIÁVEIS *****************************************************/
		int i;			   /* Auxiliar para contador				 */
		int n_filmes;	   /* número de filmes para a lista			 */
		int minimo_votos;  /* mínimo de votos para esta lista 		 */
		float nota_maxima; /* maior nota de um filme nesta lista	 */
		Filme *ponta;	   /* Indica a ponta (inferior) a partir da 
							  qual a lista será analisada.	 		 */
	
	/** DADOS PARA A LISTA ********************************************/
		printf("Qual o numero de filmes a ser mostrado? ");
		scanf(" "); scanf("%d", &n_filmes);
		
		printf("Qual a nota maxima? ");
		scanf(" "); scanf("%f", &nota_maxima);
		
		printf("Qual o numero minimo de votos? ");
		scanf(" "); scanf("%d", &minimo_votos);
	
	/** LISTA VAZIA ***************************************************/
		if(lista->ini == NULL)
		{
			printf("A lista esta vazia!");
			return;
		}
		
	/** IMPRIME A LISTA ***********************************************/
		ponta = lista->ini; i = 0;
		while(i < n_filmes && ponta != lista->fim->prox)
		{
			if(ponta->nota < nota_maxima 
				&& ponta->votos >= minimo_votos)
			{
				mostraUmFilme(ponta);
				i++; 
			}
			ponta = ponta->prox;
		}
	
	printf("--------------------------------------------------------------------------------\n");
	printf("Esses sao o %d melhores filmes com nota menor que %0.1f e "
		"pelo menos %d votos\n", i, nota_maxima, minimo_votos);
}


/*
------------------------------------------------------------------------
Funcao mostraTopMenores
	A função mostraTopMaiores recebe uma lista de filmes. Pergunta ao
	usuário quantos filmes ele deseja exibir, qual a nota mínima e o
	mínimo de notas para que ele seja incluído na lista.
*/
void mostraTopMaiores(Lista *lista)
{
	/** VARIÁVEIS *****************************************************/
		int i;			   /* Auxiliar para contador				 */
		int n_filmes;	   /* número de filmes para a lista			 */
		int minimo_votos;  /* mínimo de votos para esta lista		 */
		float nota_minima; /* menor nota de um filme nesta lista	 */
		Filme *ponta;	   /* Indica a ponta (superior) a partir da 
							 qual a lista será analisada.			 */
	
	/** DADOS PARA A LISTA ********************************************/
		printf("Qual o numero de filmes a ser mostrado: ");
		scanf(" "); scanf("%d", &n_filmes);
		
		printf("Qual a nota minima: ");
		scanf(" "); scanf("%f", &nota_minima);
		
		printf("Qual o numero minimo de votos: ");
		scanf(" "); scanf("%d", &minimo_votos);
	
	/** LISTA VAZIA ***************************************************/
		if(lista->ini == NULL)
		{
			printf("A lista esta vazia!");
			return;
		}
		
	/** IMPRIME A LISTA ***********************************************/
		ponta = lista->fim; i = 0;
		while(i < n_filmes && ponta != lista->ini->ant)
		{
			if(ponta->nota > nota_minima 
				&& ponta->votos >= minimo_votos)
			{
				mostraUmFilme(ponta);
				i++; 
			}
 			ponta = ponta->ant;
		}
	
	printf("--------------------------------------------------------------------------------\n");
	printf("Esses sao o %d piores filmes com nota maior que %0.1f e "
		"pelo menos %d votos\n", i, nota_minima, minimo_votos);
}
