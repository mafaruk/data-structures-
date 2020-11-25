#include<stdio.h>
int main (){
 int i = 1, n=32,j;
 while(i<n){
	j = n;
	while(j>0){
		printf(" %d ",j);
		j = j/2; 
	}
	i =2*i;
 }
 printf("ended");
}