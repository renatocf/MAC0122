/* 	CURVAS DE HILBERT

	As curvas a seguir têm um certo padrão regular. O objetivo é descobrir
O objetivo é descobrir o ESQUEMA DE RECURSÃO para construir tais curvas.
			
	H1		:			H2			:	PADRÃO
			:						:	
			:	|----------|	|	:	H(i+1) é obtido pela composição
			:	|	    /\ |	|	:	de 4 H(i) de "metade do tamanho"
|-------	:	|-----| || |----|	:	(aproximado) e com a rotação apro-
|			:		  |				:	priada.
|			:		  | <--
|			:		  |				:	H2 = 4 cópias de H1
|--------	:	|-----|	|| |----|	:	H3 = 4 cópias de H2
			:	|		\/ |	|	:	
			:	|----------|	|	:	(As flechas representam conexões
										baseadas na última versão)

	PARTES DA CURVA
	
	Para ilustrar denominaremos as 4 possíveis instâncias por:
	- A1:	|---	- A2:	|----------|	| 
			|---			|	       |	|
							|-----|    |----|
								  |			 
								  | 
								  |			 
							|-----|	   |----|
							|		   |	|
							|----------|    |

	- B1:	|--|	- B2:   ------     ------
			|  |			|	 |	   |	|
							|	 |	   |	|
							|	 -------	|
							|				|
							|				|
							------	   ------
								 |	   |
								 |	   |
							-----|	   |-----

	- C1:	---|	- C2:	|     |----|----|
			---|			|     |       	|
							|-----|    |----|
								  	   |	 
								       |
								  	   |	 
							|-----|	   |----|
							|     |	     	|
							|     |----|----|
						
	- D1:	|  |	- D2:	-----|     |-----
			|--|				 |	   |	
								 |	   |	
							------     ------
							|				|
							|				|
							|    -------    |
							|	 |	   |	|
                            |	 |	   |	|
                            |----|	   |----|

	ESQUEMA RECURSIVO
	
	Podemos indicar, pod meio de flechas, a forma de desenhar
	a figura:
	
	A1: << \/ >>
	B1: ^^ >> \/
	C1: >> ^^ <<
	D1: \/ << ^^
	
	A2: D1 << A1 \/ A1 >> B1	Podemos observar que os esquemas sempre
	B2: C1 ^^ B1 >> B1 \/ A1	seguem esse mesmo tipo de padrão. Isso 
	C2: D1 >> C1 ^^ C1 << A1    inclui, por exemplo, os próprios A/B/C/D
	D3: C1 \/ D1 << D1 ^^ A1	1, que teriam A/B/C/D 0 (inexistentes - 
								ou que não têm tamanho de flecha:
								
									A1: D0 << A0 \/ A0 >> B0	
									B1: C0 ^^ B0 >> B0 \/ A0	
									C1: D0 >> C0 ^^ C0 << A0
									D1: C0 \/ D0 << D0 ^^ A0

	E chegamos à forma geral:
	- A(k): D(k-1) << A(k-1) \/ A(k-1) >> B(k-1)	
	- B(k): C(k-1) ^^ B(k-1) >> B(k-1) \/ A(k-1)0	
	- C(k): D(k-1) >> C(k-1) ^^ C(k-1) << A(k-1)
	- D(k): C(k-1) \/ D(k-1) << D(k-1) ^^ A(k-1)
	
	Para desenhar os segmentos utilizamos a chamada da função.
	linha(x, y, direção, comprimento) que "move um pincel" da posição
	(x,y) em uma dada DIREÇÃO por um certo COMPRIMENTO.
	
	Para desenhar, vamos realizar o seguinte esquema: o comprimento BASE
	será dividido por 2 para cada instância que diminuímos.
*/

#include<stdio.h>
#include<stdlib.h>

void
hilbert(int k, int *x, int *y, int comprimento)

int main(int argc, char *argv[])
{
}

void
hilbert(int k, int *x, int *y, int comprimento)
{
	if(k > 0) {
		hilbert(k-1,x,y,comprimento);	
		linha(x,y,ESQUERDA,comprimento);/* Cria a linha para a esquerda */
		hilbert(k-1,x,y,comprimento);	
		linha(x,y,BAIXO,comprimento);	/* Cria a linha para baixo */
		hilbert(k-1,x,y,comprimento);	
		linha(x,y,DIREITA,comprimento); /* Cria a linha para a direita */
		hilbert(k-1,x,y,comprimento);	
	}
}

/* 	Esse tipo de recursão (que leva a sub-recursões com casos diferentes)
	é chamada de RECURSÃO INDIRETA. */
