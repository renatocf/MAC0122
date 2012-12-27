/*	PROBLEMA DO PASSEIO DO CAVALO
	
	PROBLEMA: Suponha dodo um tabuleiro nxn. Determinar se é possível
	que um cavalo na ponta da posição (1,1) e complete um passeio
	pelas n² posições.
	
	Usaremos a seguinte codificação para os movimentos:
	
	+---+---+---+---+---+	
	|   | 3 |   | 2 |   |	} MOVIMENTOS DO CAVALO
	+---+---+---+---+---+	} Seguem no sentido anti-horário, res-
	| 4 |   |   |   | 1 |	} peitando os movimentos do xadrez.
	+---+---+---+---+---+	} 
	|   |   | H |   |   |	
	+---+---+---+---+---+	
	| 5 |   |   |   | 8 |	
	+---+---+---+---+---+	
	|   | 6 |   | 7 |   |	
	+---+---+---+---+---+	*/

typedef struct {	
	int i;
	int j;
} Movimento;


void passeioCavalo(int n)
{
	int **ab;			/* MATRIZ do tabuleiro */
	int i, j;			/* Posição do cavalo */
	int iProx; jProx;	/* Posições tentadas */
	int *s;				/* Pilha */
	int k;				/* Passo (movimento) atual */
	int mov;			/* Tipo do movimento */
	
	/*
		  ^-- Guarda o último movimento
		| 1 | 2	| 1	| 8	| 2	| 5	|	|	|
								  k -> movimento atual
	*/
	
	Movimento movimento[8];
		/* Vetor de estrutudas Movimento, cada um com campos 'i' e 'j'*/
	
	movimento = { {-1, 2}, 	/*1*/
				  {-2, 1}, 	/*2*/
				  {-2, -1}, /*3*/
				  {-1, -2}, /*4*/
				  { 1, -2},	/*5*/
				  { 2, -1},	/*6*/
				  { 2,  1},	/*7*/
				  { 1,  2}  /*8*/ };	
	/* 	Posições inicializadas usando a inicialização de vetores mistura-
		da com a inicialização de estruturas. */
	
	s = mallocSafe( (n*n+1) * sizeof(int)); /* Inicializa pilha */
	
	tab = mallocSafe( (n+1) * sizeof(int *)); /* Inicializa tabuleiro */
	for(i = 1; i <= n; i++)
		tab[i] = calloc(n+1, sizeof(int));
	/* Faz o mesmo que o malloc, mas inicizliza tudo com 0 */
	
	
	/* Inicializa */
 	i = j = k = 1;	/* Começamos em (1,1) com o movimento tipo 1 */
	tab[i][j] = 1;	/* O cavalo está em (1,1) do tabuleiro */
	mov = 0; 		/* Nenhum movimento no início */
	
	while(0 < k && k < n*n)
		/* 	Enquanto for maior que 0 e não tivermos tentado todas as pos-
			sibilidades */
	{
		int achouMov = FALSE;
		while(mov < 8 && achouMov == FALSE)
		{
			iProx = i + movimento[mov].i;
			jProx = j + movimento[mov].j;
			if( (1 <= iProx && iProx <= n)		/*posição válida*/
				&& (1 <= jProx && jProx <= n)	/*posição válida*/
				&& tab[iProx][jProx] == 0)		/*Não tiver sido 
												  percorrido ainda */
				achouMov = TRUE;
			else mov+= 1;	/* 	Se tentamos o movimento e não consegui-
								mos, vamos para o próximo */
		}
		
		if(mov < 8) /*AVANÇA*/
		{
			s[k++] = mov;	/* Vetor recebe o último movimento feito */
			i = iProx;		/* Nosso 'i' é o que era da tentativa */
			j = jProx;		/* Nosso 'j' é o que era da tentativa */
			mov = 0;		/* O próximo movimento a ser tentado é o 0,
							   que corresponde ao tipo '1' */
			tab[iProx][jProx] = k-1;
				/* 	Na tabela, nas posições [iProx][jProx], recebemos
					qual foi o 'passo' dado para chegar lá */
		}
		else
		{
			tab[i][j] = 0;			/*Reinicializamos como não acessado*/
			k -= 1;					/*Fazemos como se não houvessemos da-
									  do o último passo */
			mov = s[k];				/*O último movimento dado*/
			i -= movimento[mov].i;	/*Voltamos à posição antiga*/
			j -= movimento[mov].j;	
			mov++;					/*Tentamos o movimento seguinte*/
		}
	}
}
