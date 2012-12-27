#include<stdio.h>

long binomial_r(int n, int k);

int main(void)
{
	int n, k;
	printf("Insira: ");
	scanf("%d", &n);
	printf("Insira: ");
	scanf("%d", &k);
	binomial_r(m+n, m+k);
	
	return 0;
}

long binomial_r(int n, int k)
	/* o 'r' é para simbolizar que a chamada é recursiva */
{
	if(n<k) return 0;
	if(n==k || k==0) return 1;
	return binomial_r(n-1, k-1) + binomial_r(n-1, k);
}

/* Façamos a simulação da função:
 *-----------------------------------------------------
 * binomial_r(3,2)
 * n | k
 * 3 | 2 } n>k, n!=k, k!=0 
 *		   - nova chamada de método:
 *     |------------------------------------|
 * 	   |binomial_r(2, 1)					|
 * 	   |n | k								|
 * 	   |2 | 1 } n>k, n!=0, k!=0 			|
 *	   |		- nova chamada de método:	|
 * 	   |	|-------------------|			|
 *	   |	|binomial_r(1, 0)	|			|
 *	   |	|n | k				|			|
 *	   |	|1 | 0 } k==0		|			|
 *	   |	|		- return 1; |			|
 *	   |	|-------------------|			|
 *	   |									|
 * 	   |	|-------------------|			|
 * 	   |	|binomial_r(1, 1)	|			|
 *	   |	|	n | k			|			|
 *	   | 	|	1 | 1 } n==k	|			|
 *	   |	|		- return 1	|			|
 *	   |	|-------------------|			|
 *	   |									|
 *	   |		- retorna binomial_r(1,0)+	|
 *	   |			binomial_r(1,1) = 2		|
 *	   |------------------------------------|
 *
 *	   |------------------------------------|
 *	   |binomial(2, 2)						|
 *	   |	n | k							|
 *	   |    2 | 2 } n==k					|
 *	   |		- retorna 1; 				|
 *	   |------------------------------------|
 *
 *		- retorna binomial_r(2,1)+binomial_r(2,2) =
 *			2+1 = 3;
 *-----------------------------------------------------
 * Esse é o esquema geral da recursão para calcular 
 * binomiais: carda problema chama outros, até chegar
 * a uma base que pode ser calculada.
 */

/* Binomial recursivo
	( n )	{ 0, quando n=0 e k > 0			} BASE
	( k ) = { 1, quando n>=0 e k=0			}
			{ (n-1) + (n-1), quando n, k> 0	} RECURSÃO
			{ (k-1}	  ( k )					}

	Podemos passar, sem muitos problemas, a parte matemática para uma
	função em C (equivalente à anterior):
		
	long binomial_r(int n, int k)
	{
		if(n==0 && k>0) return 0;
		if(n>=0 &&  k==0) return 1;
		return binomial_r(n-1,k-1) + binomial_r(n-1,k);
	}

	Essa estrutura é chamada de árvorae de recursão, pois o que não está
	na base pode ser tirado a partir dela:

								(3) } soma as bases: retorna 3
								(2)
								/ \
   soma as bases: retorna 2 { (2) (2) } está na base: retorna 1
							  (1) (2)
							  / \
  está na base: retorna 1 { (1) (1) } está na base: retora 1
							(0) (1)

*/
