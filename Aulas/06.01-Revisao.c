/* AULA PASSADA
*/

struct data {
	int dia;
	int mes;
	int ano;
};

typedef struct data Data;
	/* Pos padrão, definiremos os nomes para srtucts com a primeira le-
	   tra MAIÚSCULA. */
Data aniversario;
Data casamento;

aniversario.dia = 1;
aniversario.mes = 1;
aniversario.ano = 1;

casamento = aniversario;

/*
 		|---|		|---|	A atribuição casamento = aniversario
	dia	| 1	|  -->	| 1	|	faz com que cada uma das variáveis da pri-
		|---|		|---|	meira estrutura seja copiado na segunda
	mes	| 1	|  -->	| 1	|	(tudo que havia na estrutura 'casamento' é
		|---|		|---|	copiado em 'aniversario').
	ano	| 1	|  -->	| 1	|	
		|---|		|---|	
	
	ENDEREÇOS
*/

char c;			/* Tipos primitivos - inteiros e caracteres */
int i;			
				
struct {		/* Estruturas/registros - acumulam diferentes tipos */
	int x, y;	/* de variáveis. */
} ponto;		

int v[4];		/* vetores - acumulação de mesmos tipos de variáveis */


/* 	A memória do computador é como um vetor unidimensional muito grande.
	Ela é dividido em várias partes pequenas: os 'bytes' (que ocupam 8
	bits - sequência de 0 e 1)
	
	Cada tipo de variável ocupa um certo espaço:
	- caracter: por padrão, ocupa 1 byte na memória;
	- inteiro: por padrão, ele tem 4 bytes de espaço;
	- structs: depende do tipo de variável. No caso de 'ponto', temos 
			   espaço para cada variável (4 bytes para ponto.x e 4 bytes
			   para ponto.y - na memória, eles ficam juntos conforme a 
			   ordem de alocamento);
	- vetores: são todos do mesmo tipo de variável (ou de estrutura). Eles
			   ficam armazenados contiguamente na memória;
	- float: ocupam 4 bytes (mas têm uma distribuição diferente da dos 
			 'int' da memória);
	- double: ocupa o dobro do float (4 bytes).
	
	
	Para saber o tamanho que uma variável ocupa no computador, existe 
	a função 'sizeof()', que recebe como parâmetro o nome de uma variá-
	vel. Por exemplo, para um computador-padrão de 32 bits:
		sizeof(char); - devolve 1;
		sizeof(float); -> devolve 4;
	
	As memórias são vetores. Porém, em vez de terem índices, eles têm 
	ENDEREÇOS, que mostram onde estão as memórias.
	Os endereços são mostrados na base HEXADECIMAL (que tem como caracte-
	rística começar sempre com 0x, para indicar a base numérica 16 do nú-
	mero).
	
	Para mostrar o endereço de uma variável, usamos o operador unário 
	'&' (e-comercial) antes do nome da variáveç. Para imprimir o endereço,
	temos por exemplo:
*/
	printf("end i = %p\n", &i);
/*	
	Para representar que queremos imprimir o ENDEREÇO de uma variável, 
	usamos '%p' (cuja função é análoga a %d, %f, %s, %i, %c).
	
	Todos os caracteres são ilusórios. Eles são, na verdade, números 
	inteiros, que são representados por números positivos e negativos.
	Os caracteres Da tabela ASCII representam, nos números de 1 a 127, 
	a maioria dos caracteres latinos não acentuados.
	Quando queremos imprimir, se colocamos "%c" para uma variável do tipo
	'char', será imprimido o símbolo. Se for colocado, porém, o "%d", 
	será impresso o inteiro associado àquele símbolo.
	
	Quem aministra a alocação de memória é o sistema operacional. Como há
	vários programas executando ao mesmo tempo, o SO vai coordenando a 
	alocação entre partes diferentes da memória.
	Quando o programa encerra, as variáveis alocadas estaticamente é li-
	berada para o sistema (linguagens que têm coletores de lixo podem fa-
	zer o trabalho, mas em C não existe essa vantagem).
*/
