#include <stdio.h>
void selection_sort(int *, int);
int main(int argc, char const *argv[]) {
  int n = 6;
  int  a[] = {2,7,4,3,1,5};
  printf("before sorting\n" );
  for (size_t i = 0; i < n; i++) {
    printf("%d ",a[i]);
  }
  selection_sort(a, n);
  printf("after sorting\n" );
  for (size_t i = 0; i < n; i++) {
    printf("%d ",a[i]);
  }
  return 0;
}

void selection_sort(int *a, int n){

  for (size_t i = 0; i < n-1; i++) {//n-1 cuase at the end remaining element will be already sorted
    int imin =  i;//minimum index
    for (size_t j = i+1; j < n; j++) {//j = i+1 cuase once element is sorted and
                                      //put at appropriate index then we do not need to consider that element in further itration
      if(a[j]< a[imin]){ //comparing each j element with minimum index imin
        //minimum index store minimum number in array so if we found j  element minimum than imin then will update imin to j
        imin = j;
      }
    }
    int temp = a[imin]; //swaping
    a[imin] = a[i];
    a[i] = temp;
  }
}
