#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  int data;
  struct node *right;
  struct node *left;
} node;
node *getNewNode(int val);
void insert(int val);
int search(node *,int val);
int remove();
node *root;
int main(int argc, char const *argv[])
{
  insert( 15);
  insert( 10);
  insert( 12);
  if(search(root,15)){
    printf("Found\n" );
  }else{
    printf("Not Found\n" );
  }
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

void insert(int val)
{
  if(root == NULL)
  {
    root  = getNewNode(val);
  }
  else
  {
    node *temp = root;
    while (temp!= NULL)
    {
      if(val <= temp->data)
      {
        if (temp->left == NULL)
        {
          temp->left = getNewNode(val);
          //printf("left %d \n",temp->left->data);
          break;
        }
        else
        {
          temp = temp->left;
        }
      }
      else if(val > temp->data)
      {
        if (temp->right == NULL)
        {
          temp->right = getNewNode(val);
          //printf("Right %d \n",temp->right->data);
          break;
        }
        else
        {
          temp = temp->right;
        }
      }
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
