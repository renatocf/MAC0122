/* 	PROBLEMA
	
	Traduzir para notação posfixa uma expressão infixa
	
	inf
	 |->|A|+|B|*|C|-|D|\0| | | | | |	}---|
											| estrutura de strings
	posf									|
	 |->|A|B|C|*|+|D|-|\0| | | | | |	}---|
	
	 	s						 n-1
	 	|%|%|%|%|%|%| | | | | | | |
		^			 t			  ^
		início		 topo		  fim
	
	Um pequeno exemplo de tradução, para lembrar:
	A+B*C (infixa)	<=>	 ABC*+ (posfixa)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strlen(char *s);

char *infixaParaPosfixa(char *inf)
{
	char *posf; /*string que armazenará a notação posfixa*/
	char *s; 	/*pilha */
	int t; 		/*topo da pilha*/
	
	int i;		/*contador para a string com a expressão infixa*/
	int j;		/*contador para a string com a expressão posfixa*/
	
	int n = strlen(inf); /* tamanho da string com expressão infixa */
	
	
	/** INICIALIZAÇÃO DA STRING POSFIXA *******************************/
	posf = malloc((n+1)*sizeof(char));
				/* ^-- 1 byte a mais para o caracter de finalização */
	
	/** INICIALIZAÇÃO DA PILHA ****************************************/
	s = malloc(n*sizeof(char));
	t == 0; /*pilha vazia*/
	
	/** LEITURA E CONVERSÃO ******************************************/
		/* 	Estrutura do switch-case:
			switch(<expressão>) - sempre deve ser um inteiro
			{
				case constante1: 
					<comando>; } Podem-se colocar os comandos
					<comando>; } embaixo de constante1
					...		   } 
					break;	- encerra o switch, pois tudo que 
							  vem abaixo dele, depois do ponto
							  de entrada, ele executaria tudo
							  abaixo. O 'break' serve para 
							  avisar quando ele deve parar. Se
							  houver um break para cada 'case',
							  teremos um análogo a if-elses 
							  encaixados.
				case constante2: <comando>; <comando>; ...
									^ podem estar todos em linha
					break;
				case constante3: <comando>; <comando>; ...
				 .
				 .
				 .
				default: <comando1>; <comando2>; ... } É executado quando
					break;							 } não entramos em 
													   nenhum case - é
													   o caso padrão
													   (default)
			} - encerramos com uma chave
		
		NOTA: podemos declarar variáveis dentro de cada bloco, por causa
			  da pilha da memória, que tem blocos alocados conforme o 
			  nela conforme eles aparecem. Se quisermos fazer isso no 
			  meio, devemos usar a função 'malloc'
	*/
	for(i=j=0; i < n; i++)
	{
		char x;
		switch(inf[i])
		{		/*^-- é um inteiro, mas mostrado pelo símbolo ASCII */
			case '(':
				/* 	Abre parênteses é adicionado à pilha. Incrementa t */
				s[t++] = inf[i];
				break;
			case ')':
				/* 	Ao termos um fecha parênteses, desempilhamos o que
					houver dentro dele e tudo que estiver antes */
				while( (x = s[--t]) != '(')
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
				while(t != 0 && (x = s[t-1]) != '(')
					posf[j++] = s[--t];
					/* 	Salva na posfixa o símbolo em 's' e, depois, de-
						crementa 't' */
				s[t++] = inf[i];
			case '*':
			case '/':
				while(t != 0 && (x = s[t-1]) != '(' 
						&& x != '-' && x != '+')
					posf[j++] = s[--t] /* Adiciona na posfixa o que acon-	
										  tece atrás */
				s[t++] = inf[i]; /* empilha o sinal */
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
	
	while(t != 0)
		posf[t++] = s[--t]; /* Vai limpand a pilha */
	posf(j) = '\0';
	
	/** LIBERAÇÃO DE VARIÁVEIS ****************************************/	
	free(s); /* libera a pilha */
	
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
