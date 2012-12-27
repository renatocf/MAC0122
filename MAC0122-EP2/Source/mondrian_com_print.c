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

  EP2.c
  Mondrians

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:
  - A função mallocSafe foi baseada na função mallocc 
    retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

 \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO.
  COPIE O ESQUELETO PARA UM OUTRO ARQUIVO, E EDITE AS PARTES 5 E 6
  CONTENDO A SUA SOLUÇÃO.

  A estrutura deste esqueleto esta em seguida.
  Não altere esta estrutura.

  1  DECLARACAO DE STRUCTS e TIPOS               
  2  MACROS E CONSTANTES                
  3  PROTOTIPOS DAS FUNCOES DADAS
  4  PROTOTIPOS DE FUNCOES QUE VOCE DEVE FAZER
  5  M A I N
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER
  7  IMPLEMENTACAO DAS FUNCOES DADAS 

  As partes deste EP que você deverá escrever são:
  
  5  M A I N
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER
*/

#include <stdlib.h>
#include <stdio.h>


/* 
////////////////////////////////////////////////////////////////////// 
  1  DECLARACAO DE STRUCTS e TIPOS
 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

typedef unsigned char BYTE;

struct celPixel {
  int x, y;
  struct celPixel *prox;
};
typedef struct celPixel CelPixel;


struct celRegiao {
  int tamanho;
  CelPixel cabpix;
};
typedef struct celRegiao CelRegiao;


typedef struct {
  int nL;
  int nC;
  float **pixel;
} Imagem;

struct lineStruct {
  char tipo;
  int pos, ini, fim;
  struct lineStruct *prox;
};
typedef struct lineStruct Linha;


/* 
////////////////////////////////////////////////////////////////////// 
  2  MACROS E CONSTANTES 

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

#define TIPO_HORIZONTAL 'H'
#define TIPO_VERTICAL   'V'

#define EXIT_FAILURE_MALLOC -1

#define MAX_REGIOES 1000
#define MAX_LINHA 256

#define COR_FUNDO 1.0
#define COR_BORDA 0.0

/* 
////////////////////////////////////////////////////////////////////// 
  3  PROTOTIPOS DAS FUNCOES DADAS

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
void *mallocSafe (size_t nbytes);

void leMondrian(char *nomeArquivo, int *altura, int *largura, Linha *cab);

void salvaImagemRGB (char *nomeArquivo, Imagem *R, Imagem *G, Imagem *B);

void salvaImagem (char *nomeArquivo, Imagem *img);


/* 
////////////////////////////////////////////////////////////////////// 
  4  PROTOTIPOS DE FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* Protótipos das funções que você precisa implementar */
float getPixel(Imagem *img, int x, int y);

void  setPixel(Imagem *img, int x, int y, float cor);

void  pintaImagem(Imagem *img, float cor);

void  copiaImagem (Imagem *destino, Imagem *origem);

Imagem *criaImagem(int nLins, int nCols);

void desenhaLinha(Imagem *img, Linha * lin, float cor);

void desenhaBorda(Imagem *img, float cor);

int  juntaPixels(Imagem *img, int x, int y, 
		 float corNova, CelPixel *cabeca);

int  segmentaRegioes(Imagem *img, CelRegiao cabecas[MAX_REGIOES]);

void pintaRegiao(CelPixel *cab, Imagem *R, Imagem *G, Imagem *B, 
		 float cor[3]);



/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  5  M A I N 

////////////////////////////////////////////////////////////////////// 
*/

int main(int argc, char** argv)
{
  	/** ALOCAÇÃO DE VARIÁVEIS ****************************************/
		Imagem *img;		/*	Estrutura que guarda imagem genérica */
		int altura;			/* 	Dimensao da estrutura imagem 		 */
		int largura;		/* 	Dimensão da estrutura imagem 		 */
		Linha cab;			/* 	Lista com comando para criar linhas	 */
		Linha *atual;		/* 	Ponteiro auxiliar para fazer linhas	 */
		Imagem *R, *G, *B;	/* 	Canais de cores para imagem			 */
		int totalElementos;	/* 	Auxiliar para nº de regiões	achadas	 */
		int i;				/*	Contador 							 */
		CelRegiao cabecas[MAX_REGIOES];
			/* 	Vetor para cabeças das regiões de pixel	da imagem	 */
		float cores[12][3]=
			/*	Matriz para cores a serem colocadas nos canais 		 */
		{
 			{1.0, 0.0, 0.0}, /*  0 vermelho	*/
 		 	{0.0, 1.0, 0.0}, /*  1 verde   	*/
			{0.0, 0.0, 1.0}, /*  2 azul    	*/
			{1.0, 1.0, 0.0}, /*  3 amarelo 	*/
			{1.0, 0.0, 1.0}, /*  4 magenta 	*/
			{0.0, 0.0, 0.0}, /*  5 preto   	*/
			{0.2, 0.7, 0.4}, /*  6 verde 2 	*/
			{0.7, 0.4, 0.2}, /*  7 marrom  	*/
			{0.0, 1.0, 1.0}, /*  8 ciano   	*/
			{0.5, 0.5, 0.5}, /*  9 cinza   	*/
			{1.0, 1.0, 1.0}, /* 10 branco  	*/
			{0.0, 0.0, 0.0}  /* 11 preto   	*/
		};


  	/** LEITURA DE ARQUIVO DE ENTRADA ********************************/
		cab.prox = NULL;
		leMondrian(argv[1], &altura, &largura, &cab);
		printf("\n(LEITURA)\t\taltura = %d largura = %d\n", altura, largura);
	

	/** FUNDO E BORDAS ***********************************************/	
		img = criaImagem(altura, largura);
		pintaImagem(img, COR_FUNDO);
		printf("(FUNDO) \t\tTudo OK\n");	
		desenhaBorda(img, COR_BORDA);
		printf("(BORDAS) \t\tTudo OK\n");
	
	
	/** DESENHO DE LINHAS ********************************************/
		for(atual = cab.prox; atual != NULL; atual = atual->prox)
		{
			printf("%c\n", atual->tipo);
			desenhaLinha(img, atual, COR_BORDA);
		}
		printf("(LINHAS) \t\tTudo OK\n");
	
		
	/** SEGMENTAÇÃO DE REGIÕES ***************************************/
		totalElementos = segmentaRegioes(img, cabecas);
		printf("total de elementos = %d\n", totalElementos);
		printf("(REGIOES) \t\tTudo OK\n");	
		printf("cabela: cabeca[0].tamanho = %d", cabecas[0].tamanho);
	
	
	/** CRIAÇÃO DOS CANAIS DE CORES **********************************/
		R = criaImagem(altura, largura); 
		copiaImagem(R, img);				/* Vermelho */

		G = criaImagem(altura, largura); 
		copiaImagem(G, img);				/* Verde */
	
		B = criaImagem(altura, largura); 
		copiaImagem(B, img);				/* Azul */
		printf("(MALLOC FILTROS) \tTudo OK\n");
		printf("(copia) \t\tTudo OK\n");
	
	
	/** PINTURA ******************************************************/
		for(i = 0; i < totalElementos; i++)
		{
			printf("%d", i);
			pintaRegiao(&cabecas[i].cabpix, R, G, B, cores[i%12]);
			printf("verm = %f,  verde = %f, azul = %f\n", cores[i][0], cores[i][1], cores[i][2]);
		};
		
	
	/** SALVAR IMAGENS ***********************************************/
		salvaImagem("img", img);
		salvaImagem("R", R);
		salvaImagem("G", G);
		salvaImagem("B", B);
		salvaImagemRGB(argv[2], R, G, B);
		printf("(SALVAR) \t\tTudo OK\n");


	/** LIBERAÇÃO DE MEMÓRIA *****************************************/
		free(img);
		free(R);
		free(G);
		free(B);
		printf("(FREE) \t\t\tTudo OK\n");
	
	return 0;
}

/* 
////////////////////////////////////////////////////////////////////// 
  6  IMPLEMENTACAO DAS FUNCOES QUE VOCE DEVE FAZER

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
float getPixel(Imagem *img, int x, int y)
	/* 	A função recebe o endereço de uma imagem e uma coordenada (x,y);
		Retorna o valor daquele pixel */
{
	return img->pixel[x][y];
}


void  setPixel(Imagem *img, int x, int y, float cor)
	/* 	A função recebe o endereço de uma imagem e coloca um valor na 
		posição (x,y) da matriz bidimensional que compõe a imagem */
{
	img->pixel[x][y] = cor;
}


void  pintaImagem(Imagem *img, float cor)
	/*	A função recebe como parâmetro o endereço de uma imagem e colo-
		ca em todos os pixels dela uma cor (representado por um número 
		float), */
{
	int i,j;
	
	for(i = 0; i < img->nL; i++) {
		for(j = 0; j < img->nC; j++) {
			setPixel(img, i, j, cor);
		}
	}
}


void  copiaImagem (Imagem *destino, Imagem *origem)
	/*	A função recebe o endereço de uma imagem e devolve uma cópia de-
		la, armazenada num endereço previamente alocado e recebido por
		meio do parâmetro *origem. */
{
	int i, j; float pixelAtual;
	destino->nL = origem->nL;
	destino->nC = origem->nC;
	
	for(i = 0; i < origem->nL; i++) {
		for(j = 0; j < origem->nC; j++)
		{
			pixelAtual = getPixel(origem, i, j);
			setPixel(destino, i, j, pixelAtual);
		}
	}
}


Imagem *criaImagem(int nLins, int nCols)
	/*	A função recebe o número de linhas e de colunas e cria uma estru-
		tura do tipo 'Imagem', na qual será criada uma matriz de tamanho
		nLins x nCols */
{
	 /** ALOCAÇÃO DE VARIÁVEIS ****************************************/
		int i;				/* Variável auxiliar 	*/
		Imagem *novaImagem;	/* Imagem a ser alocada */
		novaImagem = mallocSafe(sizeof(Imagem));
			/* 	Alocamos com malloc para a variável não ser descartada
				com o fim da função */

	 /** CRIAÇÃO DA IMAGEM ********************************************/
		novaImagem->nL = nLins;
		novaImagem->nC = nCols;
		
		/* Alocando a matriz 'pixel' na estrutura novaImagem */
		novaImagem->pixel = mallocSafe(nLins * sizeof(int *));
		for(i = 0; i < nLins; i++)
			novaImagem->pixel[i] = mallocSafe(nCols * sizeof(int));
		
	 /** RETORNO ******************************************************/
		return novaImagem;
}


void desenhaLinha(Imagem *img, Linha * lin, float cor)
	/*	A função recebe uma imagem e uma estrutura de linha. Desenha a 
		linha com a cor passada como parâmetro na matriz da imagem. */
{
	int var;
	int posicao_fixa = lin->pos;
	int ini = lin->ini;
	int fim = lin->fim;
	
	switch(lin->tipo) {
		case 'h':
		case TIPO_HORIZONTAL:
			for(var = ini; var < fim; var++)
				setPixel(img, posicao_fixa, var, cor);
			break;
		case 'v':
		case TIPO_VERTICAL:
			for(var = ini; var < fim; var++)
				setPixel(img, var, posicao_fixa, cor);
			break;
		default:
			printf("Erro na leitura!");
			break;
	}
}


void desenhaBorda(Imagem *img, float cor)
	/*	Recebe uma imagem e uma cor. Desenha as bordas com a co nas
		linhas 0 e nL-1 e nas colunas 0 e nC-1 da matriz da imagem. */
{
	int i;	/* Variável auxiliar */
	
	for(i = 0; i < img->nC; i++) {
		/* Desenhando as linhas superior e inferior */
		setPixel(img, 0, i, cor);
		setPixel(img, img->nL-1, i, cor);
	}	
	
	for(i = 0; i < img->nL; i++) {
		/*Desenhando as colunas esquerda e direita */
		setPixel(img, i, 0, cor);
		setPixel(img, i, img->nC-1, cor);
	}
}


int juntaPixels(Imagem *img, int x, int y, float corNova, CelPixel *cabeca)
	/* 	A função juntaPixels recebe uma imagem e 2 posições. Captura re-
		cursivamente todas as células com COR_FUNDO e as pinta com corNova.
		Armazena a posição desse pixel numa lista encadeada iniciada por
		'cabeça'. Retorna o total de pixels da região. */
{	
	/** ALOCAÇÃO DE VARIÁVEIS *****************************************/
		int r; /*contador*/
		CelPixel *nova;
	
	/** BASE DA RECURSÃO **********************************************/
		if(getPixel(img, x, y) == corNova) return 0;
		if(getPixel(img, x, y) == COR_BORDA) return 0;
	
	/** AÇÕES *********************************************************/
		nova = mallocSafe(sizeof(CelPixel));
		setPixel(img, x, y, corNova);
	
		nova->x = x;
		nova->y = y;
		nova->prox = cabeca->prox;
		cabeca->prox = nova;
		r=1; /* Conta a chamada recursiva atual para o total */
	
	/** NOVAS CHAMADAS RECURSIVAS *************************************/
		r += juntaPixels(img, x+1, y, corNova, nova); /* direita	*/
		r += juntaPixels(img, x, y+1, corNova, nova); /* baixo		*/
		r += juntaPixels(img, x-1, y, corNova, nova); /* esquerda	*/
		r += juntaPixels(img, x, y-1, corNova, nova); /* cima 		*/
		
	return r;
}


int  segmentaRegioes(Imagem *img, CelRegiao cabecas[MAX_REGIOES])
{
	int i, j;
	int ultima = 0;
	float corNova = 0.5;
	
	for(i = 0; i < img->nL; i++)/*(i = img->nL-1; i >= 0; i--)*/
	{
		for(j = 0; j < img->nC; j++) /*< (j = img->nC-1; img->nC; j++)*/
		{
			if(getPixel(img, i, j) == COR_FUNDO) 
			{
				cabecas[ultima].tamanho = juntaPixels(img, i, j, corNova,
					&cabecas[ultima].cabpix);
				ultima++;
			}
		}
	}
	
	printf("Grupos de pixeis conexos:\n");
	for(i = 0; i < ultima; i++)
		printf("Grupo %3d tem %1d pixels\n", i, cabecas[i].tamanho);
	
	return ultima;
}


void pintaRegiao(CelPixel *cab, Imagem *R, Imagem *G, Imagem *B, 
		 float cor[3])
	/*	A função recebe uma lista encadeada de pixels que fazem parte
		de uma subregião, três imagens (canais) e um vetor com as cores-
		padrão. Para cada posição do pixel, colore cada cor corresponden-
		te nas imagens R, G e B. */
{
	int i, j;
	CelPixel *pixel_atual;
	pixel_atual = cab->prox;
	/*printf("cor 1 = %f", cor[0]);*/
		
	while(pixel_atual != NULL)
	{
		i = pixel_atual->x; j = pixel_atual->y;
		/*printf("%d ", i);*/
		
		setPixel(R, i, j, cor[0]);
		setPixel(G, i, j, cor[1]);
		setPixel(B, i, j, cor[2]);
		pixel_atual = pixel_atual->prox;
	}
}


/* 
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
  7  IMPLEMENTACAO DAS FUNCOES DADAS

////////////////////////////////////////////////////////////////////// 
*/

/* *****************************************************************
   mallocSafe: testa o malloc para ver se o ponteiro é válido
 */
void *mallocSafe (size_t nbytes)
{
   void *ptr;
   ptr = malloc (nbytes);
   if (ptr == NULL) {
     fprintf (stderr, "Socorro! malloc devolveu NULL!\n");
     exit (EXIT_FAILURE_MALLOC);
   }
   return ptr;
}


/* *****************************************************************
  salvaImagem RGB organizada em 3 imagens cinza no formato ppm
  Assumindo origem no canto inferior esquerdo.
 */
void salvaImagemRGB(char *nomeArquivo, Imagem *R, Imagem *G, Imagem *B)
{
  int i, j;
  char nome[256];
  FILE *fp;
  sprintf(nome, "%s.ppm", nomeArquivo);
  fp = fopen(nome, "wb");

  fprintf(fp, "P6\n%d %d\n255\n", R->nC, R->nL);
  
  for (i = R->nL - 1; i>=0; i--)
    for (j = 0; j < R->nC; j++) 
      fprintf(fp, "%c%c%c", 
	      (BYTE)(255*R->pixel[i][j]), 
	      (BYTE)(255*G->pixel[i][j]), 
	      (BYTE)(255*B->pixel[i][j]));

  fprintf(stdout, "A imagem foi salva no arquivo: %s\n", nome);
  fclose(fp);
}

/* *****************************************************************
  salvaImagem cinza no formato pgm
 */
void salvaImagem(char *nomeArquivo, Imagem *img)
{
  int i, j;
  char nome[256];
  FILE *fp;
  sprintf(nome, "%s.pgm", nomeArquivo);
  fp = fopen(nome, "wb");
   
  fprintf(fp, "P5\n%d %d\n255\n", img->nC, img->nL);
  
  for (i = img->nL - 1; i>=0; i--)
    for (j = 0; j < img->nC; j++) 
      fprintf(fp, "%c", (BYTE)(255*img->pixel[i][j]));

  fprintf(stdout, "A imagem foi salva no arquivo: %s\n", nome);
  fclose(fp);
}

/* *****************************************************************
  carrega Linhas
 */

void leMondrian(char *nomeArquivo, int *altura, int *largura, Linha *cab)
{
  char aux[MAX_LINHA];
  int npars;
  FILE *entrada;
  int p, i, f;
  Linha *nova;
  int cont = 0;

  entrada = fopen(nomeArquivo, "r");
  if (entrada == NULL) 
    {
      fprintf(stderr, "ERRO!! Nao consegui abrir o arquivo %s\n", nomeArquivo);
      exit(-1);
    }
  fprintf(stdout, "Arquivo de entrada com a definicao do desenho: %s\n", 
	  nomeArquivo);

  while (fscanf(entrada, "%s", aux) != EOF) 
    {
      switch (aux[0]) {
      case '#':
	fgets(aux, MAX_LINHA, entrada);
	break;

      case 'r':
      case 'R':
	npars = fscanf(entrada, "%d %d", altura, largura);
	if (npars != 2) {
	  fprintf(stderr, "ERRO na leitura da dimensao da"
		  " imagem no arquivo de entrada %s\n", nomeArquivo);
	  exit (-1);
	}
	else {
	  fprintf(stdout, "Resolucao da Imagem: %d linhas x %d colunas \n",
		  *altura, *largura);
	}
	break;
	
      case 'H':
      case 'h':
	npars = fscanf(entrada, "%d %d %d", &p, &i, &f);
	if (npars != 3) {
	  fprintf(stderr, "ERRO na leitura de uma linha horizontal"
		  " no arquivo de entrada %s\n", nomeArquivo);
	  exit (-1);
	}
	else {
	  cont += 1;
	  nova = mallocSafe(sizeof(Linha));
	  nova->prox = cab->prox;
	  nova->tipo = TIPO_HORIZONTAL;
	  nova->pos = p;
	  nova->ini = i;
	  nova->fim = f;

	  cab->prox = nova;
	  fprintf(stdout, "Linha %3d: Tipo H com pos = %4d, "
		  "inicio = %4d e fim %4d\n", 
		  cont, p, i, f);
	}
	break;

      case 'V':
      case 'v':
	npars = fscanf(entrada, "%d %d %d", &p, &i, &f);
	if (npars != 3) {
	  fprintf(stderr, "ERRO na leitura de uma linha vertical no"
		  " arquivo de entrada %s\n", nomeArquivo);
	  exit (-1);
	}
	else {
	  cont += 1;
	  nova = mallocSafe(sizeof(Linha));
	  nova->prox = cab->prox;
	  nova->tipo = TIPO_VERTICAL;
	  nova->pos = p;
	  nova->ini = i;
	  nova->fim = f;

	  cab->prox = nova;
	  fprintf(stdout, "Linha %3d: Tipo V com pos = %4d, "
		  "inicio = %4d e fim %4d\n", cont, p, i, f);
	}
	break;

      default:
	fgets(aux, MAX_LINHA, entrada);
	break;
      }
    }
  fclose(entrada);
}
