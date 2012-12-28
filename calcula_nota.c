#include<stdio.h>

#define min(m,n) ((m) < (n) ? (m) : (n))

float nota_final (float mp, float me);

int main(void)
{
    float notas_prova[3], mp;
    float notas_ep[5], me;
    int i = 0;
    
    /* Média das provas */
    for(i = 1; i < 4; i++)
    {
        printf("Qual a nota da P%d? ", i);
        scanf("%f", &notas_prova[i-1]);
    }
    mp = (1*notas_prova[0] + 2*notas_prova[1] + 2*notas_prova[2])/5;
    printf("A média das provas é %.1f\n", mp);
    
    
    /* Média dos EP's */
    for(i = 1, me = 0; i < 6; i++)
    {
        printf("Qual a nota do EP%d? ", i);
        scanf("%f", &notas_prova[i-1]);
        me += notas_prova[i-1];
    }
    me = (me + notas_prova[4])/6;
    printf("A média dos EP's é %.1f\n", me);
    
    
    /* Média final */
    printf("A nota final é %.1f\n", nota_final(mp, me));
    
    return 0;
}


float nota_final (float mp, float me)
{
    if (mp < 5 || me < 5) return min(mp,me);
    return 0.75*mp + 0.25*me;
} 
