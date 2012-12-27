/*	PONTEIROS, MALLOC E STRUCTS
	
	Também é possível fazer malloc usando estruturas:
	Porém, é difiícil fazer isso usando bytes. Para saber o tamanho de va-
riáveis (sejam elas variáveis simples, vetores ou estruturas), podemos usar
a função 'sizeof' (que recebe como parâmetro o tipo de dado que se quer sa-
ber o tamanho).
	Podemos ter o seguinte exemplo:
*/	
	tipedef struct {
		int dia, mes, ano;
	} Data;	    /*--------- Padronizaremos os nomes de estruturas com */
	Data *d;			/*	letras maiúsculas */
	
	d = malloc(sizeof(Data));
/*						^------- Retorna o tamanho de Data (3 ints) */
	
/*	Mas como atribuir valores a cada um dos membros da estrutura (sendo 
que a estrutura foi feita com um ponteiro)?
	A forma mais intuitiva é: */
	(*d).dia = 11;
	(*d).mes = 3;
	(*d).ano = 0;
	
/*	Porém, a forma mais usual é: */
	d -> dia = 11;		/* É uma forma mais razoável */
	d -> mes = 3;		/* e econômica de escrever o */
	d -> ano = 0;		/* mesmo que mostrado acima  */


/* 	A MEMÓRIA É FINITA
	A memória do computador tem suas limitações. Por ese motivo, a função
malloc tem um mecanismo de erro. Ela devolve NULL quando não houver memó-
ria suficiente disponível dentro da memória. Por isso, é importante tentar
colocar alguma mensagem de erro.
	Podemos, por exemplo, fazer o seguinte 'if': */

	ptr = malloc(1);			/* EXIT_FAILURE é uma constante, colocada*/
	if(ptr == NULL) {			/* por padrão na biblioteca stdlib, para */
		exit(EXIT_FAILURE);		/* tornar o código mais legível. Porém,  */
	}							/* na maioria dos computadores, ela é e- */
								/* quivalente a (na MAIORIA dos computa- */
								/* dores), clocar 1.					 */
	/* 	A função exit é diferente de 'return', pois ela não retorna algo
		para quem chamou a função, mas realmente ENCERRA a execução dos
		programas. Para, porém, não termos de ficar fazendo esse tipo de
		verificaçõa, podemos usar mallocc (com CC no final) que, por pa-
		drão, ja imprime isso */

/* 	FREE
	
	Usamos a função FREE para poder liberar a memória, porque a feita com
	malloc não é liberada no fim do programa */
