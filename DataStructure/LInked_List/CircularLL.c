#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head;
void insert(int);
void print(struct node *head){
	struct node *tempNode = head;
	struct node *endNode;
	while(endNode!=head){
		printf("add=%d|%d|%d ",tempNode,tempNode->data,tempNode->link);
		tempNode = tempNode->link;
		endNode = tempNode;
	}
	printf("\n");
}
void insertAtPos(int val, int pos);
void insertAtBeg(int val);
int main(){
	insert(3);
	insert(2);
	insert(6);
	print(head);
	insertAtPos(2,1);
	print(head);
	insertAtBeg(1);
	print(head);
	return 0;
}

void insert(int val){
	struct node *tempNode = head;
	if(tempNode==NULL){
		printf("List is empty\n");
		tempNode = (struct node*) malloc(sizeof(struct node));
		tempNode->data = val;
		head = tempNode;
		tempNode->link = head;
	}
	else{
		while(tempNode->link!=head){
			tempNode  = tempNode->link;
		}
		struct node *newNode = (struct node*) malloc(sizeof(struct node));
		newNode->data = val;
		newNode->link = head;
		tempNode->link = newNode;
	}
}
void insertAtPos(int val, int pos){
	struct node *tempNode = head;
	if(tempNode==NULL){
		printf("List is empty\n");
	}
	else{
		for(int i = 0; i<pos;i++){
			tempNode  = tempNode->link;
			if(tempNode==head){
				printf("Less element in list\n");
			}
		}
		struct node *newNode = (struct node*) malloc(sizeof(struct node));
		newNode->data = val;
		newNode->link = tempNode->link;
		tempNode->link = newNode;
		
	}
}
void insertAtBeg(int val){
	struct node *tempNode = head;
	struct node *endNode;
	if(tempNode==NULL){
		printf("List is empty\n");
		tempNode = (struct node*) malloc(sizeof(struct node));
		tempNode->data = val;
		head = tempNode;
		tempNode->link = head;
	}
	else{
		struct node *newNode = (struct node*) malloc(sizeof(struct node));
		newNode->data = val;
		head = newNode;
		newNode->link = tempNode;
		endNode = tempNode;
		while(endNode->link!=tempNode){
			endNode = endNode->link;
		}
		endNode->link = head;
		
	}
}
