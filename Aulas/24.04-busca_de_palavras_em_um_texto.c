/*	BUSCA DE PALAVRAS EM UM TEXTO
	
	PROBLEMA: Dados P[1..m], T[1..n], encontrar o número de ocorrên-
	cias de P em T.
	
	T	|			|--------|				|	texto
	
	P	|--------|	palavra (sequência a ser encontrada)
*/


/*	Faremos, primeiro, o algoritmo mais trivial, que é o de buscar
	o primeiro caracter válido e ir comparando sempre os seguintes */

int trivial(unsigned char P[], int m, 
			unsigned char T[], int n)
{
/*1*/	int t, k, ocorrs = 0;

/*2*/	for(k = 1; k <= n-m+1; k++)
		{
/*3*/		r = 0;
/*4*/		while(r < m && P[1+r] == T[k+r])
/*5*/			r += 1;
/*6*/		if(r == m) ocorrs += 1;
		}
		
/*7*/	return ocorrs;
}


/*	COMPLEXIDADE DO ALGORITMO
	
	linha	|	número de execuções
	--------|------------------------
	1		| = n-m+2 // n-m+1 vezes e última, que sai do laço
	2		| = n-m+1 // toda vez que entra no laço
	3		| <= (n-m+1)*(m+1) 	// caso seja a sequência e a saída
	4		| <= (n-m+1)*m		// caso seja a sequência
	5		| = n-m+1
	6		| = 1
	--------|------------------------
	TOTAL	| <= 3*(n=m+2) + 2*(n-m+1)*(m+1) -- É o termo maior
			  = O((n-m+1)*m) = O(n*m)
	
	Em livros de análise de algoritmos mais formais, a ordem de tempo
	é classificada como O((n-m+1)*m). Porém, em nosso caso, podemos
	colocar o crescimento na forma O(n*m), pois a complexidade depende
	de um fator que envolve o tamanho do texto e da sequência.
	
	
	1 - MELHOR CASO
		A sequência não está no algoritmo:
		
		T	a a a a a a a a a a a a a a a
		P	x a a a a 						} 
		P	  x a a a a						} 
		P	    x a a a a 					} 
		P		  x a a a a 				} Executaremos 'n' 
		P			x a a a a				} vezes, mas nunca 
		P			  x a a a a				} entra no while.
		P 				x a a a a			} 
		P				  x a a a a			} 
		P					x a a a a		} 
		P					  x a a a a		} 
		P						x a a a a	} 
	
	2 - PIOR CASO
		Existem sequências sempre
		T	a a a a a a a a a a a a a a a
        P	a a a a a 					 
        P	  a a a a a					 
        P	    a a a a a 				 
        P		  a a a a a 			 
        P			a a a a a			 
        P			  a a a a a			 
        P 				a a a a a		 
        P				  a a a a a		 
        P					a a a a a	 
        P					  a a a a a	 
        P						a a a a a
