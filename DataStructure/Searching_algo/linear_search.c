#include <stdio.h>
int linear_search (int *, int);
int main(int argc, char const *argv[]) {
  int a[10]= {10,12,15,45,48,312,4,635,315};
  printf("Enter the element you want to search\n");
  int key;
  scanf("%d", &key);
  int i = linear_search(a, key);
  if(i){
    printf("Found at index %d\n",i);
  }
  else{
    printf("Not Found\n" );
  }
  return 0;
}
int linear_search(int *a, int key)
{
  for (int i = 0; i < 10; i++) {
    if(*(a+i) == key){
      return i;
    }
  }
  return 0;
}
