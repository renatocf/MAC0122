/*	INTERFACES
	
	A interface é um fronteira entre a IMPLEMENTAÇÃO de uma biblioteca e
	o PROGRAMA que usa a biblioteca.
	
	Um CLIENTE é um programa que chama alguma função da biblioteca.
	
	
	IMPELEMENTAÇÃO						} 
	libm							    } O implementador encapsula
	|-------------------------------|   } funções em uma biblioteca
	| double sqrt(double x) {		|   } específica.
	| 	  [...]						|   } 
	| 	  return raiz;				|   } 
	|	  [...]						|   } 
	|-------------------------------|   } 
	
	
	INTERFACE							} 
	math.								} É como os protótipos de 
	|-------------------------------|	} função, que serve para
	| double sqrt(double);			|	} ser incluído depois para
	| double sin(double);			|	} que os comandos funcionem.
	| double cos(double);			|	} 
	| double pow(double, double);	|	} 
	|-------------------------------|	} 
	
	
	CLIENTE							   	} 
	prog.c							 	} Faz alguma função utili-
	|-------------------------------| 	} zando as funções incluídas
	| #include<stdio.h>				|  	} na biblioteca.
	| 	 [...]						|  	} 
	| 	 c = sqrt(a + b + c)		|  	} 
	| 	 [...]						|  	} 
	|-------------------------------|  	} 
*/
