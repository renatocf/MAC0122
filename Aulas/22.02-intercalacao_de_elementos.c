/*	INTERCALAÇÃO
	
	PROBLEMA: Dados v[p...q-1] e v[q...r-1] crescentes, rearranjar
	v[p...r-1] de modo que fique em ordem crescente.
	
	p								q							   r-1
	|	|	|	|	|	|	|	|	|	|	|	|	|	|	|	|	|
	 |-----------------------------| |-----------------------------|
	
	Usaremos uma maneira de fazer a intercalação usando um vetor au-
	xiliar 'w', que terá r-1 elementos. Ele será inicializado com os
	mesmos valores de p...q-1 como no vetor original. Porém, copiando
	a parte de q...r-1 ao CONTRÁRIO.
	
	A vantagem disso é que, em vez da versão tradicional, em que preci-
	saríamos fazer 'ifs' para observar se o vetor acabou a cada itera-
	ção, precisaremos apenas comparar os valores iniciais de cada tre-
	cho de 'v'. Com o trecho q...r-1 invertido, os batedores que per-
	correrão o vetor NÃO terão risco de sair, pois irão para o meio.
*/

void intercala(int p, int q, int r, int v[])
{
			/* auxiliar para percorrer o vetor w[] */
	int i, j, k, *w; /* vetor auxiliar */
	w = mallocSafe( (r-p) * sizeof(int));
				/*  ^^^^^-- Tamanho do trecho de vetor */
	for(i = 0, k = p; k < q; i++, k++)
		w[i] = v[k];
		 /* ^^^^^-- j é a última posição de 'w': ela é sempre -1*/
	for(j = r-p-1; k < r; j--, k++)
		w[j] = v[k];
	
	/*  	   ^^^^^-- Início do vetor */
	i = 0; j = r-p-1;
	for(k = p; k < r; k++)
		if(w[i] < w[j])
			v[k] = w[i++];
		else v[k] = w[j--];
	
	/* 	Vamos percorrendo o vetor, sendo que comparamos os menores ele-
		mentos e vamos comparando cada um deles. */
	
	free(w);
}

/* 	COMPLEXIDADE DO ALGORITMO
	
	A parte de copiar os elementos para 'w' roda 'n' vezes e faz 'n'
	atribuições. (n = r-p elementos)
	
	A parte de recopiar os elementos, agora ordenadamente, passa 'n'
	vezes em 'w', fazendo uma comparação e uma atribuição em cada uma
	delas.
	
	Por isso, o algoritmo tem complexidade linear - ele é O(n). */
