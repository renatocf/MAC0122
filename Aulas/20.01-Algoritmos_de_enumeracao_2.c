/* 	PROBLEMA DAS 'N' RAINHAS - CONTINUAÇÃO
	
	+---+---+---+---+---+	+---+	^	RELAÇÃO INVARIANTE
  1 | Q |   |   |   |   |  1| 1 |	|	Até a linha i-1, todas as rai-
	+---+---+---+---+---+	+---+	|	nhas estão em posições válidas
  2 |   |   |   |   |   |  2| 3 |	|	(até s[1...i-1] é sol. possível)
	+---+---+---+---+---+	+---+		
  3 |   |   |   |   |   |  3|   |	<-- Estamos, agora, procurando a 
	+---+---+---+---+---+	+---+		linha 'i' para conseguir um
  4 |   |   |   |   |   |  4|   |		caminho válido.
	+---+---+---+---+---+	+---+	
  5 |   |   |   |   |   |  5|   |	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	+---+---+---+---+---+	+---+	O problema acima é análogo a procu-
	  1   2   3   4   5				rar todos os caminhos possíveis de 
									um labirinto. O 'backtracking' usado
									é um instrumento muito interessante,
									e para este problema, na verdade,
									não estamos trabalhando com uma ma-
									triz, mas sim com uma linha que re-
									presenta a posição da rainha na CO-
									LUNA para certa LINHA.
*/

#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0


int solucaoParcial(int i, int *s);
/*	devolve TRUE se s[1..i] é soluçãi viável, caso contrário
	devolve FALSE. */
	

void nRainhas(int n)
{
	int i;	/*linha*/
	int j;	/*coluna*/
	int *s;	/*fila*/
	int nSolucoes = 0;
	s = mallocSafe((n+1)*sizeof(int));
	/* NÃO usaremos o índice 0, mas começaremos com '1' */
	
	i = j = 1;
	
	while(i > 0) /* Até o backtrack voltar até o '0', que significa
					que ele percorreu todas as possibilidades */
	{
		int achouPos = FALSE;
		while(j <= n+1  && achouPos == FALSE)
			/* 	Enquanto não chegamos ao final do 'tabuleiro' e não
				achamos uma posição válida, realizamos a ação */
		{
			s[i] = j;
			if(solucaoParcial(i, s) == TRUE)
				achouPos = TRUE;
			/* 	Se a solução parcial for válida, achamos a posição */
			else j += 1;
			/*	Caso não conseguimos ainda uma posição válida, avan-
				çamos para a coluna */
		}
		
		if(j <= n) /*AVANÇA*/
		{
			i += 1;
			j = 1;
			if(i == n+1)
			{
				/*achou solução*/
				nSolucoes++;
				imprimaTabuleiro(n, s);
			}
			j = s[--i] + 1; 	/*i -= 1; j = s[i];*/
		}
		else /*BACKTRACK - VOLTA*/
		{
			i -= 1; s[i] + 1;
			/* Fomos até o final do caminho, e aí voltamos */
		}
		printf("n-Solucoes %d\n", nSolucoes);
	}
	free(s); /* Libera a pilha */
}

int solucaoParcial(int i, int *s)
{
	/*	Se duas rainhas estão nas posições (i, j) e (p, q) então elas
		estão na mesma diagonal se:
						  j-1 = p-q OU i+j = p+q

		+---+---+---+---+---+ 		|		+---+---+---+---+---+ 6
	  1 | \ | \ | \ | \ | \ | -5	|	  1 |   |   |   |   | / | 
    	+---+---+---+---+---+ 		|		+---+---+---+---+---+ 5
      2 |   | \ | \ | \ | \ | -4	|	  2 |   |   |   | / | / | 
    	+---+---+---+---+---+ 		|		+---+---+---+---+---+ 4
      3 |   |   | \ | \ | \ | -3	|	  3 |   |   | / | / | / | 
    	+---+---+---+---+---+ 		|		+---+---+---+---+---+ 3
      4 |   |   |   | \ | \ | -2	|	  4 |   | / | / | / | / | 
    	+---+---+---+---+---+ 		|		+---+---+---+---+---+ 2
      5 |   |   |   |   | \ | -1	|	  5 | / | / | / | / | / |  
    	+---+---+---+---+---+ 		|		+---+---+---+---+---+ ^
    	  1   2   3   4   5	   0	|		  1   2   3   4   5	  |	
							   ^	|							  |
							   |	|							  |
	Os elementos estão numa mesma	|	Os elementos estão numa mesma
	diagonal (com sentido inferior	|	diagonal (com sentido superios
	direito) se a SUBTRAÇÃO do va-	|	direito) se a SOMA do valor da
	lor da linha menos a da colu-	|	linha com a coluna de uma cons-
	na der uma constante. (i-j)		|	tante (i+j)
	*/
	
	int j = s[i];
	int k;
	for(k = 0; k < i; k++)
	{
		int p = k;
		int q = s[k];
		if(j == q || (j-i == q-p) || (i+j == p+q)) return FALSE;
		/*	  ^			   ^			   ^
			  |			   |			   |-- Está na diagonal anti-
			  |			   |				   principal da rainha
			  |			   |-- Está na diagonal principal com centro
			  |			       na rainha;
			  |-- Está na mesma posição da rainha anterior. */
		return TRUE;
	}
}
