/*	LISTAS ENCADEADAS/LISTAS LIGADAS
	
	Uma lista encadeada é uma sequência de CÉLULAS, cada célula contém um
OBJETO (informação a ser armazenada na lista) e o endereço da célula se-
guinte.
	Esquematicamente, temos:	
	|&|--> [info|&]--> [info|&]--> [info|&]--> [info|&]--> |&|
	
	Para implementar este tipo de lista encadeada, precisamos criar 
	estruturas:
*/

#include<stdio.h>
#include<stdlib.h>
#define FIM -1

/*  P R O T Ó T I P O S  */
void
imprime(int inicio, Celula v[]);

void
remocao(int p, int v[])

void
insere(int p, int v[])


/*  M A I N  */
int main(int argc, char *argv[])
{
	struct celula {		/* Célula para representar o conteúdo juntamente */
		int conteudo;	/* do próximo elemento */
		int prox;
	}

	typedef struct celula Celula;
	
	int inicio;		/* Posicao do primeiro elemento da lista */
	int livre;		/* Posição mais à esquerda livre no vetor */

	Celula v[124];	/* 	Criamos um vetor dessas células, sendo que esta */
					/*	lista tem, no máximo, 124 elementos 			*/
	return 0;
}


/*  F U N Ç Õ E S  */
void 
imprime(int inicio, Celula v[])
	/* 	A função recebe a posição correspondente ao início do vetor de 
		células v[] e imprime todos os elementos listados. */ 
{
	int p;
	p = inicio;
	while(p != FIM)
	{
		printf("%d", v[p].conteudo);
		p = v[p].prox;
	}
}


void
remocao(int p, int v[])
	/* 	Dado um índice 'p' de uma célula de um vetor v, remove a célula de
		 índice v[p].prox armazenado junto a 'p'. */
{
	int morta;					/* 	Para armazenar a célula morta. 		 */
	morta = v[p].prox;			/* 	A célula morta tem o índice da célula
									que se quer retirar da lista. 		 */
	v[p].prox = v[morta].prox;	/*	Para desligá-la, apontamos o elemento
									anterior à cálula morta para a célula
									após ele. 							 */
	v[morta].prox = livre;		/*	Ligamos a célula morta à "lista para-
									lela" das células livres. 			 */
	livre = morta;				/*	Agora, esta célula passa a ser a pri-
									meira dessa lista de células livres  */
}


void
insere(int p, int v[])
	/* 	Dado o índice 'p' da célula de um vetor v, adiciona uma célula 
		entre 'p' e 'v[p].prox' */
{
	int inserido;					/* 	Cria uma variável para representar
										a posição do elementoa ser inseri-
										do entre 'p' e 'v[p].prox'		*/
	inserido = livre;				/*	O novo elemento estará na primeira
										posição livre disponível		*/
	livre = v[inserido].prox;		/*	A lista secundária de "livres" co-
										neça agora na segunda posição da 
										lista */
	v[inserido].prox = v[p].prox;	/*	Ligamos a nova célula ao elemento
										seguinte a v[p] */
	v[p].prox = inserido;			/*	Agora, o próximo elemento de v[p]
										é a nova célula */
}


/* 	LISTAS ENCADEADAS NA MEMÓRIA
	
	  O código acima foi implementado utilizando um VETOR de tamanho pré-
	definido. Porém, podemos trocar essa estrutura por algo diferente: a 
	própria MEMÓRIA do computador. Em vez de 'índices' teremos ENDEREÇOS e 
	em vez de um 'inteiro' próximo, teremos o APONTADOR próximo. Na úl-
	tima posição, em vez de termos um inteiro '-1', teremos o valor NULL.
	  Usamos, nesse caso, a função 'malloc' para criar as estruturas - e 
	nesse caso não temos limites (apenas a memória do computador).
*/
