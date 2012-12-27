/*
FATORIAL

n! = n*(n-1)*(n-2)*...*1
	   |_______________|
			 (n-1)!

n! -|1, se n=0
    |n*(n-1)!, se n>0
*/


/* ESQUELETO DE PROGRAMAS EM C: */


/* Para incluir bibliotecas (as bibliotecas são interfaces, usadas para 
separar e esconder o código que implementou uma certa função): */
#include<stdio.h>


/* protótipo das funções (declaramos as funções que usaremos): */
int fatorial(int n);


/* main */
int main(int argc, char *argv[])
	/* Os argumentos acima são obrigatórios */
{
	int n;											/* Declaração de 	*/
													/* variáveis		*/
	/********************************************************************/
	printf("Digite n: ");							/*					*/
	scanf("%d", &n);								/* Comandos			*/
	printf("fatorial(%d)=%d\n", n, fatorial(n));	/*					*/
	return 0;										/*					*/
}


/* Implementação das funções */
int fatorial(long n)
	/* O long, para computadores de 32 bits, não se diferencia do int. Nos
	   de 64 bits, temos que os 'int' têm 32 bits e os 'long' têm 64 bits
	   de memória. */							
{
	if(n==0) return 1;
	return n*fatorial(n-1);
}


/* Esqueleto geral de programas em C:
	
	Declaração de bibliotecas;
	Declaração de protótipo de funções;
	Main;
	Implementação de funções.
*/
