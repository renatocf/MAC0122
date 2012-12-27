/* 	ORDENAÇÃO
	
	v[0...n-1] é crescente se v[0] <= v[1] <= ... <= v[n-1]
	
	PROBLEMA: Rearranjar os elementos de um vetor v[0...n-1] tal
	que ele fique CRESCENTE.
	
	ENTRADA:
	---------------
	  01   02   03   04   05   06   07   08   09   10   11
	| 33 | 55 | 33 | 44 | 33 | 22 | 11 | 99 | 22 | 55 | 77 |
	  |         |         |_____
	  |         |__________	   |
	  |_______________	  |	   |	O algoritmo mantém a ordem
					 |	  |	   |	relativa quando os elementos
	SAÍDA:			 |	  |	   |	são IGUAIS
	---------------	 ^	  ^	   ^
	  01   02   03   04   05   06   07   08   09   10   11	
	| 11 | 22 | 22 | 33 | 33 | 33 | 44 | 55 | 55 | 77 | 99 |
	
	
	O algoritmo é ESTÁVEL.
	O algoritmo de ordenação é estável se mantém a ordem relativa dos
	elementos de mesmo valor.
	
	\%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\
	
	Os algoritmos de ordenação são úteis pelas ideias que eles apre-
	sentam em sua implementação.
	
	Usaremos muito relações invariantes também. A principal relação 
	invariante que valerá para os algoritmos de ordenação que estu-
	daremos será:
	
	"A cada iteração v[0...n-1] é uma permutação do vetor original"
*/
