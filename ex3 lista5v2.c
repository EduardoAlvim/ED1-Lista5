#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Examine a express�o matem�tica:
 7-(( X *((X + Y) / (J - 3)) + Y) / (4 � 2.5))
Queremos garantir que os par�nteses estejam corretamente agrupados, ou seja,
desejamos verificar se:
a) Existe um n�mero igual de par�nteses esquerdos e direitos.
b) Todo par�ntese da direita est� precedido por um par�ntese da esquerda
correspondente.
Express�es como ((A + B) ou A + B(violam o crit�rio l, e express�es como:
)A+B(-C ou (A+B))-(C+D violam o crit�rio 2.
Fa�a um algoritmo que teste a validade de uma express�o matem�tica que utiliza
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
