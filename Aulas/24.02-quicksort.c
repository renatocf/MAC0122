int separa(int p, int r, int v[])
{
	int i = p-1, j, x = v[r], t;
	for(j = p; j <= r; j++)
		if(v[j] <= x)
   	{
			t = v[++i]; v[i] = v[j]; v[j] = t;
   	}
	return i;
}

/*	Baseado na subrotina acima (a separação), cuja complexidade de 
	tempo é O(n), podemos construir o quicksort, um algoritmo de 
	ordenação cujo paradigma é o de 'divisão e conquista' - divi-
	dir o problema em vários subproblemas que podem ser mais fa-
	cilmente resolvidos.
	
	Uma subrotina pode ser comparada a um lema, que é uma ferra-
	menta para um teorema (que, em Computação, é chamado de ROTINA).
	A intenção, em ambos os casos, é deixar mais claro o algoritmo
	proposto.
*/

void quicksort(int p, int r, int v[])
{
/*1*/	int p, r, q;
	
/*2*/	if(p < r)
			/*	Este 'if' mostra que está ordenado quando tivermos
				um elemento (p = r) ou zero elementos (p > r), pois
				ninguém ou 1 elemento sempre estarão ordenados. */
		{
/*3*/		q = separa(p, r, v);
/*4*/		quicksort(p, q-1, v);
/*5*/		quicksort(q+1, r, v);
		}
}

/*	CONSUMO DE TEMPO
	
	Seja T(n) = consumo de tempo para o quicksort ordenar 'n' 
	elementos.
	
	linha	|
	--------|------------
	1		| = O(1)
	2		| = O(1)
	3		| = O(n)
	4		| = T(k)
	5		| = T(n-k-1)
	--------|------------
	TOTAL	| = T(k) + T(n-k-1) + O(n)
	
	Pois o vetor é separado, após acharmos o 'q', na forma:
		 _______________ ___ _______________________
		|				|	|						|
		 ^^^^^^^^^^^^^^^ ^^^ ^^^^^^^^^^^^^^^^^^^^^^^
				k		  q			  n-k-1
	
	Temos que:
	T(0) = 1
	T(1) = 1
	T(n) = T(k) + T(n-k-1) + O(n), ∀ n > 1
	
	Esse tipo de relação de RECORRÊNCIA é mais estudada em 
	Análise de Algoritmos (MAC0338). No nosso caso, usaremos,
	no lugar, uma análise de MELHOR/PIOR caso.
	
	
	*1º caso: dividindo pela metade:
	
				|---------------|---------------|					O(n)
				//								\\					
		|-------|-------|				|-------|-------|			O(n/2)
			//		\\						//		\\				
	|---|---|		|---|---|		|---|---|		|---|---|		O(n/4)
	//		\\		//		\\		//		\\		//		\\		
	|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|	O(n/8)
									...								...
	|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|	O(1)
	
	
	Assim como para o merge sort, este algoritmo é O(n*lg n) para 
	o caso de divisões ao meio.
	
	
	*2º caso: vetor ordenado
				|--------------------------|x|	~n
										  //
			  	|-------------------------|x|	~n-1
						  				 //
		    	|------------------------|x|	~n-1
										//
		  		|-----------------------|x|		...
					  				   //
				|----------------------|x|
									  //
				|---------------------|x|
									 //
				|--------------------|x|
									//
				|-------------------|x|
								   //
				|------------------|x|
								  //
				|-----------------|x|
								 //
				|----------------|x|
								//
				|---------------|x|
							   //
				|--------------|x|
							  //
				|-------------|x|
							 //
				|------------|x|
							//
				|-----------|x|
						   //
				|----------|x|
						  //
				|---------|x|
						 //
				|--------|x|
						//
				|-------|x|
					   //
				|------|x|
				      //
				|-----|x|
				   	 //
				|----|x|
					//
				|---|x|
				   //
				|--|x|
				  //
				|-|x|
				 //
				||x|
				 //
				|x|						~1
	
	Estas são todas as divisões feitas nesse caso. Temos então:
	Este é o pior caso possível para o quicksort:
	(n+1)*n/2 = (n²+n)/2 ~ n² = O(n²)
	
	Na realidade, a análise da complexidade do quicksort é uma análise
	probabilistica mais complexa. Dentro do universo de entradas pos-
	síveis, ele é mais útil em vários casos.
	
	Com a análise probabilística, acha-se que o quicksort é O(n*lg n).
	Este O(n*lg n), analisado contra o O(n*lg n) do merge sort, é mais
	rápido, justamente por causa das constantes que a notação assimp-
	tótica acaba escondendo (as operações do SEPARA do quicksort são
	mais simples que do INTERVALA do mergesort).
	
	A principal diferença do merge sort e do quicksort é que o merge
	deixa a maioria do trabalho para a volta da divisão e conquista 
	(a maior parte fica na intercalação pós divisão). Por outro la-
	do, o quicksort faz o contrário: o trabalho está na parte antes
	da divisão e conquista (na intercalação).
*/
