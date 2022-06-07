#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int topo;
    int dados[20];
};
void empilha (int x, struct stack *pilha);
int desempilha(struct stack *pilha);

void main()
{
    struct stack p1;
    struct stack p2;
    struct stack p3;
    p1.topo=-1;
    p2.topo=-1;
    p3.topo=-1;
    int v, x;
    for(int i=0; i<20; i++)
    {
        printf("\nDigite o valor a ser empilhado: ");
        scanf("%d",&v);
        empilha(v, &p1);
    }
    for(int i=0; i<20; i++)
    {
        x=desempilha(&p1);
        if(x<100)
        {
            empilha(x,&p2);
        }
        else
        {
            empilha(x,&p3);
        }
    }
    printf("\nPilha 2:");
    for(int i=0; i<=p2.topo; i++){
        printf("\n %d",p2.dados[i]);
    }
    printf("\nPilha 3:");
    for(int i=0; i<=p3.topo; i++){
        printf("\n %d",p3.dados[i]);
    }
}

void empilha (int x, struct stack *pilha)
{
    if (pilha->topo == 19)
    {
        /* pilha cheia*/printf("%s", "stack overflow");
    }
    else
    {
        pilha->topo = pilha->topo +1;
        pilha->dados[pilha->topo]=x;
    }
}
int desempilha(struct stack *pilha)
{
    int x;
    if (pilha->topo == -1)
    {
        /* pilha vazia*/printf("%s", "stack underflow");
        return(-1);
    }
    else
    {
        x= pilha->dados[pilha->topo];
        pilha->topo = pilha->topo - 1;
        return x;
    }
}


