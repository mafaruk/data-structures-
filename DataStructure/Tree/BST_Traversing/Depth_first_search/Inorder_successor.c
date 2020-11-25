#include <stdio.h>
#include <stdlib.h>
typedef struct node{
  int data;
  struct node*  right;
  struct node* left;
} node;

node* insert(node *, int val);
node* getNewNode(int);
int inorder(node *);
int inorderSuccessor(node *, int);
node* findMin(node *);
int main(int argc, char const *argv[]) {
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
    int val = 4;
    printf(" inorder Successor of %d is %d\n", val, inorderSuccessor(root, val));
    return 0;
}
node *insert(node *root, int val){
  if(root == NULL){
    root  = getNewNode(val);
  }
  else if(val <= root->data){
    root->left = insert(root->left, val);
  }
  else if(val >root->data){
    root->right = insert(root->right, val);
  }
  return root;
}

int inorder(node * root){
  if(root == NULL){
    return 0;
  }
  inorder(root->left);
  printf("%d\n",root->data );
  inorder(root->right);
}

node *getNewNode(int val){
  node *rt = (node *)malloc(sizeof(node));
  rt->data = val;
  rt->right = rt->left =NULL;
  return rt;
}

int inorderSuccessor(node *root, int val){
  node *temp = root;
  if(temp==NULL){
    return 0;
  }
  if(val == temp->data){
    if(temp->right !=NULL){
      return findMin(temp->right)->data;
    }
    else{
      node *Successor = NULL;
      node *ancestor = root;
      while (ancestor != temp) {
        if(temp->data < ancestor->data){
          Successor = ancestor;
          ancestor = ancestor->left;
        }
        else{
          ancestor = ancestor->right;
        }
        return Successor->data;
      }
    }
  }
  else if(val<=temp->data)
  {
    return inorderSuccessor(temp->left, val);
  }
  else if(val>temp->data)
  {
    return inorderSuccessor(temp->right, val);
  }
}

node* findMin(node * root){
  if(root->left== NULL){
    return root;
  }
  else{
     return findMin(root->left);
  }

}
