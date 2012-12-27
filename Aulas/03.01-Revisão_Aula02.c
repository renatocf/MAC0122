/*	
	
TORRES DE HANOI

	|			|			|	  :		|			|			|		
   |||			|			|	  :		|			|		   |||		
  | | |			|			|	  :		|			|		  | | |		
 |  |  |		|			|	  :		|			|		 |  |  |	
|	|	|		|			|	  :		|			|		|	|	|	
	A			B			C	  :		A			B   		C		
	  (CONFIGURAÇÂO INICIAL)	  :			(CONFIGURAÇÃO FINAL)

Regras do jogo: Mudar o pino de A para C com o auxílio de B;
				Não colocar um disco maior sobre um menor;

A solução inicial foi a de usar um algoritmo recursivo que reduzia o pro-
blema para menores. Nós sabíamos (como truque), a posição do meio na mu-
dança. Por exemplo, para passar o disco maior de A para C, teríamos que 
os discos menores deveriam estar em B. O processo, então, se repete, até
que o menor problema seja mudar o disco menor de um pino para outro (e 
depois executar os movimentos).

ALGORITMO:
	Para resolver Hanoi(n,A,B,C)
						  ^ ^ ^- destino
						  | |- auxiliar
						  |- origem
	1. resolver Hanoi(n-1,A,C,B)
	2. mover disco n de A para C
	3. resolver Hanoi(n-1,B,A,C)

*/


#include<stdio.h>

void 
hanoi(int n, char origem, char auxiliar, char destino);

int main(int argc, char *argv[])
{
	int n;
	printf("Digite n:");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}

void 
hanoi(int n, char origem, char auxiliar, char destino)
{
	if(n>0) {
		hanoi(n-1, origem, destino, auxiliar);
		printf("mova o disco %d do pino %c para o pino %c\n",
			   n, origem, destino);
		hanoi(n-1, auxiliar, origem, destino);
 	}
}

/* NÚMERO DE MOVIMENTOS
	Seja T(n) o número de movimentos feitos pelo algoritmo para resover 
o problema da torre e Hanoi com n discos.

	T(0) = 0				} Relação de
	T(n) = 2*T*(n-1) + 1	} recorrência

	T(n) = 2*(2*(T(n-2) + 1) + 1
	T(n) = 2*(2*(2*T(n-3) + 1) + 1) + 1
	T(n) = 2*(2*(2*(2*T(n-4) + 1) + 1) + 1) + 1
						...
	T(n) = 2*(2*(2*(2*(2* ... (2*T(0)+1) ... + 1 ) + 1) + 1) + 1) + 1
			^^^^^^^^^^^			 ^^^---------------------------------|
			n números 2    *   T(0) = 0	--> 0						 |
			n números 2	   *   todos os 2	   2^3 + 2^2 + 2^1 + 1	 |
		No total, a soma 											 |
		resulta em:					,,,,,----------------------------|	
								   2^(n-1) + ...  + 2^3 + 2^2 + 2^1 + 1
		(para todos os números 1 nas multiplicações)
		
		A soma do total será T(n) = 2^n-1

		Para analisarmos: 
		  n  |  0  1  2  3  4  5  6
		T(n) | 00 01 03 04 15 31 63
		
	
	Voltando ao problema:
	T(64) ~= 1,84*10^19
	Digamos que os monges fazem 1 movimento por segundo:
	
	1,84*10^19s ~= 3,07*10^17 min
				   5,11*10^15 horas
				   2,13*10^14 dias
				   5,83*10^11 anos
				   583 bilhões de anos
	Idade da Terra: 4,5 bilhões de anos

	
	Um algoritmo como este, da Torre de Hanoi, tem tempo da forma 2^n-1.
	Este tem um tempo EXPONENCIAL - e no caso, dobra a cara vez que au-
	mentamos a entrada.
/*
