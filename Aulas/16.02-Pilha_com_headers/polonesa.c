#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "item.h"
#include "stack.h"

/*	Implementaremos, agora, usando uma biblioreca chamada 'stack.h',
	que criaremos em seguida. Suas funções serão:
		void stackInit(int);	- Inicia a pilha
		int stackEmpty();		- Pilha vazia: falso (== 0) se ela
								  estiver, e verdadeiro (!= 0), caso
								  contrário.
		void stackpush(Item);	- Empilha
		Item stackPop();		- Desempilha
		Item stackTop();		- Devolve o topo da pilha
		void stackFree();		- Libera a pilha
		void stackDump();		- 
*/

int strlen(char *s);

char *infixaParaPosfixa2(char *inf)
	/*	Mudaremos, agora, a função usando as funções de stack.h */
{
	char *posf; /*string que armazenará a notação posfixa*/
	
	int i;		/*contador para a string com a expressão infixa*/
	int j;		/*contador para a string com a expressão posfixa*/	
	int n = strlen(inf); /* tamanho da string com expressão infixa */
	
	
	/** INICIALIZAÇÃO DA STRING POSFIXA *******************************/
	posf = malloc((n+1)*sizeof(char));
			      /* ^-- 1 byte a mais para o caracter de finalização */
	
	/** INICIALIZAÇÃO DA PILHA ****************************************/
	stackInit(n);
	
	
	/** LEITURA E CONVERSÃO ******************************************/
	for(i=j=0; i < n; i++)
	{
		switch(inf[i])
			char x;
		{		/*^-- é um inteiro, mas mostrado pelo símbolo ASCII */
			case '(':
				/* 	Abre parênteses é adicionado à pilha. Incrementa t */
				stackPush(inf[i]) /*s[t++] = inf[i];*/
				break;
			case ')':
				/* 	Ao termos um fecha parênteses, desempilhamos o que
					houver dentro dele e tudo que estiver antes */
				while( (x = stackPop()/*s[--t]*/) != '(')
					posf[j++] = x; /* Adiciona 'x' à primeira posição va-
									  zia (j), e depois incrementa 'j', 
									  pois a nova primeira é a seguinte */
			case '+':
			case '-':
				/*	Os operadores de menor precedência - quem estiver
					em comparações com eles é executado antes */
				/*	  |-- Se a pilha não estiver vazia
					  |			|-- Se o último caracter empilhado
					  |			|   não for abre-parênteses */
				while(!stackEmpty()/*t != 0*/ 
						&& x = stackTop()/*s[t-1]*/ != '(')
					posf[j++] = stackPop()/*s[--t]*/;
					/* 	Salva na posfixa o símbolo em 's' e, depois, de-
						crementa 't' */
				stackPush(inf[i])/*s[t++] = inf[i]*/;
			case '*':
			case '/':
				while(!stackEmpty()/*t != 0*/ 
						&& (x = stackTop()/*s[t-1]*/) != '(' 
						&& x != '-' && x != '+')
					posf[j++] = stackPop()/*s[--t]*/ 
					/* Adiciona na posfixa o que acontece atrás */
				stackPush(inf[i])/*s[t++] = inf[i];*/ /* empilha o sinal */
				break;
			default:
				if(inf[i] != ' ') /* ignoramos espaços */
					posf[j++] = inf[i]; /* 	os outros casos são LETRAS, e
											são diretamente adicionadas
											ao posfixo */
				/* Não prisamos do 'break;', pois ele é o último */
		} /* fim do switch */
	} /* fim do laço */
	
	/* 	Faltou ainda colocar um último caso: quando terminamos de var-
		rer a expressão infixa, podem ter sobrado operadores - e aí
		devemos limpara a pilha e colocá-la no lugar */
	
	while(!stackEmpty() /*t != 0*/)
		posf[t++] = stackPop()/*s[--t]*/; /* Vai limpand a pilha */
	posf(j) = '\0';
	
	/** LIBERAÇÃO DE VARIÁVEIS ****************************************/	
	stackFree/*free(s)*/; /* libera a pilha */
	
	return posf;
}



int strlen(char *s)
	/*	Mostraremos uma implementação do strlen, que também pode ser
		obtido da biblioteca string.h - na realidade, a maioria das
		funções são simples, mas já estão armazenadas para facilitar*/
{
	int i;
	for(int i = 0; s[i] != '\0'; i++);
		/* 	Também seria possível colocar s[i] != 0, pois o 0 é o inteiro
			na tabela ASCII que representa o fim de string. Por outro la-
			do, se colocássemos '0', estaríamos falando do símbolo 0, cu-
			jo inteiro na tabela ASCII é 48  */
	return i;
}
