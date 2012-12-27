/* 	LISTAS
	
	Quando criamos uma lista, podemos relizar várias ações. Dentre elas,
	podemos REMOVER elementos. Para tanto, precisamos saber se o elemento
	ESTÁ na lista, para depois removê-lo e, ai, ARRUMAR a lista.
	
	Façamos, inicialmente, as funções de busca (versão iterativa e recur-
	siva):
*/
						/* equivalente a int v[] */
int busca_i(int x, int n, int *v)
	/* 	O aumento de complexidade dessa função (consumo de tempo) é da 
		ordem de 'n' iterações. Assim, essa função tem complexidade O(n).*/
{
	int k;
	k = n-1; /* A busca será do final para o começo */
	while(k >= 0 && v[k] != x)
		k--;
	return k
}

int busca_r(int x, int n, int *v)
{
	if(n==0) return -1;
	if(v[n-1]==x) return n-1;
	return busca_r(x,n-1,v);
}

/* Criemos, agora, a função para REMOVER e REORGANIZAR o vetor */
int remove(int k, int n, int *v)
	/*	No pior dos casos, temos de fazer 'n' iterações para movimentar
		todos os nomes para trás. Assim, a ordem de complexidade desta
		função é O(n) (linear).
	*/
{
	int i; /* É a posição a ser removida do vetor. */
	for(i = k; i < n-1; i++)
		v[i] = v[i+1];	/* 	Vamos substituindo da esquerda para 
							a direita */
	
	return n-1;
}
