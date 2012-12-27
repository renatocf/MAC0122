/*

PF (Feofiloff) 2.1, 2.2, 2.3 e 2.4

TORRES DE HANOI

	Pino
	|			|			|		
   |||			|			|		
  | | |			|			|		
 |  |  |		|			|		
|	|	|		|			|		
	A			B			C		

Desejamos transferir 'n' discos do pino A para o pino C usando o pino B
como auxiliar, respeitando as regras:
	- podemos mover apenas um disco por vez;
	- nunca um disco de diâmetro maior poderá ser colocado sobre um de
	  diâmetro menor.
								|	 } Esta situação
							 |	|  | } é errada
							  |	| |  } 

	Nós podemos não saber qual o movimento inicial, mas sabemos qual uma 
das configurações no meio do problema: colocar todos os discos menores no 
pino B, para depois movê-lo.
	Se tivermos 4 discos, sabemos que os 3 discos menores devem estar em
B, para depois movermos o disco maior. Porém, nosso novo problema é pare-
cido com o anterior: mover 3 pinos de A para B usando C como auxiliar.
Para tanto, devemos ter os 2 discos menores em C.


IDEIA: configuração do "meio"

	|			|			|		
    |			|			|		
    | 			|			|		
    |  		  |	| |			|		
|	|	|	 |	|  |		|		
	A			B			C		

		  ´nº de discos
		  |  ´origem
		  |  |  ´auxiliar
		  |  |  |  ´destino
	Hanoi(n, A, B, C) = problema das Torres de Hanoi, com "n" discos, "mo-
ver do A" para o C usando o B com auxiliar.


RESOLUÇÃO: Para resolver Hanoi(n, A, B, C) basta:
1 - resolver Hanoi(n-1, A, C, B)
2 - novo disco 'n' de A para C
3 - resolver Hanoi(n-1, B, A, C)

Quando para? Sugestão: Hanoi (0,...,...,...)


FUNÇÃO: Vamos construir, agora, uma função em C para resolver este pro-
blema:
*/

#include<stdio.h>

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


int main(int argc, char *argv[])
{
	int n;
	printf("Digite n:");
	scanf("%d", &n);
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
