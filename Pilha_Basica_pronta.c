#include<stdio.h>
#include<stdlib.h>

#define NUM 500

typedef struct {
    int top;
    int vet[NUM];
}stack;

void newStack(stack *s);
int isEmpty(stack *s);
int isFull(stack *s);
void push(stack *s, int valor);
int pop(stack *s);
int top(stack *s);

int main(){
    stack s;
    newStack(&s);
    return 0;
}

void newStack(stack *s){
    s -> top = -1;
}

int isEmpty(stack *s){
    return s -> top == -1;
}

int isFull(stack *s){
    return s -> top == NUM;
}

void push(stack *s, int valor){
    if (isFull(s)){
        printf("\nStack Overflow!");\
        exit(1);
    }

    s->vet[++s->top] = valor;
}

int pop(stack *s){
    if (isEmpty(s)){
        printf("\nStack Underflow!");
        exit(1);
    }

    return s->vet[s->top--];
}

int top(stack *s){
    if (isEmpty(s)){
        printf("\nStack Underflow!");
        exit(1);
    }

    return s->vet[s->top];
}