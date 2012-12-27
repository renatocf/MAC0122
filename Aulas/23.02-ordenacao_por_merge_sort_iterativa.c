/*	Usaremos, novamente, a função intercala(p, q, r, v[]) */
/*	Consideremos um exemplo para intuir o algoritmo:
	
		[ 26 |  5 | 77 |  1 | 11 | 61 | 59 | 15 | 19 | 48 ]
	
	Ao contrário do outro elemento, vamos realizar uma ação diferente:
	Em vez de tratar do todo até as partes, faremos tratando o vetor
	como algo pequeno e, depois, iremos aumentando.
	
	[ 26 ][  5 ][ 77 ][  1 ][ 11 ][ 61 ][ 59 ][ 15 ][ 19 ][ 48 ]
		[  5  26 ][  1  77 ][ 11  61 ][ 15  59 ][ 19  48 ]
		  [  1   5   26  77 ][ 11  15  59   61][ 19  48 ]
		   [  1   5   11  15  26  59  61  77 ][ 19  48 ]
			[  1   5   11  15  19  26  48  59  61  77 ]
*/

void mergeSort(int n, int v[])
{
	int b, p, q, r;
	b = 1; 
		/* 	Utilizaremos 'b' para o tamanho dos blocos que serão 
			chamados */
	while(/*inv*/ b < n)
		/* 	Os blocos poderão ter tamanho máximo b < n */
	{
		p = 0; 
			/* 	'p' é a primeira posição do bloco atual */
		while(p+b < n)
			/* 	O bloco NÃO pode exceder o tamanho do vetor. Nesse caso,
				já ordenamos o que havia antes. */
		{
			r = p+2*b; 
				/* Para o intercala, passaremos o tamanho de 2 blocos */
			if(r > n) r = n;
				/* 	Isso garante que, quando tentarmos pegar o dobro
					de blocos, mas não houver o último bloco (isso 
					ocorre com número ímpar de blocos. Como devemos
					ordenar esse bloco, de qualquer modo, precisamos
					corrigir o 'r' para não exceder o tamanho do 
					vetor. */
			intercala(p, p+b, r, v);
				/* 	Chamamos o 'intercala', sendo p+b o meio, e 'r' a
					ponta. Ele funciona mesmo no caso do bloco sobres-
					salente no final, pois r seria igual a p+b (e se
					p+b excedesse, não teríamos entrado no primeiro
					laço). */
			p = p + 2*b;
				/*	Atualizamos a posição inicial para depois do bloco
					que fizemos atualmente, continuando a ordenação. */
	}
	b = 2*b;
		/* Dobramos o tamanho do bloco para reordenar */
}

/*	RELAÇÃO INVARIANTE
	
	No primeiro laço, sempre vale que os b-1 blocos estão ordenados. */
