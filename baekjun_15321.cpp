#include <iostream>
#include <algorithm>
#include "AlgoritmSuport.h"


using namespace std;


int arr[500];
unsigned int uiResult = 0;


void remove (int num, int size )
{
  if (arr[num] > arr[num + 1]) {
      
    
    memmove(arr + num+1, arr + num+ 2, ( size  - num) * sizeof(int));
    

  }
  else {

    
    memmove(arr + num , arr + num + 1, (size - num -1) * sizeof(int));

  }
    

}

int compare(int a, int b)
{
  return a < b? b : a;
}
int diff(int a, int b)
{
  return a < b ? b-a : a-b;
}

int unsign(int a)
{
  return (a < 0) ? -1 * a : a;
}

int main()
{
  int minimum;
  int n;
  //참가자 수
  cin >> n;
  
  {
    int temp;
    for (int i = 0; i < n ; i++)
    {
      cin >> arr[i];
    }
  }

  
  
 
  for (int i = 0; i < n-1; i++)
  {
    minimum = 0;

    for (int j = 0; j < n-i -1; j++)
    {
      
      if (compare(arr[minimum], arr[minimum + 1]) > compare(arr[j], arr[j + 1]))
      {
          minimum = j;
      }

    }
    
    uiResult += diff(arr[minimum], arr[minimum + 1]);
    
    remove(minimum, n-i);


  }

  cout << uiResult << endl;

  return 0;
}