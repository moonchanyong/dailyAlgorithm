#include <string.h>

#define FOR(i,j,n)  for(int i = j ; i<(n) ; ++i ) //for문 쉽고 빠르게 !! 



static void removeElementAtArry(int *arr, int index, int size)
{
  // #include string.h
  memmove(arr + index, arr + index + 1, (size - index - 1) * sizeof(int));

}




