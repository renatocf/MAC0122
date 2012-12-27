/*	REDE DE ESTRADAS
	
	Cidades numeradas de 0 a n-1
	
		(2)<----(1)		|	PROBLEMA: Dada uma rede de estradas e
	   ^   \   / ^		|	uma cidade 'c', determinar a distância
	  /     \ /  |		|	de 'c' a cada uma das demais cidades.
	 /		^ ^  |		|
	(0) --->(4)  |		|
	 \		^ ^  |		|	
	  \    /   \ |		|	Ex: para c=0
 	   \  /     \|		|	  i	 | 0 | 1 | 2 | 3 | 4 | 5 |
		(3)---->(5)		|	d[i] | 0 | 3 | 1 | 1 | 1 | 2 |
	
	
	Para sabermos como procurar, de forma sistemática, a melhor distân-
	cia, podemos realizar uma busca em CAMADAS (busca em largura). Ao
	fazermos isso, podemos ver os caminhos. Ao rotular uma das cidades,
	temos uma certeza: se ele já estiver rotulado, é porque pertence a
	um nível MENOR ou IGUAL ao da camada a ser preenchida atualmente.
	Caso contrário (ele não está rotulado), devemos rotulá-lo.
	
	No primeiro caso, temos o seguinte:
	
	No início, a única  |  	A partir do ponto   |	A partir do primeiro
	distância disponí-	|	inicial, preenche-	|	preenchido com 1 (o
	vel é a do ponto 	|	mos os ligados di-	|	de cima) olhamos os 
	inicial (0)			|	retamente a ele.	|	caminhos possíveis
	                    |                       |
	  ?	(2)<----(1) ?	|	  1	(2)<----(1)	? 	|	  1	(2)<----(1) ?
	   ^   \   / ^   	| 	   ^   \   / ^		| 	   ^   \   / ^      
	  /     \ /  |   	|	  /     \ /  |		|	  /     \ /  |      
	 /	  ?	^ ^  |   	|	 /    1	^ ^  |		|	 /    1	^ ^  |      
  0	(0) --->(4)  |    	| 0	(0) --->(4)  |	 	| 0	(0) --->(4)  |      
	 \		^ ^  |  	| 	 \		^ ^  | 		|  	 \		^ ^  |  
	  \    /   \ |      |	  \    /   \ |		|	  \    /   \ |  
	   ^  /     \|  	| 	   ^  /     \|	    |	   ^  /     \|  
	  ?	(3)---->(5) ?	|	  1	(3)---->(5	?	|	  1	(3)---->(5)	?
	                    |                       |
	                    |                       |
	O segundo preenchi-	|	O terceiro preen-	|	O único com rótulo
	do com 1 tem os ca-	|	chido com 1 tem  	|	2 é o 5 - e com is-
	minhos ao redor o-	|	apenas 1 ligação 	|	so, procuramos até
	lhados - e não vai	|	com um não rotu-	|	onde ele vai - o 
	para nenhum		    |	lado - o 5			|	1
	                    |                       |
	1	(2)<----(1)	?	|	  1	(2)<----(1)	?	|	  1	(2)<----(1)	3
       ^   \   / ^  	|  	   ^   \   / ^      |  	   ^   \   / ^    	
   	  /     \ /  |    	|	  /     \ /  |   	|	  /     \ /  |      	
   	 /    1	^ ^  | 		|  	 /    1	^ ^  |      |  	 /    1	^ ^  |    	
  0	(0) --->(4)  |  	| 0	(0) --->(4)  |      | 0	(0) --->(4)  |    	
   	 \		^ ^  |    	| 	 \		^ ^  |   	| 	 \		^ ^  |    		
   	  \    /   \ |     	|	  \    /   \ |    	|	  \    /   \ |    	
   	   ^  /     \|  	|  	   ^  /     \|      |  	   ^  /     \|    	
   	  1	(3)---->(5)	?	|  	  1	(3)---->(5)	2	|   	  1	(3)---->(5)	2
						|
						|
	No último caso, o-	|	Neste caso, temos um algoritmo chamado de
	lhamos o elemento 	|	BUSCA EM LARGURA, o qual pode ser utiliza-
	de nível 3 - que 	|	do para encontrar o menor caminho.
	não vai para ne-	|	
	nhum rotulado		|	A estrutura mostrada, na lógica de percor-
						|	rer os caminhos, tem um sentido: o primeiro
	  1	(2)<----(1)	3	|	elemento a ser rotulado é o primeiro a ser
   	   ^   \   / ^    	|	analisado, tal qual numa FILA, onde o pri-
	  /     \ /  |    	|	meiro a chegar é o primeiro a ser atendido.
  	 /    1	^ ^  |    	|	
  0	(0) --->(4)  |    	|	Estudaremos, agora, este tipo de estrutura
 	 \		^ ^  |    	|	de dados chamada de FILA (queue).
	  \    /   \ |    	|	
   	   ^  /     \|    	|	
      1 (3)---->(5)	2	|	
	
	
	FILAS (QUEUE)
	
	Uma fila é uma LISTA DINÂMICA em que as inserções são em uma extre-
	midade chamada de FIM e as remoções são feitas na outra extremidade
	chamada de INÍCIO (filosofia FIFO - First In, First Out).
	
	IMPLEMENTAÇÃO EM UM VETOR
	
	q 	|	|	|	|%%%|%%%|%%%|%%%|%%%|	|	|	|
				   ini				   fim		   n-1

	x = q[ini++]; - Para remover um elemento da fila 
	x = q[fim++]; - Para inserir um elemento 
	
		A fila está vazia quando ini == fim 			
	 	A fila está cheia se fim == n (nº de elementos)	

	Construamos, agora, a função para calcular a distânci */

/*					|-- Cidade inicial
					|	   |-- Número de cidades
					^	   ^		^-- Matriz de caminhos */
int *distancias(int c, int n, int **A)
	/* 	A função recebe a cidade inicial e a "rede de estradas". Esta
		rede será dada por meio de uma matriz com linhas e colunas re-
		presentando cada cidade e tendo 0 se não houver ligação (e na
		cidade para ela mesma) e 1 se houver ligação. 
		
		Ex: 6 cidades							| As ligações entre as
				   6 linhas						| cidades são represen-
			/-------------------\				| tadas por uma matriz
			0	0	0	0	0	0 ---			| A, sendo:
			0	1	0	1	0	0  |			| - A[i][j] == 1 se exis-
			0	0	1	0	1	0  |  6 colunas	|   te estrada de 'i' pa-
			0	0	0	0	0	1  |			|   ra 'j';
			1	0	0	1	1	0  |			| - A[i][j] == 0 se não
			1	0	0	0	1	0 ---			|   existe esta estada.
	*/
	
	/** ALOCAÇÃO DE VARIÁVEIS *****************************************/
		int *d;			/* 	Vetor de distâncias que será retornado 	  */
/**/	int *q;			/* 	Variável para armazenar a fila 			  */
/**/	int ini, fim;	/* 	Variáveis para o primeiro e o último da
							fila 									  */
		int j;			/* 	*/
	
	/** ALOCAÇÃO DA FILA **********************************************/
		d = malloc(n * sizeof(int)); /* Alocação do vetor de distâncias
										em relação a cidade inicial */
/**/	q = malloc(n * sizeof(int)); /* A fila terá, no máximo, 'n' ele-
										mentos */
/**/	ini = fim = 0; /* Fila inicialmente vazia */
		
	/** INICIALIZAÇÃO DAS DISTÂNCIAS **********************************/
		for(j = 0; j < n; j++)
			d[j] = n; /* O 'n' representa o "infinito" - a distância
						 percorrida desconhecida */
		d[c] = 0;	/* Inicialmente, a distância do ponto inicial é 0 */
		q[fim++] = c; /* Colocamos na fila o primeiro elemento, para de-
						 pois olharmos a distância até ele */
	
	/** ENCONTRANDO OS CAMINHOS ***************************************/
		while(/**/ini != fim)
			/* 	Ennquanto a lista não se esvaziar (sinal de que vimos 
				todos os elementos */
		{
			int i = q[ini++];
			int di = d[i];	/* Somente uma variável auxiliar para a 
							   distância do elemento 'i' */
			for(j = 0; j < n; j++)
				if(A[i][j] == 1 && d[j] == n)
					/* CONDIÇÃO: haver ligação com a cidade (1 na ma-
								 triz) e ele ainda não ter sido rotu-
								 lado */
				{
					d[j] = di + 1; /* Adicionamos o rótulo da camada
									  seguinte */
					q[fim++] = j; /* Adicionamos 'j' ao fim da fila,
									 pois ele está ligado a última
									 cidade */
				}
		}
		
		free(q); /* Liberamos 'q' (a fila) */
	
	
	return d;
}
