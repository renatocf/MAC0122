/*
 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP, 
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM 
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome: Renato Cordeiro Ferreira 
  NUSP: 7990933
  Prof: José Coelho da Pina

  EP3.c
  Calculadora I

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:
  - função mallocc retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO

  A estrutura deste esqueleto esta a seguir.
  Não altere esta estrutura.

  1  MACROS E CONSTANTES                
  2  DECLARACAO DE STRUCTS e TIPOS               
  3  PROTOTIPOS DAS FUNCOES DADAS
  4  PROTOTIPOS DE FUNCOES QUE VOCE DEVE FAZER
  5  M A I N
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER
  7  IMPLEMENTACAO DAS FUNCOES DADAS 

  As partes deste EP que você deverá escrever são:
  
  5  M A I N
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 
////////////////////////////////////////////////////////////////////// 
  1  MACROS E CONSTANTES 

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* numero maximo de caracteres em um linha */
#define MAX_TAMANHO 80 

/* codigos */
#define NUMERO  '#'
#define SOMA    '+'
#define SUB     '-'
#define MULT    '*'
#define DIV     '/'
#define EXP     '^'
#define NEG     '!'

/* 
////////////////////////////////////////////////////////////////////// 
  2  DECLARACAO DE STRUCTS e TIPOS
 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* ====================================================================== */
/*    Elemento para Fila e Pilha para armazenar numeros e/ou simbolos     */
/* ====================================================================== */
typedef struct celula {	
  char  simbolo; 			
  float numero;			
  struct celula *prox;	
} Celula;					


/* 
////////////////////////////////////////////////////////////////////// 
  3  PROTOTIPOS DAS FUNCOES DADAS que você não precisa implementar

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

void  * mallocSafe (size_t n);
float strtof(const char *nptr, char **endptr); /* para evitar warning */

/* 
////////////////////////////////////////////////////////////////////// 
  4  PROTOTIPOS DE FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/


/** PROTÓTIPOS DA CALCULADORA *************************************/
	Celula * constroiFilaPosfixa (char *linha);
	float calculaPosfixa(Celula *cab);

/** PROTÓTIPOS DA FILA (QUEUE) ************************************/
	Celula *queueInit();
	Celula *queuePut(Celula *cab, char simbolo, float numero); 

/** PROTÓTIPOS DA PILHA (STACK) ***********************************/
	Celula *stackInit();
	void stackPush(Celula *top, char simbolo, float numero);
	float stackPop(Celula *top);
	void stackFree(Celula *top);


/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  5  M A I N 

////////////////////////////////////////////////////////////////////// 
*/

int main(int argc, char *argv[])
{
  FILE *fentrada;
  char linha[MAX_TAMANHO]; /* recebe linha do arquivo de entrada */

  Celula *cab; /* fila de numeros e operadores */ 
  int i; 
  int contaLinha = 0;
  float numero;

  if (argc != 2) {
    printf("Para usar digite: %s <arquivoEntrada>\n", argv[0]);
    exit(-1);
  }

  fentrada = fopen(argv[1], "r");
  if (fentrada == NULL) {
    printf("Nao consegui abrir o arquivo %s\n", argv[1]);
    exit(-1);
  }
  
  while ( fgets(linha, MAX_TAMANHO, fentrada) != NULL ) {
    contaLinha++;
    i = strlen(linha);

    if (i == 0) {
      printf("Linha %d: vazia \n", contaLinha);
      continue;
    }
    
	linha[i-1] = '\0'; /* substitui \n for fim do string */
    printf("Linha %d: %s\n", contaLinha, linha);
    
    cab = constroiFilaPosfixa(linha);	
    numero = calculaPosfixa(cab);

    printf("Resultado: %f \n\n", numero);
  }

  return 0;
}

/* 
////////////////////////////////////////////////////////////////////// 
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* ====================================================================== 

  Recebe um string linha contendo a expressão posfixa e devolve o
  endereço cab da célula cabeça da fila contruída.

*/

Celula *constroiFilaPosfixa (char *linha)
{	
	Celula *line;		 /* Cabeça da fila representante da linha 	  */
	char *caracterAtual; /* Ponteiro auxiliar para percorrer a string */
	float numeroAtual;	 /* Variável auxiliar para valores numéricos 
							armazenados na pilha					  */
	
	caracterAtual = linha;
	line = queueInit();
	
	while(*caracterAtual != '\0') 		/* montagem da fila */
	{
		/** 1º CASO: NUMEROS ******************************************/
		if((*caracterAtual >= '0' && *caracterAtual <= '9')
				|| *caracterAtual == '.') 
		{
			numeroAtual = strtof(caracterAtual, &caracterAtual);
			line = queuePut(line, NUMERO, numeroAtual);
			caracterAtual++;
			continue;
		}
		/** 2º CASO: SÍMBOLOS******************************************/
		switch(*caracterAtual)
		{	
			case ' ':	/* ESPAÇO */
				caracterAtual++; 
				break;
			case SOMA:	/* '+' */
			case SUB: 	/* '-' */
			case MULT:	/* '*' */
			case DIV:	/* '/' */
			case EXP:	/* '^' */
			case NEG:	/* '!' */
				line = queuePut(line, *caracterAtual, 0);
					/* 	O número '0' é arbitrário e ignorado na função
						queuePut */
				caracterAtual++;
				break;
			default:
				/*	No último caso, o caractere é inválido para a
				 	expressão posfixa. */
				fprintf(stderr, "ERRO na expressão posfixa: não entendi"
						" a partir de '");
				
				while(*caracterAtual != '\0')
				{
				/* 	Imprime o restante do trecho que gerou 
					a irreguridadade da leitura. */
					fprintf(stderr, "%c", *caracterAtual); 
					caracterAtual++;
				}
				fprintf(stderr, "'\n");
				exit(0);

		} /* fim do switch */
	} /* fim do while */
		
	if(line->prox == line) printf("vazia");
	return line;
}

/* ====================================================================== */
/*
  recebe uma fila circular com cabeça cab de números e operadores
  representando um expressão posfixa e calcula e devolve o valor da
  expressão.

 */

float calculaPosfixa(Celula *cab)
{
	Celula *sTop;	  /* Topo da pilha 								 */
	Celula *atual;	  /* Variável auxiliar para percorrer a fila e 
					 	 empilhar os elementos						 */
	Celula *liberada; /* Auxiliar para liberar as células da fila 	 */
	float operando1;  /* Auxiliar no cálculo das operações da fila 	 */
	float operando2;  /* Auxiliar no cálculo das operações da fila	 */
	float resultado;  /* Auxiliar para guardar o resultado do cálcu-
						 lo da expressão posfixa 					 */
	
	sTop = stackInit();	
	atual = cab->prox;
	
	while(atual != cab)		/* Calcula a expressão posfixa */
	{	
		switch(atual->simbolo)
		{
			operando1 = operando2 = 0;
				
			case NUMERO:	/* '#' */
				stackPush(sTop, NUMERO, atual->numero);
				break;
			case NEG:		/* '!' */
				operando1 = (-1) * stackPop(sTop);
				stackPush(sTop, NUMERO, operando1);
				break;
			case EXP:		/* '^' */
				operando1 = stackPop(sTop);
				operando2 = stackPop(sTop);
				stackPush(sTop, NUMERO, pow(operando2, operando1));
				break;
			case DIV:		/* '/' */
				operando1 = stackPop(sTop);
				operando2 = stackPop(sTop);
				stackPush(sTop, NUMERO, (operando2 / operando1));
				break;
			case MULT:		/* '*' */
				operando1 = stackPop(sTop);
				operando2 = stackPop(sTop);
				stackPush(sTop, NUMERO, (operando2 * operando1));
				break;
			case SUB:		/* '-' */
				operando1 = stackPop(sTop);
				operando2 = stackPop(sTop);
				stackPush(sTop, NUMERO, (operando2 - operando1));
				break;
			case SOMA:		/* '+' */
				operando1 = stackPop(sTop);
				operando2 = stackPop(sTop);
				stackPush(sTop, NUMERO, (operando2 + operando1));
				break;
		} /* fim do switch */
			
		/** LIBERAÇÃO DE MEMÓRIA **************************************/	
			liberada = atual;
			atual = atual->prox;
			free(liberada);
		 
	} /* fim do while */
	
	/** LIBERAÇÃO DAS VARIÁVEIS ***************************************/
		resultado = sTop->prox->numero;
		stackFree(sTop); free(atual);		
		sTop = atual = liberada = NULL;
	
	return resultado;
}


/* ====================================================================== */
/* Implementação de funções da fila */

Celula *queueInit()
	/* 	Cria a fila utilizando uma lista encadeada 
		circular e retorna um ponteiro para ela */
{
	Celula *queue;
	queue = (Celula *) mallocSafe(sizeof(Celula));
	
	queue->prox = queue;
	return queue;
}


Celula *queuePut(Celula *cab, char simbolo, float numero) 
	/*	Adiciona um novo elemento à fila, colocando na
		célula o símbolo correspondente. Se ele for do
		tipo NUMERO, preenche o parâmetro 'numero'. Ca-
		so contrário, ignora-o. */
{
	Celula *nova;
	nova = (Celula *) mallocSafe(sizeof(Celula));
	
	cab->simbolo = simbolo;
	if(simbolo == NUMERO) cab->numero = numero;
	
	nova->prox = cab->prox;
	cab->prox = nova;
	
	return nova;
}


/* ====================================================================== */
/* Implementação de funções da pilha */

Celula *stackInit()
	/*	Cria a pilha utilizando uma lista encade-
		ada e devolve um ponteiro para ela */
{
	Celula *top;
	top = (Celula *) mallocSafe(sizeof(Celula));
	
	top->prox = NULL;
	return top;
}


void stackPush(Celula *top, char simbolo, float numero)
	/*	A função recebe a célula do topo de uma pilha
		e adiciona um elemento a esta pilha */
{
	Celula *nova;
	nova = (Celula *) mallocSafe(sizeof(Celula)); 
	
	nova->simbolo = simbolo;
	if(nova->simbolo == NUMERO) nova->numero = numero;
	
	nova->prox = top->prox;
	top->prox = nova;
}


float stackPop(Celula *top)
	/*	Desempilha uma célula que contém um nú-
		Caso não hajam mais elementos na pilha, 
		devolve uma mensagem de erro. */
{
	Celula *morta;
	float numero;	
	morta = top->prox;
	
	if(morta == NULL) 
	{
		fprintf(stderr, "ERRO: stack underflow - desempilhando "
				"uma pilha vazia\n");
		exit(0);
	}
	
	numero = morta->numero;
	top->prox = morta->prox;
	free(morta);
	
	return numero;
}


void stackFree(Celula *top)
	/*	Libera uma pilha. Se ela contiver mais de um elemento
		(a resposta), devolve uma mensagem de erro avisando da 
		tentativa de esvaziar uma pilha não totalmente vazia. */
{
	if(top->prox->prox == NULL)
	{
		free(top->prox);
		free(top);
		top = NULL;
	}
	else
	{
		fprintf(stderr, "ERRO: Liberando pilha sem esvaziá-la.\n");
		exit(0);
	}
}


/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  7  IMPLEMENTACAO DAS FUNCOES DADAS

////////////////////////////////////////////////////////////////////// 
*/

/*
  mallocSafe: testa o ponteiro devolvido por malloc
 */
void * mallocSafe (size_t n)
{
  void * pt;
  pt = malloc(n);
  if (pt == NULL) {
    printf("ERRO na alocacao de memoria.\n");
    exit(-1);
  }
  return pt;
}


