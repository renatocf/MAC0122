/* Temos vários métodos de entrada e saída:

	printf("%d oi\n", &i);
	É a abreviatura de:
	fprintf(stdout, "%d oi\n", &i);
	^		  ^
	|		  |-- saída padrão (tela) - ela também é um arquivo.
	|--- O 'f' vem de 'file'

	scanf("%f", &x);
	É a abreviatura de:
	fscanf(stdin, "%f", &x);
			 ^
			 |-- entrada padrão do arquivo (teclado) - também um arquivo
	
	Criemos um programa para copiar arquivos:
*/

#include<stdio.h>
/* #include<stderr.h> */
/* é o que GUARDA os arquivos stdin (teclado) e stdout (tela) e tem os
   protótipos das funções */

int main(int argc, char *argv[])
{
	FILE *original;	/* Criamos dois ponteiros para pegar onde está o 	*/
	FILE *copia;	/* arquivo que desejamos 							*/
	char ch;	

	/*			  |- permite abrir o arquivo original					*/
	/*			  |		|- associa o arquivo origial ao primeiro 		*/
	/*			  |		|  parâmetro									*/
	/*			  |		|	  |- só para leitura						*/
	original = fopen(argv[1],"r");
	if(original == NULL)
	{
		printf("O arquivo não existe!\n");
		return -1;
	}
	
	copia = fopen(argv[2],"w");
	if(copia == NULL)
	{
		fprintf(stderr,"Não existe o arquivo para copiar\n");
		return -2;
	}
	
	/*		+-- função para indicar o fim do arquivo */
	while(!feof(original))
	{
		fscanf(original,"%c",&ch);
		fprintf(copia,"%c",ch);
	}
	
	fclose(copia);fclose(original);
	return 0;
}
