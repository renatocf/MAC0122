#include<stdio.h>
#include<stdlib.h>
#include "mallocSafe.h"
#include "queue.h"

int main(int argc, char **argv)
{
	return 0;
}

int *distancias(int n, int **A, int c)
	/*	Recebe o número de cidades,
		uma matriz com os caminhos e
		a cidade a ser analisada (c).
		Devolve um vetor com as dis-
		tâncias até todas as cidades */
{
	int *d = mallocSafe(n*sizeof(int));
		/* Matriz das distâncias */
	int j;	/* contador */
	
	queueInit(n);
	/*	Criamos a fila */
	for(j = 0; j < n; j++)
		d[j] = n;
	/* 	Inicializa a matriz das distân-
		cias com 'n' - o número de ci-
		dades, que representa a dis-
		tância "infinita" */
	d[c] = 0;
	/* 	A cidade a ser analisada tem 
		distância dela a ela mesma 
		com 0. */
	queuePut(c);
	/* 	O primeiro elemento da fila,
		que será analisada, é a ci-
		dade passada como parâmetro. */
	 
	while(!queueEmpty())
		/*	Este laço é feito no MÁXIMO
			'n' vezes, pois cada cidade 
			é colocada na fila, para ter
			as distâncias analisadas, uma
			vez apenas */
	{
		int i = queueGet();
		/* 	Pegamos o primeiro elemento 
			da fila */
		for(j = 0; j < n; j++)
			/* 	Executamos este laço 'n' 
				vezes no MÁXIMO, pois 
				este é o número d checa-
				gens para os caminhos que
				faremos na matriz. */
			if(s[i][j] == 1 && d[j] == n) {
				/* 	Se já tiver sido posto,
					no passado, é porque 
					já houve um caminho mais
					curto até lá. Caso con-
					trário, se houver liga-
					ção (s[i][j] == 1) e 
					não tiver sido posto ain-
					da (d[j] == n), fazemos
					as operações abaixo */
				d[j] = d[i] + 1;
				/*	A distância da cidade
					será a distância até
					a cidade atual (d[j])
					somada de 1. */
				queuePut(j);
				/*	Se não tiver entrado
					ainda, ele é colocado
					na fila para ser ana-
					lisado posteriormen-
					te. */
			} /* fim do if */
		} /* fim do for */
	} /* fim do while */
	
	queueFree();
	/* No final, liberamos a pilha */
	
	return d;
	/* retornamos o vetor de distâncias */
}
