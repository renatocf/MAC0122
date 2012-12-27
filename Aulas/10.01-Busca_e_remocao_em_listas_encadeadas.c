#include<stdio.h>
#include<stdlib.h>
#define FIM -1

/*********************************************************************/
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
/*********************************************************************/
void imprime(Celula *ini)
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
/**********************************************************************/
Celula *busca(Celula *ini, int x)
{
	Celula *p;
	p = ini;
	while(p != NULL && p->conteudo != x)
		p = p->prox;
	return p;
}
/*********************************************************************/	
Celula *insere(Celula *ini, int x)
{	
	Celula *nova;					/* Trabalhando com malloc, a memória */
	nova = malloc(sizeof(Celula));	/* continua guardada mesmo depois do */
	nova->conteudo = x;				/* fim da função, estando disponível */
	nova->prox = ini;				/* externamente.					 */
	return nova;
}
/**********************************************************************/
void remove(Celula *p)
	/* 	A função, para remover, supõe que p->prox != NULL e que 
		o parâmetro p != NULL */
{
	if(p == NULL) {
		printf("Impossível remover o próximo ao nada (seu parâmetr é
				NULL");
	}
	if(p->prox == NULL) {
		printf("Impossível remover o nada! (Sua célula aponta para NULL");
	}
 
	Celula *morta;
	morta = p->prox;
	p->prox = morta->prox
	free(morta);
}
/**********************************************************************/
/* 	 TODAS AS FUNÇÕES ACIMA FORAM IMPLEMENTADAS EM AULAS ANTERIORES	  */
/**********************************************************************/

/* 	BUSCA E REMOÇÃO EM UMA LISTA
	
	Remove, caso exista, a primeira célula da lista ini que contém 'x'.
*/
Celula *buscaRemove(int x, Celula *ini)
{
	/* ATRIBUIÇÕES ***************************************************/
	Celula *p, *q; /* Criando as variáveis para percorrer a lista */
	
	
	/* CASO 1: LISTA VAZIA *******************************************/
	if(ini == NULL) return ini;
		/* Caso a lista esteja vazia, retornamos a lista de volta */
	
	
	/* CASO 2: 'X' NA PRIMEIRA CÉLULA ********************************/
	if(ini->conteudo == x) {
		/* 	O primeiro caso é especial, pois o algoritmo, na realidade,
			não consegue verificar quando 'p' (o primeiro elemento) 
			tem 'X', mas apenas quando o segundo ('q') tem 'X' */
		q = ini; ini=q->prox; free(q);
		/* Armazenamos 'ini' para podermos liberá-la depois */
	}
                                                                      
	
	/* CASO 3: GERAL *************************************************/
	else {
		p = ini; /* 'p' sempre armazenará o endereço da célula 
					anterior a 'q'*/
		q = p->prox; /* 'q' armazena o endereço da cálula seguinte a
						'p'*/
		
		while(q != NULL && q->conteudo != x)
			/*	Em C, quando temos operadores lógicos && e ||, se
				uma condição para FALSO (em &&) ou VERDADEIRO (em ||), 
				a função já retorna verdadeiro e sai da célula */
		{
			p = q;	/* Vai percorrendo a célula para buscar 'x' */
			q = q->prox;	
		}
	
		if(q != NULL) {
			p->prox = q->prox; /* Liberamos 'q' se ele for não vazio */
			free(q);			
		}
	}/*else*/
	
	return ini;
	/* 	Precisamos fazer este retorno porque podemos acabar perdendo o 
		início da lista, visto que ele é uma variável LOCAL e que não
		e acessível a quem chamou a função. */
}
