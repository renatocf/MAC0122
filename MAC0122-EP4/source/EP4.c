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
	
	EP4.c
	Calculadora II
	
	Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
	de aula, caso você tenha utilizado alguma refência, liste-as abaixo
	para que o seu programa não seja considerada plágio.
	Exemplo:
	- função mallocc retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html
	
	\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
	
	
	
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
/////////////////////////////////////////////////////////////////////////
1  MACROS E CONSTANTES 

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

#define TRUE  1
#define FALSE 0

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
#define ATR     '='

/* 
///////////////////////////////////////////////////////////////////////// 
2  DECLARACAO DE STRUCTS e TIPOS
 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* =================================================================== */
/*    Elemento para Fila e Pilha para armazenar numeros e/ou simbolos  */
/* =================================================================== */
typedef struct celula {	
	char  simbolo; 			
  	float numero;			
  	struct celula *prox;	
} Celula;


/* =================================================================== */
/*    Elemento para armazenar as variáveis recebidas com as expressões 
	  infixas														   */
/* =================================================================== */
typedef struct { 
  	int    inic;
  	float valor;
} Tabela;			


/* 
////////////////////////////////////////////////////////////////////////
3  PROTOTIPOS DAS FUNCOES DADAS que você não precisa implementar

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

void  * mallocSafe (size_t n);
float strtof(const char *nptr, char **endptr); 
/* para evitar warning */

/* 
////////////////////////////////////////////////////////////////////////
4  PROTOTIPOS DE FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/


/** PROTÓTIPOS DA CALCULADORA *****************************************/
char * infixaParaPosfixa (char *linha);
Celula * constroiFilaPosfixa (char *linha);
float calculaPosfixa(Celula *cab, Tabela variavel[26]);

/** PROTÓTIPOS DE MANIPULAÇÃO DA TABELA DE VARIÁVEIS ******************/
void atualizaTabela(Tabela variavel[26], char posicao, float valor);
float carregaVariavel(Tabela variavel[26], char posicao);
void limpaTabela(Tabela variavel[26]);
void imprimeTabela(Tabela variavel[26]);
	
/** PROTÓTIPOS DA FILA (QUEUE) ****************************************/
Celula *queueInit();
Celula *queuePut(Celula *cab, char simbolo, float numero); 

/** PROTÓTIPOS DA PILHA (STACK) ***************************************/
Celula *stackInit();
void stackPush(Celula *top, char simbolo, float numero);
Celula *stackPop(Celula *top);
float stackPop_v(Tabela variavel[26], Celula *top);
char stackPop_s(Celula *top);
int stackEmpty(Celula *top);
void stackFree(Celula *top);

/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   5  M A I N 

////////////////////////////////////////////////////////////////////////
*/

int main(int argc, char *argv[])
{
  /** DECLARAÇÃO DE VARIÁVEIS ***************************************/
  	FILE *fentrada;			 /* Arquivo para leitura 				  */
  	char linha[MAX_TAMANHO]; /*	Recebe linha do arquivo de entrada 	  */	
  	Tabela variavel[26]; 	 /* Vetor para armazenar os valores encon-	
								trados para cada variável no cálculo 
								da expressão posfixa				  */
  	int contaLinha = 0;		 /* Auxiliar para quantidade de linhas	  */
  	int i; 					 /* Auxiliar para tamanho da linha 		  */
  	char *posfixa;			 /* String com expressão posfixa 		  */
  	Celula *cab; 			 /*	Fila de numeros e operadores 	  	  */ 
  	float numero;			 /* Resultado da expressão de uma linha   */
	
	
  	/** ARGUMENTOS INSUFICIENTES **************************************/
  	if (argc != 2) /* ERRO #1: Argumentos Insuficientes */
	{
	  printf("Para usar digite: %s <arquivoEntrada>\n", argv[0]);
	  exit(-1);
	}
	
  	/** VALIDAÇÃO DO ARQUIVO ******************************************/
  	fentrada = fopen(argv[1], "r");
  	if(fentrada == NULL) /* ERRO #2: Arquivo inválido */
	{
	  printf("Nao consegui abrir o arquivo %s\n", argv[1]);
	  exit(-1);
	}
	
  	/** LEITURA DO ARQUIVO ********************************************/
  	limpaTabela(variavel);
 	while(fgets(linha, MAX_TAMANHO, fentrada) != NULL) 
	{
		contaLinha++;
	  	i = strlen(linha);
		
	  	if (i == 1) /* Linha vazia */
		{
	  		printf("Linha %d: vazia \n", contaLinha);
	  		continue;
		}
		
	  	/* Preparação para o cálculo */
	  	linha[i-1] = '\0'; /* substitui \n for fim do string */
				
	  	printf("Linha %d: %s\n", contaLinha, linha);
	  	/* printf("Cheguei aqui! 1\n"); */
	
	  	/* Calcula a expressão */
	  	posfixa = infixaParaPosfixa(linha);
	  	cab = constroiFilaPosfixa(posfixa);	
	  	numero = calculaPosfixa(cab, variavel);
		
	  	/* Imprime os resultados */
	  	printf("Resultado: %f \n\n", numero);	
	  	imprimeTabela(variavel);
	}
	
  	/* Liberação de memória */
  	limpaTabela(variavel);
  	posfixa = NULL;	cab = NULL;
	
  	return 0;
}

/* 
////////////////////////////////////////////////////////////////////// 
6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

char *infixaParaPosfixa (char *linha)
{
  	/* PROBLEMA: transformar uma frase de infixa para posfixa */
  	char *posfixa;		 /* String representante da expressão posfixa */
  	char *caracterAtual; /* Ponteiro auxiliar para percorrer a string */
  	int i;				 /* Contador para percorrer a string posfixa  */
  	Celula *sTop;
  	Celula *atual;
	
  	posfixa = (char *) mallocSafe(MAX_TAMANHO * sizeof(*posfixa));
  	for(i = 0; i < MAX_TAMANHO; i++) posfixa[i] = ' ';
  	sTop = stackInit();
	
  	caracterAtual = linha;
  	for(i = 0; *caracterAtual != '\0'; caracterAtual++)
	{
	  	/* printf("Infixa para ...: caractere = %c\n", *caracterAtual); */
		if(*caracterAtual == ' ') continue;
	  	if((*caracterAtual >= '0' && *caracterAtual <= '9') 
			|| *caracterAtual == '.')
		{
	  		posfixa[i++] = *caracterAtual;
	  		if((*(caracterAtual+1) < '0' || *(caracterAtual+1) > '9')
		 		&& *(caracterAtual+1) != '.')
				posfixa[i++] = ' ';
	  		continue;
		}
		if(*caracterAtual >= 'A' && *caracterAtual <= 'Z')
		{
	  		posfixa[i++] = *caracterAtual;
	  		posfixa[i++] = ' ';
	  		continue;
		}
		switch(*caracterAtual)
		{
			case '(':
		  		stackPush(sTop, '(', 0);
		  		break;
			case ')':
				atual = sTop->prox;
				while(atual != NULL 
					&& atual->simbolo != '(')
				{
			  		posfixa[i++] = stackPop_s(sTop);
			  		posfixa[i++] = ' ';
			  		atual = sTop->prox;
				}
		  		stackPop_s(sTop);
		  		break;
			case ATR:
		  		atual = sTop->prox;
		  		while(atual != NULL 
				&& atual->simbolo != '(' 
				&& atual->simbolo != ATR)
				{
			  		posfixa[i++] = stackPop_s(sTop);
			  		posfixa[i++] = ' ';
			  		atual = sTop->prox;
				}
		  		stackPush(sTop, *caracterAtual, 0);
		  		break;
			case SOMA:
			case SUB:
		  		atual = sTop->prox;
		  		while(atual != NULL
					&& atual->simbolo != '(' 
					&& atual->simbolo != ATR)
				{
			  		posfixa[i++] = stackPop_s(sTop);
			  		posfixa[i++] = ' ';
			  		atual = sTop->prox;
				}
		  		stackPush(sTop, *caracterAtual, 0);
		  		break;
			case MULT:
			case DIV:
		  		atual = sTop->prox;
		  		while(atual != NULL 
					&& atual->simbolo != '(' 
					&& atual->simbolo != ATR
					&& atual->simbolo != SOMA 
					&& atual->simbolo != SUB)
				{
			  		posfixa[i++] = stackPop_s(sTop);
			  		posfixa[i++] = ' ';
			  		atual = sTop->prox;
				}
		  		stackPush(sTop, *caracterAtual, 0);
		  		break;
			case EXP:
			  	atual = sTop->prox;
		  		while(atual != NULL 
					&& atual->simbolo != '(' && atual->simbolo != ATR
					&& atual->simbolo != SOMA && atual->simbolo != SUB
					&& atual->simbolo != MULT && atual->simbolo != EXP
					&& atual->simbolo != EXP && atual->simbolo != EXP)
				{
			  		posfixa[i++] = stackPop_s(sTop);
			  		posfixa[i++] = ' ';
			  		atual = sTop->prox;
				}
		  		stackPush(sTop, *caracterAtual, 0);
		  		break;
			case NEG:
		  		atual = sTop->prox;
				while(atual != NULL 
					&& atual->simbolo != '(' && atual->simbolo != ATR
					&& atual->simbolo != SOMA && atual->simbolo != SUB
					&& atual->simbolo != EXP && atual->simbolo != NEG)
				{
					posfixa[i++] = stackPop_s(sTop);
					posfixa[i++] = ' ';
					atual = sTop->prox;
				}
				stackPush(sTop, *caracterAtual, 0);
				break;
		}
	}

  	atual = sTop->prox;
  	while(atual != NULL)
    {
      	posfixa[i++] = stackPop_s(sTop);
      	posfixa[i++] = ' ';
      	atual = sTop->prox;
    }

  	posfixa[i+1] = '\0';
  	printf("%s\n", posfixa);
	
  	return posfixa;
}


/* ================================================================== */ 
/* Recebe um string linha contendo a expressão posfixa e devolve o
   endereço cab da célula cabeça da fila contruída. */

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
	  	/** 1º CASO: VARIÁVEIS ****************************************/
	  	if(*caracterAtual >= 'A' && *caracterAtual <= 'Z')
	  	{	
	  		line = queuePut(line, *caracterAtual, 0);
	  		caracterAtual++;
	  		continue;
		}
      	/** 2º CASO: NUMEROS ******************************************/
      	if((*caracterAtual >= '0' && *caracterAtual <= '9')
	 			|| *caracterAtual == '.') 
		{
	  		numeroAtual = strtof(caracterAtual, &caracterAtual);
	  		line = queuePut(line, NUMERO, numeroAtual);
	  		caracterAtual++;
	  		continue;
		}
      	/** 3º CASO: SÍMBOLOS ******************************************/
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
			case ATR:	/* '=' */
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


/* ================================================================= */
/* Recebe uma fila circular com cabeça cab de números e operadores
   representando um expressão posfixa e calcula e devolve o valor da
   expressão. */

float calculaPosfixa(Celula *cab, Tabela variavel[26])
{
  	Celula *sTop;	  /* Topo da pilha 								 */
	Celula *atual;	  /* Variável auxiliar para percorrer a fila e 
			    		 empilhar os elementos						 */
  	Celula *liberada; /* Auxiliar para liberar as células da fila 	 */
  	float operando1;  /* Auxiliar no cálculo das operações da fila 	 */
  	float operando2;  /* Auxiliar no cálculo das operações da fila	 */
  	char var_nome;	  /* Auxiliar na atribuição de valor em variável */
  	float resultado;  /* Auxiliar para guardar o resultado do cálcu-
					     lo da expressão posfixa 					 */
	
  	sTop = stackInit();	
  	atual = cab->prox;

  	while(atual != cab)		/* Calcula a expressão posfixa */
    {
      	if(atual->simbolo >= 'A' && atual->simbolo <= 'Z')
		{	
	  		var_nome = atual->simbolo;
	  		stackPush(sTop, var_nome, 0);

	  		liberada = atual;
	  		atual = atual->prox;
	  		free(liberada);
	  		continue;
		}

      	switch(atual->simbolo)
		{
	  		operando1 = operando2 = 0;

			case NUMERO:	/* '#' */
	  			stackPush(sTop, NUMERO, atual->numero);
	  			break;
			case NEG:		/* '!' */
	  			operando1 = (-1) * stackPop_v(variavel, sTop);
	  			stackPush(sTop, NUMERO, operando1);
	  			break;
			case EXP:		/* '^' */
	  			operando1 = stackPop_v(variavel, sTop);
	  			operando2 = stackPop_v(variavel, sTop);
	  			stackPush(sTop, NUMERO, pow(operando2, operando1));
	  			break;
			case DIV:		/* '/' */
	  			operando1 = stackPop_v(variavel, sTop);
	  			operando2 = stackPop_v(variavel, sTop);
	  			stackPush(sTop, NUMERO, (operando2 / operando1));
	  			break;
			case MULT:		/* '*' */
	  			operando1 = stackPop_v(variavel, sTop);
	  			operando2 = stackPop_v(variavel, sTop);
	  			stackPush(sTop, NUMERO, (operando2 * operando1));
	  			break;
			case SUB:		/* '-' */
	  			operando1 = stackPop_v(variavel, sTop);
	  			operando2 = stackPop_v(variavel, sTop);
	  			stackPush(sTop, NUMERO, (operando2 - operando1));
	  			break;
			case SOMA:		/* '+' */
	  			operando1 = stackPop_v(variavel, sTop);
	  			operando2 = stackPop_v(variavel, sTop);
	  			stackPush(sTop, NUMERO, (operando2 + operando1));
	  			break;
			case ATR:		/* '=' */
	  			operando1 = stackPop_v(variavel, sTop);
	  			var_nome = stackPop_s(sTop);

	  			atualizaTabela(variavel, var_nome, operando1);
	  			stackPush(sTop, NUMERO, operando1);
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


/* ================================================================== */
/* Implementação de funções para manejar a tabela de variáveis */

void atualizaTabela(Tabela variavel[26], char posicao, float valor)
/*	Recebe um vetor cujas posições correspondem às letras
	de A...Z, um caracter com uma letra de A...Z com a po-
	sição e um valor. Atualiza com 'valor' o conteúdo da 
	variável desejada, inicializando-a se ela não foi uti-
	lisada antes. */
{
  	int posicaoCorrigida; /* Auxiliar para o inteiro correspondente à
			   				 posição passada com um caracter entre 
			   				 A...Z */
  	Tabela *var_atual;	  /* Auxiliar para a variável na posição 
			     			 'posicaoCorrigida' no vetor de variá
			     			 veis. */  

  	posicaoCorrigida = posicao - 'A';
  	var_atual = &variavel[posicaoCorrigida];

  	/* if (var_atual->inic == FALSE) */
  	var_atual->inic = TRUE;
  	var_atual->valor = valor;
}


float carregaVariavel(Tabela variavel[26], char posicao)
{
  	int posicaoCorrigida; /* Auxiliar para o inteiro correspondente à
			   				 posição passada com um caracter entre 
			   				 A...Z */
  	Tabela *var_atual;	  /* Auxiliar para a variável na posição 
			     			 'posicaoCorrigida' no vetor de variá
			     			 veis. */  

  	posicaoCorrigida = posicao - 'A';
  	var_atual = &variavel[posicaoCorrigida];

  	if(var_atual->inic == FALSE)
    	fprintf(stderr, "AVISO: operando com variável '%c' não "
	    		"inicializada\n", posicao);
  	return var_atual->valor;
}


void limpaTabela(Tabela variavel[26])
/* 	Recebe um vetor cujas posições correspondem às letras
	de A...Z. Declara-as como não inicializadas e substi-
	tui seus valores por 0. */
{
  	int j; /* contador */
  	for(j = 0; j < 26; j++)
    {
      	variavel[j].inic = FALSE;
      	variavel[j].valor = 0;
    }
  	printf("\n");
}


void imprimeTabela(Tabela variavel[26])
/*	Recebe um vetor cujas posições correspondem às letras
	de A...Z. Imprime o valor das variáveis inicializadas
	em uma tabela. */
{
  	int j; /* contador */

  	printf("Conteúdo das variáveis\n");
  	printf(" Variável |    Valor       \n");
  	printf("----------|----------------\n");
  	for(j = 0; j < 26; j++) 
    {	
      	if(variavel[j].inic) 
			printf("     %c    |   %f     \n", 
	       			(j+'A'), variavel[j].valor);
    }

  	printf("\n........................................\n\n");
}


/* ================================================================== */
/* Implementação de funções da fila */

Celula *queueInit()
/* 	Cria a fila utilizando uma lista encadeada 
	circular e retorna um ponteiro para ela */
{
  	Celula *queue;
  	queue = (Celula *) mallocSafe(sizeof(*queue));

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
  	nova = (Celula *) mallocSafe(sizeof(*nova));

  	cab->simbolo = simbolo;
  	if(simbolo == NUMERO) cab->numero = numero;

  	nova->prox = cab->prox;
  	cab->prox = nova;

  	return nova;
}


/* ================================================================== */
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
  	if(nova->simbolo == NUMERO || (nova->simbolo >= 'A' 
				&& nova->simbolo <= 'Z')) nova->numero = numero;

  	nova->prox = top->prox;
  	top->prox = nova;
}


Celula *stackPop(Celula *top)
/*	Desempilha e devolve a última célula de uma 
	pilha. Caso a pilha esteja vazia, imprime 
	uma mensagem de erro. */
{
  	Celula *desempilhada;
  	desempilhada = top->prox;

  	if(desempilhada == NULL) 
    {
      	fprintf(stderr, "ERRO: stack underflow - desempilhando "
	      		"uma pilha vazia\n");
      	exit(0);
    }

  	top->prox = desempilhada->prox;	
  	return desempilhada;
}


float stackPop_v(Tabela variavel[26], Celula *top)
/*	Desempilha a última célula de uma pilha	e devolve seu valor.
	Imprime uma mensagem erro se a pilha estiver vazia */
{
  	Celula *morta;
  	float valor;

  	morta = stackPop(top);
  	if ('A' <= morta->simbolo && morta->simbolo <= 'Z')
    {
      	int i = morta->simbolo - 'A';
      	if (variavel[i].inic == FALSE) 
			fprintf(stderr, "AVISO: operando com variável não inicializada "
					"'%c'\n", morta->simbolo);	
      	valor = variavel[i].valor;
    }
  	else valor = morta->numero;

  	free(morta); 
  	morta = NULL;
  	return valor;
}


char stackPop_s(Celula *top)
/*	Desempilha a última célula de uma pilha	e devolve seu símbo-
	lo. Imprime uma mensagem de aviso caso a célula seja do tipo
	NUMERO e uma de erro se a pilha estiver vazia */
{
  	Celula *morta;
  	char simbolo;

  	morta = stackPop(top);
  	if(morta->simbolo == NUMERO)
    	fprintf(stderr, "AVISO: devolvendo simbolo de célula "
	    		"não significativo (símbolo da célula é NUMERO\n");
  	simbolo = morta->simbolo;

  	free(morta);
  	morta = NULL;
  	return simbolo;
}


int stackEmpty(Celula *top)
{
	Celula *ultima;
	ultima = top->prox;

	return ultima == NULL;
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
