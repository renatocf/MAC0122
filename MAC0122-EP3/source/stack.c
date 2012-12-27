#include <stdlib.h>
#include <stdio.h>
#include "item.h"

/*
 * PILHA: uma implementacao com lista encadeada sem cabeca
 */
typedef struct stackNode* Link;
struct stackNode { 
  Item conteudo; 
  Link prox; 
};

struct stack { /* aqui esta especificado o que e' */
  Link topo;   /* uma pilha: um apontador para stacknode */
};
typedef struct stack *Stack;

static void *mallocSafe (unsigned int n);

Stack
stackInit(int n)
{ 
  Stack s = (Stack) mallocSafe(sizeof *s);
  s->topo = NULL; 
  return s;
}

int 
stackEmpty(Stack s)
{ 
  return s->topo == NULL; 
}

void 
stackPush(Stack s, Item conteudo)
{ 
  Link p = (Link) mallocSafe(sizeof *p);
  p->conteudo = conteudo;
  p->prox = s->topo;
  s->topo = p;
}

Item 
stackPop(Stack s)
{ 
  Link p = s->topo;
  Item conteudo;

  if (p == NULL) /* stackempty() */
    {
      fprintf(stderr,"Putz, voce nao sabe o que esta fazendo!\n");
      exit(-1);
    }
  /* tudo bem, a pilha nao esta vazia... */
  conteudo = p->conteudo;
  s->topo = p->prox;
  free(p);
  return conteudo;  
}

Item
stackTop(Stack s)
{
  if (s->topo == NULL) /* stackempty() */
    {
      fprintf(stderr,"Putz, voce nao sabe o que esta fazendo!\n");
      exit(-1);
    }

  /* tudo bem, a pilha nao esta vazia... */
  return  s->topo->conteudo;
}

void 
stackFree(Stack s)
{
  while (s->topo != NULL) 
    {
      Link p = s->topo;
      s->topo = s->topo->prox;
      free(p);
    }

  free(s);
}


void
stackDump(Stack s)
{
  Link p = s->topo;
  fprintf(stdout, "pilha:");
  if (p == NULL) fprintf(stdout, "vazia.");
  while (p != NULL)
    {
      fprintf(stdout," %c", p->conteudo);
      p = p->prox;
    }
  fprintf(stdout,"\n");
}


static void *
mallocSafe (unsigned int n) 
{
  void *p;

  p = malloc(n);
  if (p == NULL)
    {
      fprintf(stderr,"stack: malloc de %u bytes falhou.\n", n);
      exit (-1);
    }
  return p;
}
