#include <stdio.h>
#include <stdlib.h>

void quicksort(int left, int right, int * a ) {

  int hole = left;
  int pivot = a[hole];
  
  // the way it works is we going from left to right
  // and we shove all the lesser < pivot ones to the left of the hole
  // we accomplish that by putting smaller element into the hole and moving hole to the right
  // and the end of the pass all the smaller to the left of the hole 
  //and all the bigger ones are to the right of the hole
  for(int i = left + 1; i <= right; i++) {
    // put all the < pivot to the left of the hole
    if ( a[i] <=  pivot ) {
      a[hole] = a[i];
      // move the element to the right of the hole into i
      // now hole is to the right were it used to be
      // so the lesser element now to the left of the hole
      a[i] = a[++hole];
    }
  }

  a[hole] = pivot;

  if ( right - hole > 1 ) 
    quicksort(hole+1,right,a);

  if ( hole - left > 1 ) 
    quicksort(left,hole-1,a);

}


int main(int argc,char* argv[]) {
  int nelems = argc-1; // excluding program name
  int * a = malloc(sizeof(int)*nelems);
  for(int i = 0; i < nelems; i++) {
    a[i] = atoi(argv[i+1]);
  }
  quicksort(0,nelems-1,a);
  for(int i=0; i < nelems;i++) {
   printf("%d",a[i]);
   if (i < (nelems-1)) printf(" ");
  }
  printf("\n");
}

