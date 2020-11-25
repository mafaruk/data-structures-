#include<stdio.h>
#include<stdlib.h>
#define  MAX 10
struct queue
{
  int rear;
  int front;
  int* arr;
};
void enqueueRear(struct queue *q, int val);
void enqueueFront(struct queue *q, int val);
int dequeueFront(struct queue *q);
int dequeueRear(struct queue *q);
int isEmpty(struct queue *q);
int isFull(struct queue *q);
void print(struct queue *q);
int main()
{
  struct queue q;
  q.rear = q.front = -1;
  q.arr = (int *)malloc(MAX * sizeof(int));
  enqueueRear(&q, 12);
  enqueueRear(&q, 10);
  dequeueFront(&q);
  enqueueFront(&q, 15);
  dequeueFront(&q);
  enqueueFront(&q, 10);
  enqueueRear(&q, 5);
  dequeueRear(&q);
  print(&q);
}

void enqueueRear(struct queue *q, int val)
{
  if(isFull(q))
  {
    printf("queue is full\n");
  }
  else
  {
    q->rear = q->rear + 1;
    q->arr[q->rear] = val;
  }
}

void enqueueFront(struct queue *q, int val){
  if(q->front == -1){
    printf("can not add element from front \n" );
  }
  else{
    q->arr[q->front] = val;
    q->front = q->front - 1;
  }
}

int dequeueFront(struct queue *q)
{
  int a = - 1;
  if(isEmpty(q))
  {
    printf("Queue is Empty\n" );
  }
  else
  {
    q->front = q->front + 1;
    a= q->arr[q->front];
  }
  return a;
}


int dequeueRear(struct queue *q){
  int val = -1;
  if(isEmpty(q)){
    printf("Queue is Empty\n" );
  }
  else{
    val = q->arr[q->rear];
    q->rear = q->rear - 1;
  }
  return val;
}

int isFull(struct queue *q)
{
  if(q->rear == MAX-1){
    return 1;
  }
  else{
    return 0;
  }
}


int isEmpty(struct queue *q)
{
  if(q->rear == q->front){
    return 1;
  }
  else{
    return 0;
  }
}
void print(struct queue *q){
  for(int i = q->front+1; i<=q->rear;i++){
    printf("%d\n",q->arr[i]);
  }
}
