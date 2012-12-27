/*	O primeiro algoritmo de R.S. Boyer e J.S. Moore
	Ele utiliza uma heurística diferente, que tenta, mais inteligen-
	temente, refletir sobre o padrão para se adequar à uma possibi-
	lidade. Ex:
	
	| | | | | | | | | | |a| | | | | | | | |
	 		 a b a e f c a
	
	| | | | | | | | | | |a| | | | | | | | |
	 			 	 a b a e f c a

	| | | | | | | | | | |a| | | | | | | | |
	 			 	 	 a b a e f c a
	
	O algoritmo tenta encontrar uma maneira mais rápida, 'acelerando'
	ao pular de um lugar para outro.
	
	Ele tenta, sempre, acelerar o máximo possível.
*/ 
