#include<stdio.h>
#include <stdlib.h>
#define MAX 10
struct stack{
	int data;
	struct stack *next; 
};
void push( int val);
int pop();
void print(struct stack *);
void delstack(struct stack *);
static struct stack *top;
int main(){
		
	push(10);
	push(2);
	push(15);
	push(1);
	print(top);
	printf("\n\n");
	printf("%d poped out of stack\n",pop());
	print(top);
	printf("\n\n");
	printf("%d poped out of stack\n",pop());
	printf("\n\n");
	print(top);
	delstack(top);
	print(top);
	
}
//remeber this as a linkist pointing to previos node
void push( int val){
	//printf("in push \n");
	
	if(top==NULL){
		top  = (struct stack *)malloc(sizeof(struct stack));
		top->next= NULL;
		top->data= val;
		//printf("in null;  \n");
	}
	else{
		struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
		temp->data = val;
		temp->next = top;///initailly top is null
		top = temp;
	}
	//printf("top updated %d \n",top->data);
	//above statement will create structure like null<--|add|data|<--|add|data|(this node is at top)
}
int pop(){
	int item = 0;
	if(top==NULL){
		printf("Stack is empty\n");
		exit(0);
	}
	
		struct stack *temp  = top;
		item = temp->data;
		top = temp->next;
		free(temp);
		return item;
}
void print(struct stack *top){
	struct stack *temp = top;
	//printf("top updated %d %d\n",top->data,temp->data);
	while(temp!=NULL){
		printf("%d|%d|v\n",temp->data,temp->next);
		temp = temp->next;
	}
	if(top==NULL){
		printf("Stack is empty\n");
	}
}
void delstack(struct stack *top){
	while(top!=NULL){
		printf("%d poped out of stack\n",pop());
	}
}
