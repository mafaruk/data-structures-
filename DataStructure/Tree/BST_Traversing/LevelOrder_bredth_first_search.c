#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//tree
typedef struct node
{
  int data;
  struct node *right;
  struct node *left;
} node;
// Queue
typedef struct Queue{
  struct node *data;
  struct Queue *next;
} que;
que *r;
que *f;

node *getNewNode(int val);
node *insert(node *,int val);
int search(node *,int val);
int remove();
void enqueue(node *);
node* dequeue();
void BFS_traverse(node *);
int main(int argc, char const *argv[])
{
  node *root;
  root = NULL;
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 12);
  root = insert(root, 8);
  root = insert(root, 20);
  root = insert(root, 17);
  root = insert(root, 25);
  root = insert(root, 29);
  root = insert(root, 4);
  BFS_traverse(root);

}

node* insert(node *rt,int val)
{
  if(rt == NULL)
  {
    rt  = getNewNode(val);
  }
  else
  {
    if(val <= rt->data)
    {
      rt->left = insert(rt->left, val);
    }
    else if(val > rt->data)
    {
      rt->right = insert(rt->right, val);
    }
  }
  return rt;
}

int search(node *rt, int val)
{
  node *temp = rt;
  if(temp == NULL){
    return 0;
  }
  else{
    if(temp->data == val)
    {
      return 1;
    }
    else if(val <= temp->data){
      search(temp->left, val);
    }
    else if(val > temp->data){
      search(temp->right, val);
    }
  }
}

node *getNewNode(int val)
{
  node *n = (node *)malloc(sizeof(node));
  n->data = val;
  n->right = n->left = NULL;
  return n;
}

void enqueue(node *add){
  que *new = (que *)malloc(sizeof(que *));
  if(new==NULL){
    printf("Que is Full\n");
  }
  else {
    new->data = add;
    new->next = NULL;
    if(r==NULL){ ///queue is empty first node in queue
      f=r=new;
    }
    else{
      r->next = new;
      r = new;
    }
  }
}

node* dequeue(){
  node *val;
  if(f==NULL){
    printf("queue is empty\n" );
    return 0;
  }
  else{
    que *temp = f;
    f = f->next;
    val = temp->data;
    free(temp);
  }
  return val;
}

void BFS_traverse(node *rt){
  if(rt == NULL){
    return;
  }
  else{
    node *temp = rt;
    enqueue(temp);
    while(temp!=NULL){
      temp = f->data;
      printf("%d\n",temp->data );
      if(temp->left != NULL){
        enqueue(temp->left);
      }
      if(temp->right != NULL){
        enqueue(temp->right);
      }
      dequeue();
    }
  }
}
