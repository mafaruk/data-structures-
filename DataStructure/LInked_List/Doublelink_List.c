#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
void deleteFromNpos(int);
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
				printf(" |%d|%d|%d|-->",ptrTemp->prev,ptrTemp->data,ptrTemp->next);
				ptrTemp = ptrTemp->next;
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
	deleteFromNpos(2);
	print(head);
}

void delete(){
	struct node *ptrTemp = head;
	struct node *prevNode;
	if(ptrTemp == NULL){
		printf("List is empty \n\n");
	}
	else{
		while(ptrTemp->next!=NULL){
			prevNode = ptrTemp;
			ptrTemp = ptrTemp->next;	
		}
		free(ptrTemp);
		prevNode->next = NULL;
	}
}

void deleteAtBeg(){
	struct node *ptrTemp = head;
	if(ptrTemp == NULL){
		printf("List is empty \n\n");
	}
	else{
		head = ptrTemp->next;
		head->prev = NULL;
		free(ptrTemp);
	}
}

void deleteFromNpos(int pos){
	struct node *ptrTemp = head;
	struct node *prevNode,*nextNode;
	for(int i =0; i<pos; i++){
		prevNode = ptrTemp;
		ptrTemp = ptrTemp->next;
		if(ptrTemp==NULL){
			printf("No element at %d pos ",pos);
				exit(0);
		}
	}
	if(ptrTemp->next==NULL){
		prevNode->next = NULL;
		free(ptrTemp);
	}
	else{
		nextNode = ptrTemp->next;
		prevNode->next = nextNode;
		nextNode->prev = prevNode;
		free(ptrTemp);
	}
	
}
void insert(int data){
	struct node *ptrTemp = head;
	if(ptrTemp == NULL){
		printf("List is empty adding element at 0st pos\n\n");
		ptrTemp = (struct node*)malloc(sizeof(struct node));
		ptrTemp->data = data;
		ptrTemp->next = NULL;
		ptrTemp->prev = NULL;
		head = ptrTemp;
	}
	else{
		while(ptrTemp->next!=NULL){
			ptrTemp = ptrTemp->next;
		}
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->next=NULL;
		temp->prev=ptrTemp;
		ptrTemp->next = temp;
	}
}

void insertAtBeg(int data){
	struct node *ptrTemp = head;
	if(ptrTemp == NULL){
		printf("List is empty adding element at 0st pos\n\n");
		ptrTemp = (struct node*)malloc(sizeof(struct node));
		ptrTemp->data = data;
		ptrTemp->next = NULL;
		ptrTemp->prev = NULL;
		head = ptrTemp;
	}
	else{	
		struct node *newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		ptrTemp->prev = newNode;
		head = newNode;
		newNode->next = ptrTemp;
		newNode->prev = NULL;
	}
}

void insertAtNpos(int data, int pos){
	
	struct node *ptrTemp = head;
	if(ptrTemp == NULL && pos!=0){
		printf("List is empty, not possible to add element at %d pos\n\n",pos);
	}
	else if(ptrTemp != NULL && pos==0){	///insertion at the front
		struct node *newNode = (struct node*)malloc(sizeof(struct node));
		newNode->data = data;
		ptrTemp->prev = newNode;
		head = newNode;
		newNode->next = ptrTemp;
		newNode->prev = NULL;
	}
	else if(ptrTemp == NULL &&  pos==0){//inserting fisrt element in the list
		printf("List is empty adding element at 0st pos\n\n");
		ptrTemp = (struct node*)malloc(sizeof(struct node));
		ptrTemp->data = data;
		ptrTemp->next = NULL;
		ptrTemp->prev = NULL;
		head = ptrTemp;
	}
	else{//insert after Nth position 
		
		for(int i = 0; i<pos; i++){
			ptrTemp = ptrTemp->next;
			if(ptrTemp==NULL){
				printf("Can't added element at %d pos ",pos);
				exit(0);
			}
			
		}	
		struct node *temp1 = (struct node*)malloc(sizeof(struct node));
		struct node *prevNode; 
		// prevNode = ptrTemp->next;
		temp1->data=data;
		temp1->prev = ptrTemp;
		
		if(ptrTemp->next == NULL){
			ptrTemp->next = temp1;
			temp1->next = NULL;
		}
		else{
			prevNode = ptrTemp->next;
			ptrTemp->next = temp1;
			prevNode->prev = temp1; 
			temp1->next = prevNode;
		}
	}	
}