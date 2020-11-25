#include<stdio.h>
void bubbleSort(int *, int);
int main(){
	int n = 5;
	int a[] = {10,9,8,7,5};
	bubbleSort(a,n);
	for(int j = 0; j<n; j++){
		printf("%d ",a[j]);
	}
}
void bubbleSort(int *a, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}
