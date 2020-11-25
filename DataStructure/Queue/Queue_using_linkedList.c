#include<stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
} node;
node *f;
node *r;
void enqueue(int val);
int dequeue();
int isFull();
int isEmpty();
void print() {
  node *temp = f;
  while (temp !=NULL) {
    printf("%d\n",temp->data );
    temp = temp->next;
  }
}
int main(int argc, char const *argv[]) {
  enqueue(5);
  enqueue(2);
  enqueue(12);
  enqueue(9);
  print();
  printf("%d dequeue from Queue\n", dequeue());
  print();
  return 0;
}
void enqueue(int val) {
  node *n = (node *)malloc(sizeof(node));
  if (isFull(n)) {
    printf("Queue is full\n");
  }
  else {
    n->data = val;
    n->next = NULL;
    if (isEmpty()) {
      printf("Queue is empty\n");
      f = r = n;
    }
    else{
      r->next = n;
      r = n;
    }
  }
}

int dequeue() {
  int val = -1;
  node *temp = f;
  if(isEmpty()){
    return 0;
  }
  else{
    f = f->next;
    val = temp->data;
    free(temp);
  }
  return val;
}

int isFull(node *n){
  if (n == NULL) {
    return 1;
  } else {
    return 0;
  }
}

int isEmpty(){
  if (f==NULL) {
    return 1;
  } else {
    return 0;
  }
}
