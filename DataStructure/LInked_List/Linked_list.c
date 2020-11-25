#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
void insertAtNpos(int, int );
void insert(int);
void insertAtBeg(int);
void delete();
void deleteAtBeg();
struct node *head;
void print(struct node *head){
	struct node *ptrTemp = head;

	if(ptrTemp == NULL){
		printf("List is empty\n");
	}
	else{
		while(ptrTemp!=NULL){
				printf("  |%d|%d|-->", ptrTemp->data,ptrTemp->link);
				ptrTemp = ptrTemp->link;
		}
	}
	printf("\n");

}
int main(){
	insert(5);
	insert(4);
	insert(3);
	print(head);
	insertAtBeg(6);
	print(head);
	insertAtNpos(1,0);
	print(head);
	insertAtNpos(2,4);
	print(head);
	insertAtNpos(10,4);
	print(head);
	delete();
	print(head);
	deleteAtBeg();
	print(head);
}

void delete(){
	struct node *ptrTemp = head;
	struct node *prevNode;
	if(ptrTemp == NULL){
		printf("List is empty \n\n");
	}
	else{
		while(ptrTemp->link!=NULL){
			prevNode = ptrTemp;
			ptrTemp = ptrTemp->link;	
		}
		free(ptrTemp);
		prevNode->link = NULL;
	}
}

void deleteAtBeg(){
	struct node *ptrTemp = head;
	if(ptrTemp == NULL){
		printf("List is empty \n\n");
	}
	else{
		head = ptrTemp->link;
		free(ptrTemp);
	}
}

void insert(int data){
	struct node *ptrTemp = head;
	if(ptrTemp == NULL){
		printf("List is empty adding element at 0st pos\n\n");
		ptrTemp = (struct node*)malloc(sizeof(struct node));
		ptrTemp->data = data;
		ptrTemp->link = NULL;
		head = ptrTemp;
	}
	else{
		while(ptrTemp->link!=NULL){
			ptrTemp = ptrTemp->link;
		}
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->link=NULL;
		ptrTemp->link = temp;
	}
}

void insertAtBeg(int data){
	struct node *ptrTemp = head;
	if(ptrTemp == NULL){
		printf("List is empty adding element at 0st pos\n\n");
		ptrTemp = (struct node*)malloc(sizeof(struct node));
		ptrTemp->data = data;
		ptrTemp->link = NULL;
		head = ptrTemp;
	}
	else{	
		struct node *newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		head = newNode;
		newNode->link = ptrTemp;
	}
}

void insertAtNpos(int data, int pos){
	int temp = 0;
	struct node *ptrTemp = head;
	if(ptrTemp == NULL && pos!=0){
		printf("List is empty, not possible to add element at %d pos\n\n",pos);
	}
	else if(ptrTemp != NULL && pos==0){	
		struct node *newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		head = newNode;
		newNode->link = ptrTemp;
	}
	else if(ptrTemp == NULL &&  pos==0){
		printf("List is empty adding element at 0st pos\n\n");
		ptrTemp = (struct node*)malloc(sizeof(struct node));
		ptrTemp->data = data;
		ptrTemp->link = NULL;
		head = ptrTemp;
	}
	else{
		
		while(temp!=pos){
			temp++;
			if(ptrTemp->link==NULL){
				printf("Can't added element at %d pos ",pos);
				exit(0);
			}
			ptrTemp = ptrTemp->link;
		}
		struct node *temp1 = (struct node*)malloc(sizeof(struct node));
			
			temp1->data=data;
			temp1->link=ptrTemp->link;
			ptrTemp->link = temp1;
	}
}