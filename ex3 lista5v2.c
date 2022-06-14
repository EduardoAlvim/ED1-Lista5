#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Examine a expressão matemática:
 7-(( X *((X + Y) / (J - 3)) + Y) / (4 – 2.5))
Queremos garantir que os parênteses estejam corretamente agrupados, ou seja,
desejamos verificar se:
a) Existe um número igual de parênteses esquerdos e direitos.
b) Todo parêntese da direita está precedido por um parêntese da esquerda
correspondente.
Expressões como ((A + B) ou A + B(violam o critério l, e expressões como:
)A+B(-C ou (A+B))-(C+D violam o critério 2.
Faça um algoritmo que teste a validade de uma expressão matemática que utiliza
parenteses */

struct stack
{
    int topo;
    char dados[50];
};

void empilha (int x, struct stack *pilha);
int desempilha(struct stack *pilha);

void main()
{
    struct stack p;
    p.topo=-1;
    char exp[50],c;
    int y=0,i=0;
    printf("\nDigite sua expressao matematica: ");
    gets(exp);
    while(y!=-1 && i <= strlen(exp))
    {
        c=exp[i];
        if(c == '(')
        {
            empilha(c,&p);
        }
        else if(c == ')')
        {
            y=desempilha(&p);
        }
        i++;
    }
    if(p.topo==-1 && y==0)
    {
        printf("\nExpressao valida");
    }
    else
    {
        printf("\nExpressao invalida");
    }
}

void empilha (int x, struct stack *pilha)
{
    if (pilha->topo == 49)
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
        return 0;
    }
}
