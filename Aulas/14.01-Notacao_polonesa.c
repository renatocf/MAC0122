/* 	Notação polonesa
	
	Usuamente os operadores são escritos entre os operandos como em:
	
	(A + B) * D + E / (F + A * D) + C
	A - B + C
	
	Essa é a chamada notação INFIXA (que está entre os números)
	
	Na notação POLONESA ou POSFIXA os operadores sõ escritos depois 
	dos operandos:
		AB+ D* EFAD*+/+C+
	A ordem das operações mostradas será feita pegando os dois operandos
	mais próximos do opedador e executando. Na ordem de execução, teríamos:
	
	01- (AB+)							| Esse tipo de operação é muito
	02- (AB+)D*							| útil para os computadores, pois
	03- (AB+)D* (AD*)					| tira dúvidas de em que ordem 
	04- (AB+)D* F(AD*)+					| executar as operações. Essa no-
	05- (AB+)D* E(F(AD*)+)/				| tação é usada pelos compiladores
	06- ( (AB+)D* E(F(AD*)+)/ )+		| para facilitar a execução dos 
	07- (( (AB+)D* E(F(AD*)+)/ )+ )C+	| comandos passados.
	
	Na realidade, o que se faz, geralmente, é entrar com as informações
	(por exemplo, inserir A e B) e depois operar com eles (+).
*/

/*	PROBLEMA:
	Traduzir para notação posfiza a expressão infixa em ma cadeia de carac-
	teres INFIXA
	
	INFIXA					| POSFIXA		| SIMULAÇÃO
	------------------------|---------------|------------------------
	A + B * C				| ABC*+			| ABC*+ 
							|				| = A(B*C)+ 
							|				| = A+(B*C)			OK
	%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%
	A*(B+C)/D-E				| ABC+*D/E-		| ABC+*D/E- 
							|				| = A(B+C)*D/E-
							|				| = A*(B+C)D/E-
							|				| = A*(B+C)/D 
							|				| = A*(B+C)/D-E		OK
	%%%%%%%%%%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%|%%%%%%%%%%%%%%%%%%%%%%%%
	A+B*(C-D*(E-F)-G*H)-I*3	|				| 
	
	
	Vamos converter a terceira expressão acima. Um fato, porém, que pode-
	mos identificar é que as variáveis não mudam de ordem nas cores.
	
	ABCDEF
	
	^ - ordem de armazenamento dos operadores
	|	
	|	NÍVEIS DE EXECUÇÃO
	|
	|	  1	2	3	4	5	6
	|	  | |	|	|	|	|
	|	  |	|	|	|	|	|
	|	  ^	^	^	^	^	^
9º	|	*				} Executamos o (*), pois têm procedência
	|					  maior frente ao (+) que estava antes
8º	|	-					} Executamos o (-) por último
Par1|	)		}---------------------------------------| Executa-
7º	|	*		}										| mos o que
6º	|	-		}--------------------| Este (-) aguarda | está den-
	|								 |					| tro dos 
Par2|	) }	Achamos o primeiro fecha | Em C, com opera-	| parênte-
5º	|	- }	parênteses - colocamos 	 | dores de mesma	| ses, no
Par2|	( } ele nas operações		 | procedência, há	| nível em
4º	|	* 	} O * é levado, pois 	 | preferência para	| que ele 
	|		  tem precedência maior	 | os da esquerda  	| já está
3º	|	-	}------------------------| (mais baixo), 	|
	|								   ele sai.			|
Par1|	(		}---------------------------------------|
2º	|	*			} O * é executado neste
	|				  nível, pois têm pro-
	|				  cedência maior
1º	|	+			} Como (+) está mais a 
	|				  esquerda (mais à bai-
	|				  xo), é executado pri-
	|				  meiro.

	No final, a operação fica:
	^^^^^^---- 	Aguardamos 6 entradas (incluido parênteses) para
	||||||		poder colocar algum operador. Entre eles, coloca-
	||||||		mos as variáveis que vieram - sendo que 6 delas
	||||||		ficam no total
	||||||	 ^^----	Agora esperamos 2 passos até chegarmos ao 
	||||||	 ||		próximo fecha-parênteses - e armazenamos 2
	||||||	 ||		variáveis
	||||||	 ||	   ^^---- Armazenamos 2 operadores - e aguar-
	||||||	 ||	   ||	  damos 2 variáveis
	ABCDEF-*-GH*-*+I3*-	
	
*/

/*	-----------------------------------------
	PILHAS
	-----------------------------------------
	
	Uma PILHA é uma lista dinâmica em que todas as operações (inserções,
	remoções, consultas) são feitas em uma mesma extremidade chamada de
	TOPO:
	
	Em inglês, as pilhas são apelidadas de LIFO: Last In First Out
	(último a entrar, primeiro a sair).
	
	-----------------------------------------
	IMPLEMENTAÇÃO EM UM VETOR
	-----------------------------------------
	
	^- vem do nome STACK (pilha, em inglês)
	s	|%%%|%%%|%%%|%%%|%%%|%%%|	|	|	|	|	|	|	|	|
		  0						  t							 n-1
	
	t = índice da primeira posição disponível
	
	pilha vazia:  t == 0
	pilha cheira: t == n
	
	-------------------------------------------------------------------	
	Para REMOVER um elemento, faça:		| Em inglês, chamamos o ato		
		t = t-1;	// ou t -= 1 ou t--	| de EMPILHAR de POP			
		x = s[t];						| Quando tentamos desempilhar	
	ou equivalentemente:				| da pilha vazia temos um:		
		x = t[--t];						| 		STACK UNDERFLOW			
	-------------------------------------------------------------------	
	Para INSERIR um elemento, faça:		| Em inglês, chamamos o ato 	
		s[t] = x;						| de DESEMPILHAR de PUSH		
		t += 1;							| Quando tentamos empilhar da	
	ou equivalentemente:				| pilha cheira, temos um:		
		s[t++] = x;						| 		STACK OVERFLOW			
	-------------------------------------------------------------------	
	
*/
