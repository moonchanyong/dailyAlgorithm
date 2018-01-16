//#include <iostream>
//
//using namespace std;
//
//char **inputData = new char*[2000];
//
//bool*  oneSentence;
//
//// 2진수 변환 모듈 
// void convertTobi(char *data, int length )
//{
//
//  oneSentence = new bool[length * 4];
//  
//  for (int i = 0; i < length; i++)
//  {
//
//    for(int j = 0 ; j < 4 ; j++)    
//      switch (data[i]) {
//        case '0': 
//          oneSentence[ 4 * i ] = 0;
//          oneSentence[4 * i +1] = 0;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case '1':
//          oneSentence[4 * i] = 0;
//          oneSentence[4 * i + 1] = 0;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 1;
//          break;
//        case '2':
//          oneSentence[4 * i] = 0;
//          oneSentence[4 * i + 1] = 0;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case '3':
//          oneSentence[4 * i] = 0;
//          oneSentence[4 * i + 1] = 0;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 1;
//          break;
//        case '4':
//          oneSentence[4 * i] = 0;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case '5':
//          oneSentence[4 * i] = 0;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 1;
//          break;
//        case '6':
//          oneSentence[4 * i] = 0;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case '7':
//          oneSentence[4 * i] = 0;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 1;
//          break;
//        case '8':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 0;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case '9':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 0;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 1;
//          break;
//        case 'A':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 0;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case 'B':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 0;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 1;
//          break;
//        case 'C':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case 'D':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 0;
//          oneSentence[4 * i + 3] = 1;
//          break;
//        case 'E':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 0;
//          break;
//        case 'F':
//          oneSentence[4 * i] = 1;
//          oneSentence[4 * i + 1] = 1;
//          oneSentence[4 * i + 2] = 1;
//          oneSentence[4 * i + 3] = 1;
//          break;
//
//    }
//    
//  }
//  
//    
//}
//
//
//// 코드 파싱 모듈 
////  필터 크기별로 파싱 해주면 된다. 
//void parse(int fillterSize ) {
//  
//  int code = 0;
//  int combinationa = 0;
//  int combinationb = 0;
//  int combinationc = 0;
//  int combinationd = 0;
//
//  for (int i = 0; i < fillterSize * 56; i++)
//  {
//
//    if (i % (7*fillterSize) == 6 ) { // 숫자 4개로  코드의 한자리 숫자 나옴 
//      
//
//    }
//      
//
//      
//  }
//
//
//}
//
//
//
//// 코드 검증 모듈 
//bool  inspect(int a) { // 8자리 숫자 받음 
//  
//  int sum = 0;
//  int code = 0;
//  
//  code = a % 10;
//  
//  for (int i = 0; i < 7; i++)
//  {
//    a /= 10; 
//    if (i % 2 != 0)
//    {
//      sum += (a % 10) *3;
//      
//    }
//    else {
//      sum += a % 3;
//    }
//
//  }
//  
//  return  ((10 - (sum % 10)) == code);
//
//}
//
//
//
//int main() {
//
//  int T; 
//  cin >> T;
//
//  int N, M;
//  cin >> N >> M;
//
//  for (int i = 0; i < N; i++)
//  {
//    inputData[i] = new char[M];
//  }
//
//  for (int i = 0; i < N; i++)
//  {
//    cin >> inputData[i];    
//  }
//    
//
//
//  /*   for (int i = 0; i < N; i++)
//  {
//    convertTobi(inputData[i],M);
//    for (int j = 0; j < 4*M; j++)
//    {
//      cout << oneSentence[j] ;
//    }
//    cout << "\n";
//  }*/
//
//
//  return 0;
//}