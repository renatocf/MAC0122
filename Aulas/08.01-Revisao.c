/* 	LISTAS:
	
	São um conjunto de elementos ordenados.
	Podemos realizar várias ações nela:
	- Uma delas é REMOVER elementos dela. Para remover um elemento, devemos 
	retirá-lo e colocar todos os elementos abaixo para cima. No pior dos
	casos, deveremos fazer o deslocamento de 'n' elementos (a complexidade
	do algoritmo é de ordem 'n' - O(n) ); 
	- Podemos, também, ADICIONAR elementos nela. No pior dos casos, temos
	que mover 'n' elementos para frente no vetor. Assim, a complexidade
	deste algoritmo é 'n'.
		Temos a seeguinte função para adicionar elementos numa lista de
		númmeros inteiros:
*/

int insere(int k, int x, int n, int v[])
{
	int i;					/* |  |  |  | ...  |  | ... |   |   |		*/
	for(i = n; i > k; i--)	/*  00 01 02        kk       n-1  n			*/
		v[i] = v[i-1];		/*					-->      --> -->		*/
	v[k] = x;				/*					^-- Inserimos 'x' aqui	*/
}							/*						se esta é a última	*/
							/*						posição.			*/

/* 	Este tipo de algoritmo pode ser ineficiente, dependendo do tamanho. As
	LISTAS ENCADEADAS podem auxiliar a melhorar isso. Porém, a melhora do
	tempo acaba tendo um custo: o armazenamento, junto ao dado, da posição
	do próximo elemento que os liga. */
