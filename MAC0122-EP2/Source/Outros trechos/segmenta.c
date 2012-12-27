int  segmentaRegioes(Imagem *img, CelRegiao cabecas[MAX_REGIOES])
{
	int i, j;			
	int ultima = 0;		
	float corNova = 0.5;
	
	for(i = 0; i < img->nL; i++)
	{
		for(j = 0; j < img->nC; j++)
		{
			if(getPixel(img, i, j) == COR_FUNDO) 
			{
				cabecas[ultima].tamanho = juntaPixels(img, i, j, corNova,
					&cabecas[ultima].cabpix);
				ultima++;
			}
		}
	}
	
	printf("\nGrupos de pixels conexos:\n");
	for(i = 0; i < ultima; i++)
		printf("Grupo %3d tem %1d pixels\n", i, cabecas[i].tamanho);
	
	return ultima;
