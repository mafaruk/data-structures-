#include<stdio.h>
#include <stdlib.h>
#define MAX 100

struct stack{
	char data;
	struct stack *next; 
};
void push(struct stack **,char val);
int pop(struct stack **);
void print(struct stack **);
void delstack(struct stack **);
int main(){
	static struct stack *open, *close;
	print(&open);
	print(&close);
	char expresion[MAX]; 
	scanf("%s",expresion);
	
	for(int i = 0;expresion[i]!='\0';i++){
		switch(expresion[i]){
			case '(': 
				push(&open, expresion[i]);
				push(&close, ')');
				printf("open %c\n",open->data);
				printf("close %c\n",close->data);
				// printf(" open stack \n");
				// print(&open);
				// printf(" Close stack \n");
				// print(&close);
				break;
			case ')': 
				if(close->data == ')'){
					pop(&open);
					pop(&close);
					printf("pop open %c\n",open->data);
					printf("pop close %c\n",close->data);
					// printf(" open stack \n");
					// print(&open);
					// printf(" Close stack \n");
					// print(&close);
				}
				else{
					printf("Unbalanced Expression\n");
					exit(0);
				}
				break;
			case '[': 
				push(&open, expresion[i]);
				push(&close, ']');
				printf("open %c\n",open->data);
				printf("close %c\n",close->data);
				// printf(" open stack \n");
				// print(&open);
				// printf(" Close stack \n");
				// print(&close);
				break;
			case ']': 
				if(close->data == expresion[i]){
					pop(&open);
					pop(&close);
					printf("pop open %c\n",open->data);
					printf("pop close %c\n",close->data);
					// printf(" open stack \n");
					// print(&open);
					// printf(" Close stack \n");
					// print(&close);
				}
				else{
					printf("Unbalanced Expression\n");
					exit(0);
				}
				break;
			case '{': 
				push(&open, expresion[i]);
				push(&close, '}');
				printf(" open %c\n",open->data);
				printf(" close %c\n",close->data);
				// printf(" open stack \n");
				// print(&open);
				// printf(" Close stack \n");
				// print(&close);
				break;
			case '}': 
				if(close->data == expresion[i]){
					printf("pop open %c\n",open->data);
					printf("pop close %c\n",close->data);
					pop(&open);
					pop(&close);
					// printf(" open stack \n");
					// print(&open);
					// printf(" Close stack \n");
					// print(&close);
				}
				else{
					printf("Unbalanced Expression\n");
					exit(0);
				}
				break;
			default: 
			break;
		}
	}
	print(&open);
	print(&close);
}
//remeber this as a linkist pointing to previos node
void push(struct stack **top ,char val){
	//printf("in push \n");
	
	if(top==NULL){
		*top  = (struct stack *)malloc(sizeof(struct stack));
		(*top)->next= NULL;
		(*top)->data= val;
		//printf("in null;  \n");
	}
	else{
		struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
		temp->data = val;
		temp->next = *top;///initailly top is null
		*top = temp;
	}
	//printf("top updated %d \n",top->data);
	//above statement will create structure like null<--|add|data|<--|add|data|(this node is at top)
}
int pop(struct stack **top){
	int item = 0;
	if(*top==NULL){
		printf("Unbalanced Expression\n");
		exit(0);
	}
		struct stack *temp  = *top;
		item = temp->data;
		*top = temp->next;
		free(temp);
		return item;
}
void print(struct stack **top){
	struct stack *temp = *top;
	//printf("top updated %d %d\n",top->data,temp->data);
	while(temp!=NULL){
		printf("%c \n",temp->data);
		temp = temp->next;
	}
	// if(top==NULL){
		// printf("balanced Expression\n");
	// }
	// else {
		// // while(temp!=NULL){
			// // printf("%c\n",temp->data);
			// // temp = temp->next;
		// // }
		// printf("Unbalanced Expression\n");
	// }
}
void delstack(struct stack **top){
	while(*top!=NULL){
		printf("%d poped out of stack\n",pop(top));
	}
}
