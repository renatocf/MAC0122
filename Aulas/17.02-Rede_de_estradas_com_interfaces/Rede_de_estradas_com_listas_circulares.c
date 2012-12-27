/*	Utilizaremos, agora, listas CIRCULARES para implementar o problema
	de redes de estradas */

typedef struct queueNode *Link
/* Para facilitar a escrita */

struct queueNode {
	/* Célula da lista ligada */
	Item conteudo;
	Link prox;
}

Link ini; /* Ponteiro para a lista circular */

/* Criemos as funções para a implementação */
void queueInit(int n)
	/* 	Não usaremos o 'n', pois a lista é dinâmica */
{
	ini = malloc(sizeof *ini);
	/* 	Equivalente a ini = malloc(sizeof(struct queueNode)) */
	ini->prox = ini;
	/*	Como a lista é CIRCULAR, o último elemento da lista
		aponta para o PRIMEIRO - no caso, o início aponta para
		ele mesmo */
}

Item queueGet() 
	/* Retira um elemento da fila e devolve seu conteúdo */
{
	Link p = ini->prox;			/* Auxiliar para guardar para quem ini
								   aponta */
	Item item = p->conteudo;	/* Guardamos o conteúdo */
	ini->prox = p->prox;		/* Recebe para quem o elemento antigo
								   apontava */
	free(p);					/* Liberamos o elemento da fila */
	return item;				/* Devolvemos a informação */
}

void queuePut(Item item)
	/*  Para colocar elementos na "fila" - neste caso, temos um problema,
		pois não há um elemento claro a ser colocado */
	Link nova = malloc(sizeof *nova);
	ini->conteudo = item;
		/* 	Agora, estamos colocando conteúdo nacélula cabeça, a qual
			deveria ser inútil. E faremos a nova célula ser a nova ca-
			beça */
	nova->prox = ini->prox;
		/* 	A nova célula recebe o próximo da cabeça - o primeiro ele-
			mento. */
	ini->prox = nova;
		/*	Agora, a cabeça passa a apontar para a nova */
	ini = nova;
		/*	Agora, ini aponta para a célula nova, que será a nova ca-
			beça */
}

void queueFree()
	/* Libera a lista circular */
{
	Link p = ini->prox;
	while(p != ini) {
		Link t = p->prox;
		free(p);
		p = t;
	}
}
