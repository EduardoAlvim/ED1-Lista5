#include <stdio.h>
#include <stdlib.h>

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
char desempilha(struct stack *pilha);

void main()
{
    struct stack p;
    p.topo=-1;
    char exp[50],c;
    int cont=0;
    printf("\nDigite sua expressao matematica: ");
    gets(exp);
    for(int i=0; i<sizeof(exp); i++)
    {
        empilha(exp[i],&p);
    }
    for(int i=0; i<sizeof(exp); i++)
    {
        c=desempilha(&p);
        if(c == '(')
        {
            cont++;
        }
        else if(c == ')')
        {
            cont--;
        }

    }
    if(cont==0){
        printf("\nA expressao e valida");
    }
    else{
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
char desempilha(struct stack *pilha)
{
    char x;
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
