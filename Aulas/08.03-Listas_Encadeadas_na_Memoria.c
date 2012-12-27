/* 	LISTAS ENCADEADAS NA MEMÓRIA
	
	  O código acima foi implementado utilizando um VETOR de tamanho pré-
	definido. Porém, podemos trocar essa estrutura por algo diferente: a 
	própria MEMÓRIA do computador. Em vez de 'índices' teremos ENDEREÇOS e 
	em vez de um 'inteiro' próximo, teremos o APONTADOR próximo. Na úl-
	tima posição, em vez de termos um inteiro '-1', teremos o valor NULL.
	  Usamos, nesse caso, a função 'malloc' para criar as estruturas - e 
	nesse caso não temos limites (apenas a memória do computador).
*/

#include<stdio.h>
#include<stdlib.h>
#define FIM -1


int main(int argc, char *argv[])
{
	struct celula{
		int conteudo;
		struct celula *prox;
	}
	
	typedef struct celula Celula;
	Celula *ini;	/* Começa a lista */
	ini = NULL.		/* A lista começa vazia */
	
	return 0;
}


void
imprime(Celula *ini)
{
	Celula *p;
	p = ini;
	while(p != NULL)
	{
		printf("%d", p->conteudo);	/* (*p).conteudo */
						/* 	Acessamos uma subparte do endereço e ai a 
							modificamos, usando para isso a estrutura 
							'p->conteudo' */
		P = P->prox;
	}
}


/* Celula * busca
	Pode ficar separado, porque a representação de "devolve ponteiro da 
	estrutura do tipo 'Celula' " é "Celula *". Porém, habitua-se a colocar
	* junto ao nome da função, como abaixo. */
Celula *busca(Celula *ini, int x)
{
	Celula *p;
	p = ini;
	while(p != NULL && p->conteudo != x)
		p = p->prox;
	return p;
}
