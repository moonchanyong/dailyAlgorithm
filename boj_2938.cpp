#include <iostream>
#include <queue>

using namespace std;



int main() {

  // input
  int n;
  cin >> n;
  queue<int> v0;
  queue<int> v1;
  queue<int> v2;
  

  {
    int temp;
    for (int i = 0; i < n; i++)
    {
      cin >> temp;
      switch (temp % 3)
      {
      case 0:
        v0.push(temp);
        break;
      case 1:
        v1.push(temp);
        break;
      case 2:
        v2.push(temp);
        break;
      }
    }
  } // end input

  // 조건 확인
  if ( v0.size() - 1 > ( v1.size() + v2.size() ) ){
    cout << -1 << endl;
    return 0;
  }
  else if (v1.size() - 1 > (v0.size() + v2.size())) {
    cout << -1 << endl;
    return 0;
  }
  else if (v2.size() - 1 > (v1.size() + v0.size())) {
    cout << -1 << endl;
    return 0;
  }

  // 분기로 배열 만들기 

  if ( v0.size() >= v1.size() && v0.size() >= v2.size() && v0.size()!=0) {
    n = 0;    
    cout << v0.front() << " ";    
    v0.pop();
  }
  else if (v1.size() >= v0.size() && v1.size() >= v2.size() && v1.size() != 0) {
    n = 1;
    cout << v1.front() << " ";
    v1.pop();

  }
  else if (v2.size() >= v1.size() && v2.size() >= v0.size() && v2.size() != 0) {

    n = 2;    
    cout << v2.front() << " ";
    v2.pop();
  }


  while (!v0.empty() || !v1.empty() || v2.empty())
  {
    
  
    

  }

  // 출력

}
