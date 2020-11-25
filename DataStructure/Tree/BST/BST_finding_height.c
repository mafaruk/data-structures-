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
node *insert(node *,int val);
int search(node *,int val);
int remove();
int minNode(node *);
int maxNode(node *);
int heightOfTree(node *, int );
int max(int, int);
int main(int argc, char const *argv[])
{
  node *root;
  root = NULL;
  root = insert(root, 15);
  root = insert(root, 10);
  root = insert(root, 12);
  root = insert(root, 20);
  root = insert(root, 8);
  root = insert(root, 22);
  root = insert(root, 27);
  root = insert(root, 29);
  if(search(root,22)){
    printf("Found\n" );
  }else{
    printf("Not Found\n" );
  }
  printf(" minimum node is %d\n", minNode(root));
  printf(" maximum node is %d\n", maxNode(root));
  printf("height of Tree is %d\n",heightOfTree(root, 0));
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

int minNode(node *rt)
{
    node *temp = rt;
    if(temp == NULL)
    {
      printf("tree is empty\n" );
    }
    else if(temp->left==NULL){
      return temp->data;
    }
    else{
      minNode(temp->left);
    }
}

int maxNode(node *rt)
{
  node *temp = rt;
  if(temp == NULL)
  {
    printf("tree is empty\n" );
  }
  else if(temp->right==NULL){
    return temp->data;
  }
  else{
    maxNode(temp->right);
  }
}

int heightOfTree(node *rt,int h)
{
  int ht = h;
  if(rt==NULL){
    return ht-1;
  }
  else{
    return max(heightOfTree(rt->left,ht+1),heightOfTree(rt->right,ht+1));
  }
}

int max(int a, int b){
  if(a<b){
    return b;
  }
  else{
    return a;
  }
}

/**
int heightOfTree(node *rt)
// {
//   if(rt==NULL){
//     return -1;
//   }
//   else{
//     return max(heightOfTree(rt->left),heightOfTree(rt->right))+1;
//   }
// }
call heightOfTree(root); in main and delcare "heightOfTree(node *rt);" if requiered
**/
