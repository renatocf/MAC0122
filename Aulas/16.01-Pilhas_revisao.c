/*	Faremos, agora, os arquivos que implementarão as diversas partes (inclu-
 *	indo a pilha) que montará as partes da pilha. As partes serão:
 *
 * 		polonesa.ci				   item.h
 * 	|-------------------|	!-------------------|
 *	|#include "item.h"	|	|typedef char Item	|
 *	|#include "stack.h"	|	|					|
 *	|					|	|					|
 *	|int main(){		|	|					|
 *	|					|	|					|
 *	|}					|	|					|
 *	|-------------------|	|-------------------|
 *
 * 		     stack.h				   stack.c
 *	|-----------------------|	|-------------------|
 *	|void stackinit(int);	|	|#include "item.h"	|
 *	|int stackEmpty();		|	|void stack(int n){	|
 *	|void stackPush(Item);	|	|					|
 *	|Item stackPop();		|	|					|
 *	|Item stackTop();		|	|}					|
 *	|void stackFree();		|	|					|
 *	|-----------------------|	|-------------------|
