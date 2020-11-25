#include<stdio.h>
#include <stdlib.h>
#define MAX 100

struct stack{
	char data;
	struct stack *next; 
};
void push(char val);
int pop();
void print();
void delstack(struct stack *);
static struct stack *top;
int main(){
	char expresion[MAX]; 
	scanf("%s",expresion);
	int i = 0;
	while(expresion[i] != '\0'){
		if(expresion[i]=='(')
		{
			//printf("%c",expresion[i]);
			push(expresion[i]);
			//print();
			i++;
			
		}
		else if (expresion[i]== ')' ){
			//printf("%c",expresion[i]);
			i++;
			pop();
			//print();
		}
		else{
			i++;
			continue;
		}
	}
	print();
}
//remeber this as a linkist pointing to previos node
void push( char val){
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
		printf("Unbalanced Expression\n");
		exit(0);
	}
		struct stack *temp  = top;
		item = temp->data;
		top = temp->next;
		free(temp);
		return item;
}
void print(){
	struct stack *temp = top;
	//printf("top updated %d %d\n",top->data,temp->data);
	
	if(top==NULL){
		printf("balanced Expression\n");
	}
	else {
		// while(temp!=NULL){
			// printf("%c\n",temp->data);
			// temp = temp->next;
		// }
		printf("Unbalanced Expression\n");
	}
}
void delstack(struct stack *top){
	while(top!=NULL){
		printf("%d poped out of stack\n",pop());
	}
}
