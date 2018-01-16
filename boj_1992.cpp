
#include <iostream>
#define FOR(i,j,n)  for(int i = j ; i<(n) ; ++i )

using namespace std;


int check(bool *arr[], int l1, int l2, int r1, int r2) {

  

  int change = arr[l1][l2];

  FOR(i, l1, r1+1) { // l1 <= r1 
    FOR(j, l2, r2 + 1) {
      if ( change != arr[i][j] ) {
        return -1; // 섞여있다.
      }
    }
  }
  return change;  // Only consist of  one value 

}




void recrucive(bool *arr[], int l1, int l2, int r1, int r2) {
  cout << "(";
  int temp;
  
    temp = check(arr, l1, l2, (l1+r1) / 2, (l2+r2) / 2);
    if (temp == -1)
      recrucive(arr, l1, l2, (l1 + r1) / 2, (l2 + r2) / 2);
    else
      cout << temp;
    temp = check(arr, l1, (l2+r2) / 2 + 1, (l1+r1) / 2, r2);
    if (temp == -1)
      recrucive(arr, l1, (l2 + r2) / 2 + 1, (l1 + r1) / 2, r2);
    else
      cout << temp;
    temp = check(arr, (l1+r1) / 2 + 1, l2, r1, (l2+r2) / 2);
    if (temp == -1)
      recrucive(arr, (l1 + r1) / 2 + 1, l2, r1, (l2 + r2) / 2);
    else
      cout << temp;
    temp = check(arr, (l1+r1) / 2 + 1,  (l2+r2) / 2 + 1, r1, r2);
    if (temp == -1)
      recrucive(arr, (l1 + r1) / 2 + 1, (l2 + r2) / 2 + 1, r1, r2);
    else
      cout << temp;


  


  cout << ")";
}





int main() {

  int n;
  cin >> n;
  bool **arr = new bool* [n];
  FOR(i, 0, n) {
    arr[i] = new bool[n];
  }
  char* temp= new char[256];
  FOR(i, 0, n) {
    cin >> temp;
    FOR(j, 0, n) {
      if (temp[j] == '1')
        arr[i][j] = 1;
      else
        arr[i][j] = 0;
    }
  }
  int temp_= check(arr, 0, 0, n-1, n-1);
  if (temp_ != -1) { // -1이 아닌경우 one digit
    cout << temp_;
  }
  else 
  recrucive(arr, 0, 0, n - 1, n - 1);

  return 1;
  }