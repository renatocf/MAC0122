#include<stdio.h>
#define MAX 100

long binomial_i(int n, int k);

int main(void)
{
	int n, k;
	printf("Número: ");
	scanf("%d", &n);
	printf("Número: ");
	scanf("%d", &k);
	binomial_i(n, k);
}

long binomial_i(int n, int k)
{
	int i, j;
	long bin[MAX][MAX];
	for(j=1; j<=k; j++) bin[0][k] = 0;
	for(i=0; i<=n; i++) bin[i][0] = 1;
	for(i=1; i<=n; i++)
		for(j=1; j<=k; j++)
			bin[i][j]=bin[i-1][j-1]+bin[i-1][j];
	return bin[n][k];
}

/* Diferença entre os algoritmos de cálculo de binomial:
	- a versão implementada baseada apenas na forma geral de binomial
	não tem memória. Ela não é muito rápida, pois cada vez que precisa
	calcular certo binomial, precisa fazê-lo várias vezes. É um excesso
	de cálculos que demora muito tempo.
	- a versão baseada na iteratividade possui a memória. A iteratividade,
	ao contrário da recursão, faz o cálculo de tudo que é necessário. Ape-
	sar de ter a limitação da memória, isso aumenta muito a velocidade,
	pois uma vez calculado, é necessário apenas acessar (e não recalcular)
	o dado que precisamos acessar.
	  A iteratividade cria uma espécie de tabela que tem, no canto inferior
	direito, a resposta.
	- a primeira versão (implementada recursivamente) é mais inteligente, 
	pois não calcula valores como os depois da diagonal principal da tabe-
	la criada pela versão iterativa. Também se estiver nas bases (formato
	de combinação C(n, 0) ou C(n, n)) devolve 1. Isso diminui o número de
	cálculos (melhor que a outra versão iterativa). Porém, o tempo conti-
	nua a ser muito grande.
