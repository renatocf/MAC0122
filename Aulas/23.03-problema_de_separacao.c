/*	PROBLEMA DE SEPARAÇÃO
	
	PROBLEMA: Rearranjar um dado vetor v[p..r] e devolver um índice
	'q' tais que:
		v[p..q-1] <= v[q] < v[q+1..r]
					|	|
	menor ou igual a 	 maior ou igual a 
	todos os elementos	 todos os elementos
	antes dele			 depois dele
	
	 p							 q				r
	|%%|<= <= <= <= <= <= <= <= |$$| > > > > > |%%|
*/

/*	RELAÇÃO INVARIANTE
	
	No início de cada iteração vale que:
	v[0..i] <= x <= v[i+1..j-1]
*/

/*	SIMULAÇÃO
	
	i   j                              x <-- nosso pivô
	v | 99 | 33 | 55 | 77 | 11 | 22 | 44 |		Quando o número é maior
												que o pivô, não fazemos
												nada. Só atualizamos 'j'
	i		 j						   x
	v | 99 | 33 | 55 | 77 | 11 | 22 | 44 |		Quando o número é menor
												que o pivô, trocamos ele
												pelo elemento da posição
												i+1. Todos antes de 'i' 
												serão menores. E entre
												'j' e 'i' são maiores.
												Atualizamos, então, 'j'
		i	      j                    x		
	v | 33 | 99 | 55 | 77 | 11 | 22 | 44 |		
												
		i	           j               x		
	v | 33 | 99 | 55 | 77 | 11 | 22 | 44 |		
												
		i	                j          x		
	v | 33 | 99 | 55 | 77 | 11 | 22 | 44 |		
												
		     i	                 j     x		
	v | 33 | 11 | 55 | 77 | 99 | 22 | 44 |		
											
		          i	                  jx		
	v | 33 | 11 | 22 | 77 | 99 | 55 | 44 |		No último elemento, aca-
												bamos colocando o pró-
												prio elemento na posi-
												ção 'i'.
												
		          	   i                    j	         
	v | 33 | 11 | 22 | 44 | 99 | 55 | 77 |		No final, acabamos quan-
												do 'j' sai do vetor. 
*/

int separa(int p, int r, int v[])
{
	int i = p-1, x = v[r], j, t;
	for(j = p; j <= r; j++)
		if(v[j] <= x)
		{
			i = i+1;
			t = v[i]; v[i] = v[j]; v[j] = t;
		}
	return i;
}

/* 	Este algoritmo de separação é de onde vem o Quicksort. */
