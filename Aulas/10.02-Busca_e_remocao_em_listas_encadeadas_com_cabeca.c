void imprima()
{
	Celula *p;
		/* 	A maior mudança é que, em vez de começarmos pegando o conteú-
			do das próprias células, por causa da cabeça olhamos sempre
			para o próximo à célula atual */
	for(p = ini->prox; p != NULL; p = p->prox) {
		printf("%d", p->conteudo);
}
/*********************************************************************/
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
/*********************************************************************/
/*	  TODAS ESTAS FUNÇÕES FORAM IMPLEMENTADAS EM AULAS ANTERIORES 	 */
/*********************************************************************/
void buscaRemove(int x, Celula *ini)
	/* 	Busca e remoção em uma lista:
		Remove, caso exista, a primeira célula da lista 'ini' que con-
		tém X */
{
	/* ATRIBUIÇÕES ***************************************************/
	Celula *p, *q; /* Criando as variáveis para percorrer a lista */
	
	
	/* CASO 1: LISTA VAZIA *******************************************/
		/* 	Não é necessário, pois a lista sempre terá ao menos uma 
			célula - a cabeça. */	
	
	/* CASO 2: 'X' NA PRIMEIRA CÉLULA ********************************/
		/* 	Não é necessária, pois o primeiro elemento ÚTIL da célula
			sempre será, pelo menos, 'q'. */
                                                                      
	/* CASO 3: GERAL *************************************************/
		/*	É o único necessário, pois todos os casos são cobertos 
			por esta situação. */
		
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

	/*return ini;*/
		/* 	Não precisamos retornar nada, pois em todo caso estamos 
			modificando apenas a lista, cuja cabeça (que nunca dei-
			za de existir) já é possuída por quem chamou a função - 
			não temos mais o problema do apontador ser uam variável
			local */
}
/*********************************************************************/
	inverta(Celula *ini)
	/*	Inverte a ordem dos elementos da célula */
{
	Celula *p, *q, *r; 	/*	'p' e 'q' são auxiliares para executar a 
							tarefa*/
	
	/*	A lógica inicial do problema, para o caso mais geral, é:	
		q->prox = p; /  A célula atual (q) passa a apontar para a 
						anterior /
		p = q;		 
		q = r;		 /  Movendo os apontadores auxiliares pela
						célula /
		r = q->prox;
	*/
	
	p = NULL;		
	q = ini;		
	r;
	/* 	Para as inicializações, devemos pensar no primeiro caso:
		|I| -> |cont|&| -> |cont|&| -> |cont|&| -> ...
				  ^
				  |----	Sempre alteramos o que houver em 'q'. Pre-
						cisamos, para o primero caso, que ele apon-
						te para NULL, pois é o primeiro (e como ele
						aponta para 'p', então 'p' deve receber 
						NULL. 
	*/
	
	while(q != NULL)
		/* 	O laço para quando q == NULL, pois se fosse com 'r', o
			laço não executaria a última vez. */
		/* 	Usamos a lógica e o primeiro caso para fazer o laço */
	{
		r = q->prox; /* Primeiro, andamos 'q' */
		q->prox = p; /* Fazendo a inversão do ponteiro */
		p = q;	/* Andando as variáveis */
		q = r;  /* Andando as variáveis */
	}
	
	return p;
	/* 	Na última iteração, quando temos 'p' já se tornou NULL e 'q' 
		foi movida para a posição de 'r' (NULL), 'p' é movido para 
		a última posição e 'p' é quebrado. Como nossa variável 'ini'
		é local, devemos retornar algo que aponte para o novo 'ini'.
		Nesse caso, é 'p'.
	*/
}
