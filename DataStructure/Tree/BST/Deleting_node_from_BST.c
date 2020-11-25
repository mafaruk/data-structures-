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
/*
                        15
            10                        20
    8             12            17            25
4     NULL   NULL     NULL  NULL   NULL  NULL    29

*/
node *getNewNode(int val);
node *insert(node *,int val);
int search(node *,int val);
int remove();
void inorder(node *);
void preorder(node *);
void postorder(node *);
node *deleteNode(node *, int val);
void inorder(node *);
node* findMin(node *root);
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
  inorder(root);
  root = deleteNode(root, 4);
  root = deleteNode(root, 20);
  root = deleteNode(root, 25);
  printf("\nAfter deleting 4,20,25\n");
  inorder(root);
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

node *deleteNode(node *root, int val){
  if(root == NULL){
    return root;
  }
  else if(val < root->data){
    root->left = deleteNode(root->left, val);
  }
  else if(val > root->data){
    root->right = deleteNode(root->right, val);
  }
  else {
    if(root->left == NULL){
      node *temp = root;
      root = temp->right;
      free(temp);
    }
    else if(root->right == NULL){
      node *temp = root;
      root = temp->left;
      free(temp);
    }
    else {
      node *temp = findMin(root->right);
      root->data = temp->data;
      root->right =deleteNode(root->right, temp->data);
    }
  }
  return root;
}

void inorder(node *rt){
  if(rt==NULL){
    return;
  }
    inorder(rt->left);
    printf("%d ",rt->data);
    inorder(rt->right);
    //printf("%d\n",rt->data);
    return;
}

node* findMin(node *root){

      node *temp = root;
      if(temp == NULL)
      {
        printf("tree is empty\n" );
      }
      else if(temp->left==NULL){
        return temp;
      }
      else{
        findMin(temp->left);
      }
      return temp;
}
