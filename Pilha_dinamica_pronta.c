#include<stdio.h>
#include<stdlib.h>

typedef struct NodeItem{
    int io;
    struct NodeItem *px;
}node;

typedef struct{
    node *top;
}stack;

void newStack(stack *p);
int top(stack *p);
void push(stack *p, int valor);
int pop(stack *p);
int isEmpty(stack *p);
node *newNode(int valor);

int main(){
    
    return 0;
}

node *newNode(int valor){
    node *nd = (node *)malloc(sizeof(node));
    nd -> io = valor;
    nd -> px = NULL;
    return nd;
}

void newStack(stack *p){
    p -> top = NULL;
}

int isEmpty(stack *p){
    return p -> top == NULL;
}

int top(stack *p){
    if(isEmpty(p)){
        printf("Error: STACK UNDERFLOW");
        exit(0);
    }else{
        return p -> top -> io;
    }
}

void push(stack *p, int valor){
    node *n = newNode(valor);
    n -> px = p -> top;
    p -> top = n;
}

int pop(stack *p){
    node *n;
    int i;
    i = top(p);
    p -> top = n -> px;
    free(n);
    return i;
}