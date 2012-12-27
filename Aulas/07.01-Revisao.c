/* MEMÓRIA, PONTEIROS E VETORES
	
	A memória é como um grande vetor, sendo que cada local é identificado
por um endereço escrito em HEXADECIMAL (base 16).
	Para sabermos o endereço de uma variável, colocamos o operador unário
e-comercial (&) antes dele:
	i - mostra o valor; 
	&i - endereço onde está armazenado conteúdo de i.
	
	PONTEIROS são variáveis feitas para guardar endereços. Elas funcionam
ao contrário das variáveis normais, pois estas expressam, primeiro, o ende-
reço, e se colocarmos o operador unário asterisco (*), falamos do conteúdo
guardado naquele endereço de momória APONTADO pelo ponteiro.
	p - endereço;
	*p - conteúdo armazenado no endereço guardado em 'p'.
	Quando fazemos (p+1) ou (p+2), avançamos na memória pela quantidade de
bytes do tipo de variável ponteiro 'p' (se for char, avança 1 byte, se for
int, avança 4 bytes, etc.).
	
	VETORES e PONTEIROS
	Os vetores são praticamente iguais aos ponteiros dentro de C. Quando 
nos referenciamos a 'v', apontamos para o endereço de v[0] (&v[0]). Se
avançamos para &v[1], é o mesmo que fazer (v+1). Portanto, se colocarmos
o operador ASTERISCO (*), temos o CONTEÚDO daquele endereço.
	Assim:
	&v[0] é análogo a v				v[0] é análogo a *v
	&v[1] é análogo a v+1			v[1] é análogo a *(v+1)
	etc.							etc.
	A principal diferença entre VETORES e PONTEIROS é que algo como 
'v = &a;' é impossível, pois o vetor não é uma variável, mas uma estrutura
de dados que reúne várias variáveis do mesmo tipo ordenadamente numa regi-
ão da memória.
*/
	
