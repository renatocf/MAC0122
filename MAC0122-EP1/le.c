#include <stdio.h>
#include <stdlib.h>


int 
main(int argc, char *argv[]) 
{
   FILE *fp; 
   int    n;
   int  *sequencia;
   int i;

  if (argc < 2) 
    {
      fprintf(stdout,"%s: uso: %s <nome do arquivo com a sequencia>\n.", 
	      argv[0], argv[0]); 
      return -1;
    }  
 
   if (!(fp = fopen(argv[1],"rb"))) 
     {
       printf("Erro na leitura do arquivo '%s'.\n", argv[1]);
       return -1;
     }  
   
   fread(&n, sizeof(int), 1, fp);
   printf("A sequencia tem %d numeros.\n", n);
   
   /* aloque um vetor de n posicoes */
  if ((sequencia = (int *) malloc(n * sizeof(int))) == NULL)
    {
      fprintf(stderr,"%s: espaco insuficiente.\n", argv[0]);
      return -5;
    }

  /* leia a sequencia */ 
  if (fread(sequencia, sizeof(int), n, fp) < n) 
     {
       fprintf(stdout,"O arquivo %s nao esta completo.\n", argv[1]);
       return -6;
     }
   fclose(fp);
   
   for (i = 0; i < n; i++)
     printf(" %d ", sequencia[i]);

   printf("\n");

   return 0;
}
