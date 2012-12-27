/*	STRINGS EM C
	
	Em Java e C++, não temos acesso à implementação de strings, apenas 
	as utilizamos.
	
	Em C++, uma STRING é o conceiro de uma cadeia de caracteres que 
	acaba com um número especial, o '\0'
	
	Os caracteres, por sua vez, nada mais são que valores numéricos,
	armazenados, geralmente, em um byte. Quando vamos, por exemplo,
	imprimir, podemos ou imprimir NÚMEROS ou o caracter gráfico (ou
	não gráfico) associado a ele:
	*/ 	printf("%c", ch)	/*	Imprime o símbolo gráfico/não-gráfico
								associado a ch, como 'a'.*/
		printf("%d", ch) 	/*	Imprime o número inteiro associado
								a ch. Ele pode ser um símbolo gráfico
								como 'a' (inteiro 97) ou um não grá-
								fico, como '\n', que pula a linha. */
	
	/* (Exemplo de implementação de string): */
	
	char nome[1024];
		/* 	Alocação ESTÁTICA da variável */
	
	char *nome;
	nome = malloc(1024 * sizeof(char));
		/* 	Alocação DINÂMICA da variável */
