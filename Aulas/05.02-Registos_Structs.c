/* 	REGISTROS E STRUCTS
	
	Um registro e uma coleção de várias variáveis possivelmente de tipos
	diferentes (diferente de arrays, no qual só se armazenam variáveis
	do mesmo tipo).
*/

/* 1º M O D O */

struct {		/* A struct pode ser considerada como o "tipo"		*/
	int dia;	/* da variável. Nesse caso, aniversario foi criado	*/
	int mes;	/* com todos estes inteiros criados para ela.		*/
	int ano;	/*	aniversario		dia |		|					*/
} aniversario;	/*					mes |		|					*/
				/*					ano |		|					*/


/* 2º M O D O
 	Podemos também declarar essa mesma variável (aniversário) de um jeito
	diferente (em muitas ou em apenas uma linha) */

struct data { /* <-- É um "nome" para esse tipo de variável */
	int dia, mes, ano;
}; /* <-- Este ponto-e-vírgula sempre deve estar presente */

/* 	E para criar variáveis: */
struct data aniversario;
struct data casamento;


/* 3º M O D O
	Podemos criar uma maneira diferente, SEM ter de colocar o nome 
	"struct" antes da criação das variáveis structs */
typedef struct data Data;

/* E para criar as variáveis: */
Data aniversario, casamento;

/* E também vale para arrays: */
Data aniversario[100];
	/* Estamos criando um vetor chamado "aniversario" com 100 espaços para
	   guardar variáveis do tipo "Data". O esquema da alocação delas fica:
		|---|---|---|---|---|---|---|---|---|---|---| 	  ---|---|
		|	|	|	|	|	|	|	|	|	|	|	| ... 	 |	 |
		|---|---|---|---|---|---|---|---|---|---|---| 	  ---|---|
		|	|	|	|	|	|	|	|	|	|	|	| ... 	 |	 |
		|---|---|---|---|---|---|---|---|---|---|---| 	  ---|---|
		|	|	|	|	|	|	|	|	|	|	|	| ... 	 |	 |
		|---|---|---|---|---|---|---|---|---|---|---| 	  ---|---|
		^^^^^
		  |--- Cada um equivale a um dos structs
*/


/* 	PARA ACESSAR ALGUM VALOR E DECLARAR: */
casamento.dia = 12;
aniversario[2].dia = 27; /* <-- Estamos colocando na posiçao 2 do vetor 
							aniversario dentro do inteiro em DIA. Para
							imprimí-los, usamos os mesmos esquemas de
							%s/d/c/i/f */
