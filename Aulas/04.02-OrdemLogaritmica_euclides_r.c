#include<stdio.h>

int
euclides_r(int m, int n);


int main(int argc, char *argv[])
{
	int m, n;
	printf("Escreva os numeros para calcular mdc:");
	scanf("%d%d", &m, &n)
	
	euclides_r(m, n);
	return 0;
}


int
euclides_r(int m, int n)
{
	if(n == 0) return m;
	return euclides(n, m%n);
}

/* 	ALGORITMO DE EUCLIDES

	Encontremos os invariantes (afirmações para o início do algoritmo, que
	valem no início e valerão até o final):
	
	Para calcular o mdc(m,n), o algoritmo de Euclides usa a recorrência:
	mdc(m,0) = m
	mdc(m,n) =  mdc(n, m % n)
	
	CORREÇÃO
	
	Se baseia no seguinte fato:
	|-------------------------------------|
	| m,n e n,m%n têm os mesmos divisores |
	|-------------------------------------|
	
	Suponha que 'd' divide 'm' e 'n':
		* Se d|m e d|n, d|n;
		* Podemos expressar m%n = r = m - k*n.
		  É claro que d|k*n. Igualmente, d|m.
		  Como, em ambos os casos, d é divisor, então d|m%n.
		  Nos dois casos, obtemos um inteiro.
	
	Assim, o programa cumpre o que prometeu.
*/

/* CONSUMO DE TEMPO
	
	Número de chamadas recursivas:

	- Sejam:
		   originais 1ª rec   2ª rec		 última recursão 
	(m,n) = (m0,n0), (m1,n1), (m2,n2), ... , (mk,nk) = (mdc(m,n), 0)
	
	- Os valores dos parâmetros:
	
	   | n0 | n1 | n2 | n3 | n4		Os 'n' se tornam 'm' conforme a 
	   | || | || | || | || | ||		divisão vai avançando com o tempo
	m0 | m1 | m2 | m3 | m4 | m5
	n1 | n2 | n3 | n4 |

	- Temos a seguinte característica válida:
		0 <= b <= a vale:
			a%b < a/2
		Porque se b for menor que a metade:
						+-- Metade
			|-----------:-----------|	a } Podemos continuar tirando
			|---|---|---|---|---|		b } se ele for menor que a metade.
											Isso faz com que o resto seja
											sempre menor que a metade.
		Se b for maior que a metade:
						+-- Metade
			|-----------:-----------|	a } O resto já será menor que a 
			|-----------------|			b } metade
		
		Assim, a proporção vale em ambos os casos

	- Analisando as divisões possíveis, temos que:
		n0 = n
		n2 = n0%n1 < n0/2 = n/2
		n4 = n2%n3 < n2/2 < n/2²
		n6 = n4%n5 < n4/2 < n/2³
		
		Essa proporção segue o LOGARITMO N DE BASE 2 (quantas vezes preci-
		samos fazer divisões por 2 para chegarmos em 1, na forma de uma 
		fração). Isso faz com que a ORDEM desse algoritmo seja O(log_2 n).
*/

/* ORDEM DOS ALGORITMOS
	Até agora, estudamos 3 ordens de algoritmos:
	- EXPONENCIAL: para dobrar o tempo, precisamos adicionar 1 unidade na
				   entrada; O(2^n)
	- LINEAR: para dobrar o tempo, devemos dobrar o número de entradas;
			  O(n)
	- LOGARÍTMICO: para dobrar o tempo, devemos ter n² número de entradas;
*/
		no total, 2*(log_2 n) chamadas recursivas. 
