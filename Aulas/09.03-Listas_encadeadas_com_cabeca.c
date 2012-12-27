/* 	LISTAS COM CABEÇA
	
	A diferença destas inhas é que elas têm uma célula inútil apenas
	para ser sempre a primeira célula da lista.
	O esquema delas é:

	|I| --> |///|&|	--> |con|&| --> |con|&|	--> |con|/|
	Início	Cabeça		Célula		Célula		Célula
	
	Vamos fazer os análogos às funções anteriores para listas com cabeça */

void imprima()
{
	Celula *p;
		/* 	A maior mudança é que, em vez de começarmos pegando o conteú-
			do das próprias células, por causa da cabeça olhamos sempre
			para o próximo à célula atual */
	for(p = ini->prox; p != NULL; p = p->prox) {
		printf("%d", p->conteudo);
}

void insere(Celula *ini, int x)
{
	Celula *nova;
		/* Criamos uma célula nova */
	nova = malloc(sizeof(Celula));
		/* Alocamos a célula nova */
	nova->conteudo = x;
		/* Guardamos 'x' dentro de 'nova' */
	nova->prox = ini->prox;
		/* Nova passa a apontar para onde a cabeça estava apontando */
	ini->prox = nova;
		/* Nova passa a ser a apontada por ela */
}
