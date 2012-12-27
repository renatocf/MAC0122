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


/* 	INSERE NO COMEÇO DA LISTA (sem cabeça)
	
	Cria uma célula para guardar um elemento 'X' e insere a célula no
	início da lista 'ini'.
*/
Celula *insere(Celula *ini, int x)
{
	
/*	Celula nova;							   */	/* Essa forma seria  */
/*	nova.conteudo = x;						   */	/* interessante, mas */
/*	nova.prox = ini;						   */	/* a variável 'nova' */
/*	ini = &nova;*/ 		/* A célula é o início */	/* não existirá mais */
													/* quando a função 	 */
													/* acabar (na verda- */
													/* de, a área estará,*/
													/* para o sistema, 	 */
													/* livre para ser u- */
													/* sada, e poderá ser*/
													/* usada quando ne-	 */
													/* cessario. */
	
	/* 	O que estamos fazendo é:		
		|I|     |con|&|	--> |con|&| --> |con|&|	--> |con|/|
		Início	Célula		Célula		Célula		Célula
		 |		 ^
		 |		 |
		 `{	| x |&|											*/

	/* A função correta seria: */
	
	
	Celula *nova;					/* Trabalhando com malloc, a memória */
	nova = malloc(sizeof(Celula));	/* continua guardada mesmo depois do */
	nova->conteudo = x;				/* fim da função, estando disponível */
	nova->prox = ini;				/* externamente.					 */
	return nova;
		/* 	Essa é a nova célula inicial. Não podemos fazer uma simples
		 	atribuição porque essa variável é local. */
	
	/* 	Façamos uma simulaçaõ da função:
			
		|I|     |con|&|	--> |con|&| --> |con|&|	--> |con|/|
		Ini		Célula		Célula		Célula		Célula
				 100 - Suponhamos que este endereço valha 100
				  ^---------------------|
										|
		|---------------------------|	|
		| ini	 X		nova		|	|
		| 100	11		 ?			|	|
		| 200						|	|
		|  |						|	|
		|  |----------^				|	|
		| 			| 11 |100| -----:---|
		|			Célula			|
		|			(suponhamos o 	|
		|			endereço 200)	|
		|---------------------------|	A variável faz as atribuições
										corretas, porém, a variável ini
										acaba com o fim da função. Para
										que este 'ini' passado fosse mo-
										dificado externamente, teríamos
										duas alternativas:
										- criar um ponteiro duplo (**ini),
										  com o objetivo de modificar o 
										  ponteiro em si;
										- realizar um 'return' de ini, pa-
										  ra quem chamou a função poder 
										  alcançar este conteúdo. */
void remove(Celula *p)
	/* 	A função, para remover, supõe que p->prox != NULL e que 
		o parâmetro p != NULL */
{
	if(p == NULL)
	{
		printf("Impossível remover o próximo ao nada (seu parâmetr é
				NULL");
	}
	if(p->prox == NULL)
	{
		printf("Impossível remover o nada! (Sua célula aponta para NULL");
	}
 
	Celula *morta;			/* 	Criamos uma variável auxiliar 			*/
	morta = p->prox;		/* 	A célula morta é a seguinte à passada como
								parâmetro 								*/
	p->prox = morta->prox;	/*	Agora, religamos a célula anterior à morta
								com a seguinte a ela 					*/
	
	free(morta); /* Liberamos a célula morta para o sistema. */
}
