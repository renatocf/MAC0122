/* PONTEIROS (Pointer)

	Um ponteiro é um tipo de variável que armazena um endereço.
	Ao declarar ponteiros, é necessário mostrar que tipo de variáveis
	eles são (para que o sistema possa identificar o início e o fim da-
	quela variável, de acordo com o tamanho padrão da variável).
	
	Para declarar ponteiros:
	int *p;		<-- endereço de um int			Usamos o operador unário
	char *q;	<-- endereço de um caracter		* (asterisco) para mostrar
												que a variável é um pon-
												teiro.
	
	Pode-se declarar um ponteiro como 'void', quando não se sabe exata-
	mente o tipo de variável que será passado (porém, no meio do progra-
	ma, é necessário dizer qual o tipo de variável).
	
	Como queremos armazenar um endereço, podemos usar o operador unário
	& com a variável comum:
	int i;
	p = &i; <-- P recebeu o endereço de 'i'
		Esse tipo de atribuição se lê "p aponta para i". Esquematicamente,
		representa-se como:
				p				i
			|-------|		|-------|
			|		| ====>	|		|
			|-------|		|-------|
	
	Se 'p' aponta para i, então *p é sinônimo de i.
	Logo, se colocarmos *p = 5, é equivalente a i = 5.

	Ex de uso para "c = a + b":	*/
	
	int *p;	/*ponteiro*/	/* p |------| q |------|	*/
	int *q; /*ponteiro*/	/*	 |		|	|	   |	*/
	int i;					/*	 |------|	|------|	*/
	int a, b;				/*	 	||		   ||		*/
							/*		\/		   \/		*/
							/*      *p		   *q		*/
							/* a |------| b	|------|	*/
	a = 10;					/*	 | 	10	|	|  05  |	*/
	b = 5;					/*	 |------|	|------|	*/
	p = &a;					
	q = &b;					
	c = *p + *q;			
	
/* 	PONTEIRO DE PONTEIRO:
	
	int *p;
	int **r; <-- r, nesse caso, é um ponteiro para um ponteiro de um in-
					teiro (ele guarda o endereço de uma variável que tem
					o endereço da variável que aponta para o inteiro). */
	int *p;
	int **r;
	
	p = &a;
	r = &p;	/* O endereço da variável ponteiro 'p' */
	c = **r + b;

	/* Esquematicamente:
		
		*r <- aponta para o conteúdo (de endereço) de r (endereço de a)
	p |-----|		r |-----|
	  |		|	<=>	  |	   	|
	  |-----|	 	  |-----|
	   /\ || 
	   || \/ 
	a |-----|  b |-----|  c |-----|
	  |		|    |     |    |     |
	  |-----|    |-----|	|-----|
		*p
		**r <- aponta para o conteúdo de endereço de *r (conteúdo de a)
*/

void troca(int i, int j) /* troca errada */
{
	int temp;
	temp = i;
	i = j;
	j = temp;
}

int main()
{
	a = 10;
	b = 20;
	troca(a, b);
	return 0;
}

/* SIMULAÇÃO:
	
	|-- MAIN ---------------------------|	A função troca, nesse caso,
	| 									|	não fez nada com os valores
	| a - conteúdo: ? (lixo)			|	de 10 e 20. Na chamada de fun-
	| b - conteúdo: ? (lixo)			|	ções, só se passam como parâ-
	| a = 10;							|	metros os VALORES e não os 
	| b = 20;							|	ENDEREÇOS das variáveis. Por
	| 									|	isso, as variaveis criadas in-
	| |-- TROCA --------------------|	|	ternamente só existem no es-
	| | 							|	|	copo da função. Por isso, ao
	| | i = 10						|	|	terminar a função, nada foi
	| | j = 20						|	|	feito realmente com 'a' e 'b'
	| | temp - conteúdo: ? (lixo)	|	|	do main, mas apenas com as
	| | temp = 10;					|	|	variáveis locais da função 
	| | i = 20;						|	|	que tinham como conteúdo có-
	| | j = temp;					|	|	pias dos valores de 'a' e 'b'.
	| |-----------------------------|	|	Para modificar 'a' e 'b' re-
	|									|	almente, precisamos ter os 
	| return 0;							|	ENDEREÇOS dessas variáveis.
	|-----------------------------------|	
*/
		
void troca(int *i, int *j) /* troca errada */
{
	int temp;
	temp = *i;
	*i = *j;
	*j = temp;
}

int main()
{
	a = 10;
	b = 20;
	troca(&a, &b);
	return 0;
}

/* TROCA CERTA

	|-- MAIN ---------------------------|	
	| 									|	Ao passar como parâmetros 
	| a - conteúdo: ? (lixo)			|	os ENDEREÇOS, a função passa
	| b - conteúdo: ? (lixo)			|	a alterar valores das variá-
	| a = 10;							|	veis armazenadas naquele lo-
	| b = 20;							|	cal, mesmo que estas variáve-
	| 									|	is sejam EXTERNAS ao escopo
	| |-- TROCA --------------------|	|	da função mostrada. 
	| | 							|	|	Dessa maneira, por meio dos
	| | temp - conteúdo: ? (lixo)	|	|	apontadores, não são i e j os
	| | i = &a						|	|	modificados, mas sim o conte-
	| | k = &b						|	|	údo guardado nos endereços 
	| | temp = 10;					|	|	apontados por eles.
	| :::::::::::::::::::::::::::::::	|	
	| 	a = 20;							|	
	| 	b = temp;						|	
	| :::::::::::::::::::::::::::::::	|	
	| |-----------------------------|	|	
	|									|	
	| return 0;							|	
	|-----------------------------------|	
*/

/* 	VETORES E PONTEIROS
	
	Os vetores e os ponteiros fazem a mesma função.
	
	Suponhamos a delaração de um inteiro:
	int v[10];
	int *p;

		  |---------------------------------------------  p
		|---|---|---|---|---|---|---|---|---|---|		|---|
	  V	|	|	|	|	|	|	|	|	|	|	|   	|	|
		|---|---|---|---|---|---|---|---|---|---|   	|---|
		  0	  1	  2	  3   4   5   6   7   8   9
	
	p = &v[0] <-- p aponta para v[0]
	
	Se fizermos p+1, estamos representando &p[1]
	Se fizermos p+2, estamos representando &p[2]
	
		Essas contas, possíveis de se fazer (e quando se vai avnaçando 
		na memória), é chamada de ARITMÉTICA DE PONTEIROS.
		Este enfileiramento mostrado só é possível, corretamente, quando
		tratamos de strings ou vetores.
	
	Por esse motivo, *p é v[0] (o valor)
	Do mesmo modo, *(p+1) é v[1] e *(p+2) e v[2]
	
	Quando colocamos p = v (o nome do vetor), é um sinônimo de p = &v[0].
	
	Assim, se v é o endereço de v[0], então v+1 é o endereço de v[1] e
	assim consecutivamente. Portanto, o nome do vetor, sozinho, é um 
	ponteiro, enquanto v[n] seria o equivalente a *(v+1).
	
	Reciprocamente, *p e *(p+1) podem ser representados como p[0] ou p[1].
	
	Entretanto, há uma diferença: enquanto os PONTEIROS são VARIÁVEIS, 
	construções do tipo p++ são possíveis (avançando no endereço aos
	poucos). Porém, v++ não, pois v é fixo - o endereço do início do
	vetor v.
	
	Há, porém, um problema nesse tipo de ação - como v[n] não tem um limi-
	te (ele vai avançando na memória), uma alteração pode ir modificando
	qualquer coisa armazenada naquelas posições de memória. Porém, há um
	problema: se uma dessas modificações indevidas tentar alterar uma va-
	riável do sistema (e que está protegida), o sistema mata o programa
	e se exibe a mensagem: segmentation fault */
