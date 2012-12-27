/* PROBLEMA: Dados dois números infinitos não negativos 'm' e 'n', deter-
minar mdc(m, n) */

#include<stdio.h>

int
mdc(int m, int n);


int main(int argc, char *argv[])
{
	int m, n;
	printf("Escreva os numeros para calcular mdc:");
	scanf("%d%d", &m, &n)
	
	mdc(m, n);
	return 0;
}


int
mdc(int m, int n)
{
	int d = m; /* d = min(m,n) */
	while(/*1*/ m % d != 0 || n % d != 0) 
		/*2*/ d--; /* d = d - 1 */
	/*3*/ 
	return d;
}

/* INVARIANTES E CORREÇÃO:

	Correção: a função faz (correctness) o que promete.
	(Meios para provar que o programa funciona/faz corretamente o que 
	promete)
	
	Relações invariantes para a função MDC:
	(relações que vaem sempre para o problema)
		- Em /1/ vale que:
			(i0) 1 <= d <= min(m,n)
				- não existe numero maior que o menor número da dupla (m,n)
			(i1) m % t != 0 ou n % t != 0 para todo t > d
		- Em /2/ vale que:
			(i2) m % d != 0 ou n % d != 0
		- É evidente que em /3/ vale que:
			(i3) m % d = 0 e n % d = 0 como (i1) em /1/ também vale em /3/.
				 Assim, nunhum número maior que o valor de 'd' retornado 
				 divide m e n. Portanto, a função faz o que promete.
	
	
		Esse algoritmo parece um pouco com uma iteração: no início, temos
	uma afirmação (base) - nunca o número é maior que min(m,n) e nunca o 
	número será se não dividir ambos - e uma ação repetitiva - vamos dimi-
	nuindo o número testado até encontrarmos algum que serve a condição 
	que desejávamos. Isso demonstra que se o programa para, ele faz o que
	promete. Falta mostras SE ele para. E isso realmente acontece: no pior
	dos casos, 1 dividirá ambos os números.
	
	O uso das relações invariantes - condições no início que valem sempre
	- permite mostrar como uma 'demonstração' do algoritmo: no início, ela
	propõe algumas afirmações (o número não será maior que o mínimo de 'm' 
	e 'n' e o valor correto deverá devolver um número que divide 'm' e 
	'n'). Estas características são repetidas no meio do algoritmo (/2/) e
	o retorno segue estas poposições (em /3/). Desse modo, provamos que o
	programa realiza o que prometeu.
*/

/* CONSUMO DE TEMPO
	
	O consumo de tempo é PROPORCIONAL a número de execuções do 'while', a
	qual é igual ao número de execuções do comando "d--;"
	
	|---------------------------------------------------------|
	| No pior caso, o número de execuções de d-- é min(m,n)-1 |
	|---------------------------------------------------------|
	
	|----------------------------------| Este O grande representa a ORDEM
	| O consumo de tempo é O(min(m,n)) | de tempo do algoritmo
	|----------------------------------| 
*/
