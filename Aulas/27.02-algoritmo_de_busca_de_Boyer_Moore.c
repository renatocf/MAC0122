/*	A ideia é que possamos fazer pulos maiores ao buscar a palavra.
	Nossa ideia, para esta situação, é fazermos com que quando acharmos
	um caractere que não esteja na palavra, pulemos o caracter.
	
	Ex:
	
	as andorinhas andam andando alto			T
	anDando								} bateu uma errada
	       | 							} não existe na palavra
	        andandO						} bateu uma errada
	           andandO 					} bateu uma errada
	                  | 				} não existe na palavra
	                   andandO 			} bateu uma errada
	                    andando 		(match)
	                           | 		} não existe na palavra
	                            anda... } SAIU do vetor
	
	IDEIA: Calcular um deslocamento de modo que T[k+1] fique emparelhado
	com a última Ocorrência do caractere T[k+1] em P.
	
	Faremos, para auxiliar, uma TABELA:
	Colocaremos em cada casela a última posição de ocorrência da letra
	na palavra:
	
		  0        'a' 'b' 'c' 'd'  ...   ...  'n' 'o' 'p'  ...   255
	ult	| 0 | ... | 4 | 0 | 0 | 6 | ... | ... | 5 | 7 | 0 | ... | ... |
					^							^
					|							| última ocorrência na
					|							| 5ª posição
					| última ocorrência na 4ª posição
	
	Para ter uma tabela com número positivos, usaremos o 'unsigned'
	char, pois ai as posições da Tabela ASCII serão de 0 a 255, em vez
	do char normal (que tem negativos).
	
	No algoritmo, faremos um pré-processamento:
*/

int BoyerMoore(unsigned char P[], int m,
			   unsigned char T[], int n)
	/*	Utilizaremos uma HEURÍSTICA, para tentar melhorar na maioria dos
	 *	casos */
{
		int k, r, ocorrs;
		int ult[256]; /* Tabela para os que apareceram */
	
		/* Pré-processamento */
/*1*/	for(i = 0; i <= 255; i++) ult[i] = 0;
/*2*/	for(i = 1; i <= m; i++) ult[P[i]] = i;

/*3*/	ocorrs = 0; k = m;
/*4*/	while( k <= m)
		{
/*5*/		r = 0;
/*6*/		while(r < m && P[m-r] == T[k-r]) r++;
/*7*/		if(r == m) ocorrs++;

/*8*/		if(k == n) k++;
/*9*/		else k += 1 + m - ult[T[k+1]]; /*heuristica*/
		}
/*10*/	return ocorrs;
}

/*	CONSUMO DE TEMPO:
	No melhor caso, o programa é O(n/m)
	No pior caso, é O(n²) - como o trivial */
