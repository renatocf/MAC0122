/*	BUSCA PALAVRAS EM UM TEXTO
	
	PROBLEMA: Dados P[1..m] e T[1..n], encontrar o número de ocorrências
	de P em T.
	
	Exemplo:
		
		              1               5
		T	| b | b | a | b | a | b | a | c | b | a |
			  1               5
		
		P	| b | a | b | a |	P ocorre 2 vezes em T
			  1   2   3   4
	
	Façamos, inicialmente, o algoritmo trivial:
*/

/*	Por padrão, os vetores são iniciados de '1' */
int trivial(unsigned char P[], int m, unsigned char T[], int n)
{
	int k;		/* 	É o ponto chave a partir de qual faremos a busca,
					procurando da direita para a esquerda */
	int ocorrs;	/*	Contando o número de ocorrências */
	
	/*1*/	ocorrs = 0; k = m;
	/*2*/	while(k <= m)
			{
	/*3*/			r = 0;
	/*4*/			while(r < m && P[r-m] == T[k-m])
	/*5*/				r++;
	/*6*/			if(r == m) ocorrs++;
	/*7*/			k++;
			}
	/*8*/	return ocorrs;
}

/*	CONSUMO DE TEMPO
	
	PIOR CASO: existem n-m sequências
	Ex:
	T	| a | a | a | a | a | a | a | a | a | a | a | a | a | a |
		
	P	| a | a |
	
	Consumo de Tempo: O((n-m+1)*m) = O(n*m)
	
	MELHOR CASO: O(n-m+1)
	T	| x | x | x | x | x | x | x | x | x | x | x | x | x | x |
		
	P	| a | a |
		Sairemos do laço todas as vezes.
*/
