#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NodeItem{
    char msg;
    struct NodeItem *px;
}node;

typedef struct{
    node *top;
}stack;

void newStack(stack *p);
char top(stack *p);
void push(stack *p, char valor);
char pop(stack *p);
int isEmpty(stack *p);
node *newNode(char valor);

int main(){
    stack s;
    
    return 0;
}

node *newNode(char valor){
    node *nd = (node *)malloc(sizeof(node));
    nd -> msg = valor;
    nd -> px = NULL;
    return nd;
}

void newStack(stack *p){
    p -> top = NULL;
}

int isEmpty(stack *p){
    return p -> top == NULL;
}

char top(stack *p){
    if(isEmpty(p)){
        printf("Error: STACK UNDERFLOW");
        exit(0);
    }else{
        return p -> top -> msg;
    }
}

void push(stack *p, char valor){
    node *nd = newNode(valor);
    nd -> px = p -> top;
    p -> top = nd;
}

char pop(stack *p){
    node *n;
    char i;
    i = top(p);
    p -> top = n -> px;
    free(n);
    return i;
}