/* numero maximo de caracteres no nome do filme */
#define TAMNOME   80 

/* 
////////////////////////////////////////////////////////////////////// 
  DECLARACAO DE STRUCTS e TIPOS para armazenar filmes
 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

typedef struct filme {
  char  dist[11];
  int   votos;
  float nota;
  char  nome[TAMNOME+1];
  int   ano;
  struct filme *prox;
  struct filme *ant;
} Filme;

typedef struct lista {
  Filme *ini;
  Filme *fim;
} Lista;

/* 
////////////////////////////////////////////////////////////////////// 
   PROTOTIPOS DAS FUNCOES QUE VOCE DEVE IMPLEMENTAR

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

int  achaFilme(Lista *lista, Filme *f);
void quickSort(Lista *lista);
int  achaPalavra(unsigned char *pal, int tPal,
		 unsigned char *texto, int tTexto);


/* 
////////////////////////////////////////////////////////////////////// 
   PROTOTIPOS DE FUNCOES DADAS

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

Lista *criaLista();
Filme *criaFilme(char *d, int v, float n, char *nm, int a);
void   insereFilme(Lista *lista, Filme *entrada);


/* 
////////////////////////////////////////////////////////////////////// 
   PROTOTIPOS DE DAS FUNCOES QUE VOCE DESEJAR FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

void adicionaFilme(Lista *lista);
void buscaFilme(Lista *lista);
void removeFilme(Lista *lista);
void mostraTopMaiores(Lista *lista);
void mostraTopMenores(Lista *lista);
