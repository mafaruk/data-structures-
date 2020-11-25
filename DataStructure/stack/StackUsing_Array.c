#include<stdio.h>
#define MAX 10
struct stack{
	int data[MAX];
	int top;
}s;
void intit(struct stack *s);
void push(struct stack *s, int val);
int pop(struct stack *s);
void print(struct stack *s);
int main(){
	push(&s,10);
	push(&s,2);
	push(&s,15);
	push(&s,1);
	print(&s);
	printf("\n\n");
	printf("%d poped out of stack",pop(&s));
	print(&s);
	printf("\n\n");
	printf("%d poped out of stack",pop(&s));
	printf("\n\n");
	print(&s);
	
}
void intit(struct stack * s){
	s->top = -1;
}
void push(struct stack *s, int val){
	if(s->top == MAX-1){
		printf("Stack is full");
	}
	else{
		s->top++;
		s->data[s->top] = val;
	}
}
int pop(struct stack *s){
	if(s->top== -1){
		printf("Stack is empty");
	}
	int data = s->data[s->top];
	s->data[s->top]  = NULL;
	s->top--;
	return data;
}
void print(struct stack *s){
	int i=MAX-1;
	while(i!=0){
		printf("%d\n",s->data[i]);
		i--;
	}
}
