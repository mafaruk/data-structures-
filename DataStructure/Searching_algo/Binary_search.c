#include <stdio.h>
int binary_search(int*, int, int, int);
int main(int argc, char const *argv[]) {
  int a[10]= {10,12,15,45,48,312,635,785,852,1000};
  printf("Enter the element you want to search\n");
  int key;
  scanf("%d", &key);
  int lower = 0;
  int upper = sizeof(a)/sizeof(int);
  int i = binary_search(a, lower, upper ,key);
  if(i){
    printf("Found at index %d\n",i);
  }
  else{
    printf("Not Found\n" );
  }
  return 0;
}
int binary_search(int *a, int low, int up, int key) {
  int mid = (up+low)/2;
  if(a[mid]==key){
    return mid;
  }
  else if(a[mid] > key){
    binary_search(a, low, mid, key);
  }
  else if(a[mid] < key){
    binary_search(a,mid,up, key);
  }
  return 0;
}
