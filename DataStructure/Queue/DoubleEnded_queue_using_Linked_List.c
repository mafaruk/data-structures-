#include<stdio.h>
#include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
} node;
node *f;
node *r;
void enqueueRear(int val);
int dequeueFront();
void enqueueFront(int val);
int dequeueRear();
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
  enqueueRear(5);
  enqueueFront(2);
  enqueueFront(12);
  enqueueRear(9);
  print();
  printf("%d dequeue from Queue\n", dequeueRear());
  printf("%d dequeue from Queue\n", dequeueFront());
  print();
  return 0;
}
void enqueueRear(int val) {
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
      n->data;
    }
    else{
      r->next = n;
      r = n;
    }
  }
}

void enqueueFront(int val) {
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
      n->next = f;
      f = n;
    }
  }
}


int dequeueFront() {
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

int dequeueRear() {
  int val = -1;
  node *temp = f;
  node *preNode;
  if(isEmpty()){
    return 0;
  }
  else{
    while (temp->next !=NULL) {
      preNode = temp;
      temp = temp->next;
    }
    preNode->next= NULL;
    val = temp->data;
    r = preNode;
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
