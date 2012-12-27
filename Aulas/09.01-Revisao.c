/* REVISÃO - LISTAS LIGADAS */
struct celula {
	int conteudo;			/* Conteúdo armazenado */
	struct celula *prox;	/* Armazenamento da próxima casa */
};

typedef struct celula Celula;

Celula *ini;	
ini = NULL; 	/* Não há elementos no início */

/* |/| - Representação do início */

/* 
	|I| --> |con|&|	--> |con|&| --> |con|&|	--> |con|/|
	Início	Célula		Célula		Célula		Célula
*/

void imprima(Celula *ini)
{
	Celula *p;
	p = ini;
	while(p != NULL) {
		printf("%d", p->conteudo);
		p = p->prox; /* Faz com que a lista seja percorrida */
	}
}

/* 
	|I| --> |con|&|	--> |con|&| --> |con|&|	--> |con|/|
	Início	Célula		Célula		Célula		Célula
			^-----										(1ª Iteração)

	|I| --> |con|&|	--> |con|&| --> |con|&|	--> |con|/|
	Início	Célula		Célula		Célula		Célula
						^-----							(2ª Iteração)
	
	|I| --> |con|&|	--> |con|&| --> |con|&|	--> |con|/|
	Início	Célula		Célula		Célula		Célula
									^-----				(3ª Iteração)
	
	|I| --> |con|&|	--> |con|&| --> |con|&|	--> |con|/|
	Início	Célula		Célula		Célula		Célula
												^-----	(4ª Iteração)
	Como a célula, agora, tem NULL, então o laço para. */
	
	Celula X;
	X.conteudo;	/* Chamada de parâmetros para X */
	X.prox;
	Celula *p;
	p = &X;		/* Criando um ponteiro para células Celula */
	
	
	(*p).conteudo = 5;	/* As expressões são equivalentes */
	p->conteudo=5;
	
	(*p).prox = NULL;	/* As expressões são equivalentes */
	p->prox = NULL;
