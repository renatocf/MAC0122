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
	
	
	/** FUNDO E BORDAS ***********************************************/	
		img = criaImagem(altura, largura);
		pintaImagem(img, COR_FUNDO);
		desenhaBorda(img, COR_BORDA);
	
		
	/** DESENHO DE LINHAS ********************************************/
		for(atual = cab.prox; atual != NULL; atual = atual->prox)
			desenhaLinha(img, atual, COR_BORDA);
	
	
	/** SEGMENTAÇÃO DE REGIÕES ***************************************/
		totalElementos = segmentaRegioes(img, cabecas);
		
	
	/** CRIAÇÃO DOS CANAIS DE CORES **********************************/
		R = criaImagem(altura, largura); 
		copiaImagem(R, img);				/* Vermelho */

		G = criaImagem(altura, largura); 
		copiaImagem(G, img);				/* Verde */
	
		B = criaImagem(altura, largura); 
		copiaImagem(B, img);				/* Azul */
	
	
	/** PINTURA ******************************************************/
		for(i = 0; i < totalElementos; i++)
			pintaRegiao(&cabecas[i].cabpix, R, G, B, cores[i]);
			

	/** LIBERAÇÃO DE MEMÓRIA *****************************************/
		free(img);
		free(R);
		free(G);
		free(B);
	
	return 0;
}
