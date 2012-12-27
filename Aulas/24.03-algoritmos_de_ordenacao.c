/*	Em geral, existem algoritmos de ordenação muito mais eficientes,
	usando para isso, na realidade, algoritmos híbridos que exploram
	o melhor potencial de cada algoritmo de ordenação.
	
	O 'quicksort' em geral é melhor em ordenações na memória RAM, pois
	ele cobre a maioria dos casos simples.
	
	O 'merge sort' é usado, em geral, para arrumar em bancos de dados
	e memória em disco - que são menos acessados e usados para grandes
	quantidades.
	
	Já o 'inserction sort' é mais utilizada em casos quando temos a 
	sequência quase ordenada e queremos colocar mais elementos. Tam-
	bém é útil para quando tivermos casos de dados que chegam online
	(chegam constantemente ao longo do tempo de execução).
