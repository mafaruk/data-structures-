#include<stdio.h>
#include<stdlib.h>
#define  MAX 10
struct queue
{
  int rear;
  int front;
  int* arr;
};
void enqueue(struct queue *q, int val);
int dequeue(struct queue *q);
int isEmpty(struct queue *q);
int isFull(struct queue *q);
void print(struct queue *q);
int main()
{
  struct queue q;
  q.rear = q.front = -1;
  q.arr = (int *)malloc(MAX * sizeof(int));
  enqueue(&q, 12);
  enqueue(&q, 15);
  dequeue(&q);
  dequeue(&q);
  dequeue(&q);
  print(&q);
}
void enqueue(struct queue *q, int val)
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
int dequeue(struct queue *q)
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
