/*	Usando os princípios de intercalação vistos anteriormente, podemos
	utilizar uma RECURSÃO e o princípio de DIVIDIR-E-CONQUISTAR para 
	podermos pegar partes menores do nosso problema (o vetor) para
	ordená-lo. Então, o que faremos é pegar um vetor de 'n' elementos
	e dividí-lo em partes cada vez MENORES, até chegarmos a 1 elemento
	(pois 1 elemento sempre está ordenado). Aí, vamos intervalando.
	
	Este algoritmo é chamado MERGE SORT:
*/

void mergeSort(int p, int r, int v[])
{
	if(p < r-1)
	/* 	Temos 'n' elementos, sendo n = r-p (o nº de elementos do trecho).
		Preciamos que n > 1, ou 1 < n, ou 1 < r-p, ou p < r-1. */
	{
		q = (r-p)/2;
		mergeSort(p, q, v); /* Lado esquerdo */
		mergeSort(q, r, v); /* Lado direito */
		intercala(p, q, r, v); /* Intercalação */
	}
}
