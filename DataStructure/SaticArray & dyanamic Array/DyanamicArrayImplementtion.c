#include<stdio.h>
int* newDyanArray(int n, int* oldArr);
int newArr[];
int main(){
	int n = 5;
	int capacity = 0;
	int a[n];
	int* b;
	for(int i =0;i<n;i++){
		a[i] = i;
		capacity++;
		if(capacity==n){
			b = newDyanArray(n,a);
		}
	}
	for(int i =0;i<10;i++){
		printf("%d  ", *(b+i));
	}
	
	
	
	
}
int* newDyanArray(int n, int* oldArr){
	newArr[n*2];
	for(int i = 0; i<n; i++){
		newArr[i] = *(oldArr + i);
		//printf("%d  ", newArr[i]);
	}
	for(int i = n; i<n*2; i++){
		newArr[i] = i;
	}
	return newArr;
}
