#include<stdio.h>
#include<stdlib.h>

typedef struct NodeItem {
  int info;
  struct NodeItem *prox;
  struct NodeItem *prev;  
} node;

typedef struct {
  node *first;
  node *last;
} list;

list *newList();
node *newNode(int value);
node *addNodeInit(list *l, int value);
node *addNodeMid(list *l, node *ant, int value);
node *addNodeEnd(list *l, int value);
node *findNode(list *l, int value);
void delNode(list *l, int value);
int isEmpty(list *l);
int length(list *l);
void showList(list *l);

int main(){
    list *l;
    l = newList();

    return 0;
}

list *newList(){
    list *l = (node *)malloc(sizeof(node));
    l -> first = NULL;
    l -> last = NULL;
    return l;
}

node *newNode(int value){
    node *n = (node *)malloc(sizeof(node));
    n -> info = value;
    n -> prev = NULL;
    n -> prox = NULL;
    return n;
}

node *addNodeInit(list *l, int value) {
  node *n = newNode(value);
  if (isEmpty(l)) {
    l->first = n;
    l->last = n;
  } else {
    n->prox = l->first;
    l->first->prev = n;
    l->first = n;
  }

  return n;
}

node *addNodeMid(list *l, node *ant, int value) {
  node *n, *prox;

  if (ant == NULL) {
    n = addNodeInit(l, value);
  } else if(ant == l->last) {
    n = addNodeEnd(l, value);
  } else {
    n = newNode(value);
    prox = ant->prox;
    n->prev = ant;
    n->prox = prox;
    ant->prox = n;
    prox->prev = n;
  }

  return n;
}

node *addNodeEnd(list *l, int value) {
  node *n = newNode(value);
  if (isEmpty(l)) {
    l->first = n;
    l->last = n;
  } else {
    n->prev = l->last;
    l->last->prox = n;
    l->last = n;
  }

  return n;
}

node *findNode(list *l, int value){
    node *n = l -> first;
    while(n != NULL && n -> info != value){
        n = n -> prox;
    }
    return n;
}

void delNode(list *l, int value) {
  node *n, *prev, *next;
  n = findNode(l, value);
  if (n != NULL) {
    prev = n->prev;
    next = n->prox;

    if (n == l->first) {
      l->first = next;
    }
    if (n == l->last) {
      l->last = prev;
    }

    if (prev != NULL){
      prev->prox = next;
    }
    if (next != NULL) {
      next->prev = prev;
    }

    free(n);
  }
}

void showList(list *l) {
  node *n;
  if (isEmpty(l)) {
    printf("\nA lista esta vazia");
  } else {
    printf("\nA lista possui %i elemento(s), sendo: ", length(l));
    n = l->first;
    while(n != NULL) {
      if (n->prev != NULL && n->prox != NULL)
        printf("\n=> %i [Ant: %i, Prox: %i]", n->info, n->prev->info, n->prox->info);
      else if (n->prev != NULL)
        printf("\n=> %d [Ant: %d, Prox: NULL]", n->info, n->prev->info);
      else if (n->prox != NULL)
        printf("\n=> %d [Ant: NULL, Prox: %d]", n->info, n->prox->info);
      else
        printf("\n=> %d [Ant: NULL, Prox: NULL]", n->info);
      n = n->prox;
    }
    printf("\n");
  }
}

int length(list *l) {
  int i=0;
  node *n = l->first;
  while(n != NULL) {
    n = n->prox;
    i++;
  }
  return i;
}

int isEmpty(list *l) {
  return l->first == NULL;
}