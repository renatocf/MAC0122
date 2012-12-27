/* 	Para criarmos matrizes, precisamos utilizar uma metodologia diferente.
	Usaremos, parar criar esta matriz, um ponteiro de ponteiro, na sequin-
	te forma.
	Suponhamos uma matriz de 'm' linhas e 'n' colunas: */
	
	int **A;
	
	A = malloc(m * sizeof(int *));
	for(i = 0; i < m; i++)
		A[i] = malloc(n * sizeof(int));
	
	/* 	O ponteiro duplo equivale a termos criado um array de ponteiros,
		armazenado com o nome de A, e cuja função é apontar para várias 
		mini-vetores na memória.
		O 'for' faz múltiplas alocações, associando-as à vários vetores do
		tipo de variável que quisermos.
		Assim, criamos um meio de, na memoria LINEAR, criar uma estrutura
		equivalente a uma matriz (bidimensional).
		
		A forma dessa matriz seria:
	
					 |--------- COLUNAS ---------|	Estrutura GERAL do ve-
	 				   0   1   2   3   4   5   6	tor alocado com malloc:
	|L|	0 |*int| --> |int|int|int|int|int|int|int|	As linhas servem de 
	|I|	1 |*int| --> |int|int|int|int|int|int|int|	apontadores para o que
	|N|	2 |*int| --> |int|int|int|int|int|int|int|	será formado nas colu-
	|H|	3 |*int| --> |int|int|int|int|int|int|int|	nas. Apesar de parecer
	|A|	4 |*int| --> |int|int|int|int|int|int|int|	complicado, essa forma
	|S|	5 |*int| --> |int|int|int|int|int|int|int|	permite que chamemos a
													linha 'i' e coluna 'j'
													na forma A[i][j]
