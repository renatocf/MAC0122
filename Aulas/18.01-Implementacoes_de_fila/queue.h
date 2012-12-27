/* 
 * queue.h
 * INTERFACE: Funções para manipular a fila
 * 
 */

void queueInit(int);
int queueEmpty();
void queuePut();
Item queueGet();
void queueFree();
