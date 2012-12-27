/*	CONSTRUÇÃO DE UM HEAP
	
	Desejamos, dado uma árvore que não é um heap, criar heaps:
		
				(	)				|	Tendo dois max-heap, é bem
				/	\				|	simples construir, a par-
			   /	 \				|	tir deles, um max-heap, uti-
			  /		  \				|	lizando, para isso, a função
			 /		   \			|	'peneira' criada anterior-
		(	)			(	)		|	mente. Se analisarmos a estru-
		/%%%\			/%%%\		|	tura da árvore, podemos ver 
	   /%%%%%\		   /%%%%%\		|	que as folhas são max-heap 
	  /-------\		  /-------\		|	(já que não têm filhos).
	  
	O algoritmo fica:
*/

int constroiHeap(int i, int m, int v[])
{
		/*	|-- o primeiro que não é heap, a partir da última
			|	folha (que é um heap). Vamos construindo os heaps
			|	até o elemento '1', que significará que é um max 
			|	heap */
	for(i = m/2; i >= 1; i--)
		peneira(i, m, v);
}

/*	CONSUMO DE TEMPO
	
	De acordo com a nossa análise (mais grosseira), o constroiHeap
	é m*lg m.
	Porém, com uma análise mais precisa, vemos que a construção é
	O(lg m), pois o peneira é (lg m/m) e este e m.
*/
