/*
 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEcALHO COM O MEU NOME E O MEU N�MERO USP, 
  DECLARO QUE SOU O �NICO AUTOR E RESPONS�VEL POR ESSE PROGRAMA. 
  TODAS AS PARTES ORIGINAIS DESSE EXERC�CIO PROGRAMA (EP) FORAM 
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUc�ES DESSE EP
  E QUE PORTANTO Nao CONSTITUEM PL�GIO. DECLARO TAMB�M QUE SOU RESPONS�VEL
  POR TODAS AS C�PIAS DESSE PROGRAMA E QUE EU Nao DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIcao. ESTOU CIENTE QUE OS CASOS DE PL�GIO Sao PUNIDOS COM 
  REPROVAcao DIRETA NA DISCIPLINA.

  Nome: Renato Cordeiro Ferreira
  NUSP: 7990933
  Prof: Jos� Coelho da Pina

  EP5
  Ordenacao de filmes

  Os arquivos que compoem este EP sao:
     utils.[h|c], iofilmes.[h|c], filmes.[h|c] e main.c

  Refer�ncias: Com excecao das rotinas fornecidas no esqueleto e em sala
  de aula, caso voc� tenha utilizado alguma ref�ncia, liste-as abaixo
  para que o seu programa nao seja considerada pl�gio.
  Exemplo:
  - funcao mallocc retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
////////////////////////////////////////////////////////////////////// 

  A estrutura deste esqueleto esta a seguir.
  Nao altere esta estrutura.

  1  MACROS E CONSTANTES                
  2  PROTOTIPOS DAS FUNCOES (locais)
  3  M A I N
  4  IMPLEMENTACAO DAS FUNCOES (locais) 

////////////////////////////////////////////////////////////////////// 
*/

#include <stdio.h>
#include <stdlib.h>


#include "filmes.h" /* estrutura de e funcoes para manipulacao da 
                          lista de filmes:
                             - criaLista
                             - criaFilme
                             - insereFilme
                             - achaFilme
                             - quickSort
              */

#include "iofilmes.h"  /* funcoes de entrada e saida:
                             - carregaLista  
                             - gravaLista
                             - mostraUmFilme
                             - mostraLista 
                        */
#include "utils.h"    /* funcoes de uso geral: 
                             - mallocSafe
                             - leString
              */

/* 
////////////////////////////////////////////////////////////////////// 
  1  MACROS E CONSTANTES 

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/


#define CARREGAR   'c'
#define GRAVAR     'g'
#define INSERIR    'i'
#define MOSTRAR    'm'
#define ORDENAR    'o'
#define PROCURAR   'p'
#define REMOVER    'r'
#define MSTRMENOR  't'
#define MSTRMAIOR  'u'
#define SAIR       'x'


/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

  2  P R O T O T I P O S 

////////////////////////////////////////////////////////////////////// 
*/

/* A funcao leOpcao so e usada neste arquivo. */
char  leOpcao(); 

/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

  3  M A I N 

////////////////////////////////////////////////////////////////////// 
*/
int main()
{
    char opcao;
    Lista *lista = criaLista();
    int ORDENADO = FALSE;
        
    /* declaracao das demais variaveis do main */
    
    /* iterara ate o usuario digitar 'x' para sair */
    do { 
        
      opcao = leOpcao();
      switch (opcao) {
    
      case CARREGAR:
        carregaLista(lista);
        break;
    
      case GRAVAR:
        gravaLista(lista);
        break;
    
      case INSERIR:
        adicionaFilme(lista);
        break;
        
      case MOSTRAR:
        mostraLista(lista);
        break;
        
      case ORDENAR:
        ORDENADO = TRUE;
        quickSort(lista);
        break;
        
      case PROCURAR:
        buscaFilme(lista);
        break;
        
      case REMOVER:
        removeFilme(lista);
        break;
        
      case MSTRMENOR:
        if(ORDENADO == FALSE)
            printf("Lista nao ordenada\n");
        else
            mostraTopMenores(lista);
        break;
        
      case MSTRMAIOR:
        if(ORDENADO == FALSE)
            printf("Lista nao ordenada\n");
        else
            mostraTopMaiores(lista);
        break;
        
      case SAIR:
        break;
    
      default :
        printf("\nOpcao '%c' nao reconhecida\n\n", opcao);
        break;
    }
  } while (opcao != SAIR);
  
  return 0;
}

/* 
////////////////////////////////////////////////////////////////////// 

  4. IMPLEMENTACAO DAS FUNCOES DADAS 

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/


/*
----------------------------------------------------------------------
Funcao leOpcao
   Le uma opcao do usuario.
*/

char leOpcao()
{
  char opcao;

  printf(
     "======================================================================\n"
     "  (c) Carregar um arquivo de dados\n"
     "  (g) Gravar a lista atual em um arquivo\n"
     "  (i) Inserir um filme\n"
     "  (m) Mostrar todos os filmes\n"
     "  (o) Ordenar a lista de filmes\n"
     "  (p) Procurar a nota de um filme\n"
     "  (r) Remover um filme\n"
     "  (t) Mostrar N filmes com nota menor que X e pelo menos V votos\n"
     "  (u) Mostrar N filmes com nota maior que X e pelo menos V votos\n"
     "  (x) Sair do programa\n\n"
     );
  printf("Digite uma opcao: ");
  scanf(" %c", &opcao);
  
  return opcao;
}
