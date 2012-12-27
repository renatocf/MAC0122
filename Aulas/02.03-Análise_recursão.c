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
	if(n<k) return 0;					/* linha 1 */
	if(n==k || k==0) return 1;			/* linha 2 */
	return binomial_r(n-1, k-1) 		/* linha 3 */
		+ binomial_r(n-1, k);			/* linha 4 */
}

/* Análise do algoritomo 
Quantas chamadas recursivas faz aproximadamente a função?
Aproximadamente o DOBRO do número de adições que aparecem.
Seja T(n,k) o número de adições presentes no programa para n tomado k a k
Vamos analisar o número de adições para cada caso:

T(n, k) = { 0, se n<k
		  { 0, n >= k
		  { T(n-1,k)+T(n-1,k-1)+1, se n,k > 0
	
	linha |
	1	  | 0
	2	  | 0
	3	  | T(n-1,k)
	4	  | T(n-1,k-1)+1
	------|----------------------
	TOTAL | T(n-1,k)+T(n-1,k-1)+1

	Ao fazermos uma tabela com adições e a compararmos com a binomial, te-
	mos uma noção de quantas adições são feitas:
	T(n, k) = (n) - 1
			  (k)
	
	Conforme k fica próximo a n/2, temos um tempo muito grande.
	
	Para n/2, podemos estimar o número de adições como:
		n!	  n*(n-1)*(n-2)*............*(n/2)!
	  ----	= --------------------------------
	  n! n!	  n/1 * (n/2-1)*(n/2-2)*....*(n/2)!
	  -  -	   |       |	   |
	  2  2 	   |       |	   |
			   2  *   ~2   *  ~2
	A complexidade do programa é de aproximadamente 2^(n/2). Isso faz o 
	programa ser de complexidade EXPONENCIAL (aumenta exponencialmente 
	conforme o tempo)
