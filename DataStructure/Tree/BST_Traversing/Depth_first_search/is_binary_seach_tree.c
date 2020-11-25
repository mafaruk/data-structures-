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

node *getNewNode(int val);
node *insert(node *,int val);
int search(node *,int val);
int remove();
void inorder(node *);
void preorder(node *);
void postorder(node *);
int btsUtil(node *, int , int);
int isBST(node *);
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
  if(isBST(root)){
    printf("Binary Srach Tree\n");
  }
  else{
    printf("Not Binary Srach Tree\n");
  }
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

/*
                        15
            10                        20
    8             12            17            25
4     NULL   NULL     NULL  NULL   NULL  NULL    29

Inorder 4 8 10 12 15 17 20 25 29
preorder 15 10 8 4 12 20 17 25 29
postorder 4 8 12 10 17 29 25 20 15
*/

int btsUtil(node *root, int minVal,int maxVal){
  if(root == NULL){
    return 1;
  }
  if(root->data>minVal && root->data < maxVal){
    btsUtil(root->left, minVal, root->data);
    btsUtil(root->right,root->data, maxVal);
    return 1;
  }
  else{
    return 0;
  }
}

int isBST(node *root){
  return btsUtil(root, INT_MIN, INT_MAX);
}
