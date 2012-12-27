int G(int a, int b)
{
	int x\
	x = a+b;
	return x;
}

int F(int i, int k, int k)
{
	int x;
	x = G(i, j)
	x = x + k;
	return x;
}
	
int main()
{
	int i, j, k, y;
	i = 111; j = 222; k = 444;
	y = F(i, j, k);
	printf("y = %d", y);
	return 0;
}

/* 	/1/ Na pilha de execução, primeiro começamos criando as variáveis
	do main:
	
	y			|	  ?		|
	k			|	  ?		|
	j			|	  ?		|
	i			|	  ?		|	
	end. retorno| 010101010	|
	
	/2/ Em seguida, atribuímos um valor:

	y			|	  ?		|
	k			|	 444	|
	j			|	 222	|
	i			|	 111	|	
	end. retorno| 010101010	|
	
	/3/ Na chamada de função, alocamos na pilha os espaços para F. O 
		main volra quando aparecer o comando de retorno:
	
	
	y			|	  ?		|
	k			|	 444	| } Começam
	j			|	 222	| } inicializados
	i			|	 111	| }	
	end. retorno| &endereço	|
	y			|	  ?		|
	k			|	 444	|
	j			|	 222	|
	i			|	 111	|	
	end. retorno| 010101010	|
	
	/4/ Ocorre a nova chamada de função
	
	x			|	  ?		|
	b			|	 222	|
	a			|	 111	|	
	end. retorno| &endereço	|
	x			|	  ?		|
	k			|	 444	| } Começam
	j			|	 222	| } inicializados
	i			|	 111	| }	
	end. retorno| &endereço	|
	y			|	  ?		|
	k			|	 444	|
	j			|	 222	|
	i			|	 111	|	
	end. retorno| 010101010	|
