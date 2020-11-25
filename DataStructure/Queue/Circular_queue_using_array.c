#include<stdio.h>
#include<stdlib.h>
#define  MAX 10
typedef struct queue
{
  int rear;
  int front;
  int* arr;
} cir_que;
void cir_enqueue(cir_que *q, int val);
int cir_dequeue(cir_que *q);
int isFull(cir_que *q);
int isEmpty(cir_que *q);
void print(cir_que *q);
int main()
{
  cir_que cq;
  cq.rear = cq.front =-1;
  cq.arr = (int *)malloc(MAX * sizeof(int));
  cir_enqueue(&cq, 12);
  cir_enqueue(&cq, 15);
  cir_enqueue(&cq, 13);
  // cir_enqueue(&cq, 14);
  // cir_enqueue(&cq, 10);
  // cir_enqueue(&cq, 9);
  cir_dequeue(&cq);
  cir_dequeue(&cq);
  cir_dequeue(&cq);
  cir_dequeue(&cq);
  print(&cq);
}

void cir_enqueue(cir_que *q, int val)
{
  if(isFull(q))
  {
    printf("Queue is Full\n" );
  }
  else
  {
      q->rear = q->rear +1;
      q->arr[q->rear] = val;
  }
}

int cir_dequeue(cir_que *q)
{
  int a = -1;
  if(isEmpty(q))
  {
    printf("Queue is Empty\n" );
  }
  else
  {
      q->front = (q->front+1)%MAX;
      a = q->arr[q->front] = a;
  }
  return a;
}

int isFull(cir_que *q)
{
    if((q->rear+1)%MAX == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(cir_que *q)
{
    if(q->front == q->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void  print(cir_que *q)
{
  for (int i = q->front +1;  i <=q->rear;  i++)
   {
    printf("%d\n", q->arr[i]);
  }
}
