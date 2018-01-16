#include <iostream>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int test_case = 0; test_case < T; test_case++)
  {


    long long  a, b;
    cin >> a >> b;

    long long temp_a, temp_b ;
    temp_a = a % b;
    if (temp_a  != 0) //a % b
    {
      if (b %temp_a != 0)
      {

        // 1이된다.
        for (int i = 1; i <= 10; i++)
        {        
          
          if (( b*i) % 10 ==temp_a-1 )
          {
             
            cout << "#" << test_case + 1 << " " <<  i << " -"  << ( a * i )/b << endl;
            break;
          }
          temp_a += a % b;
        }
        continue;
      }
    } 


    temp_b = b% a;
    if (temp_b != 0) // b%a;
    {
      if (a %temp_b != 0)
      {

        // 1이된다.
        for (int i = 1; i <= 10; i++)
        {

          if ((a*i) % 10 == temp_b -1)
          {

            cout << "#" << test_case + 1 << " -" << (b*i) / a << " " << i << endl;
            break;
          }
          temp_b += b % a;
        }
        continue;
      }
    }

    cout << "#" << test_case + 1 << " " << -1 << endl;

    
    //unsigned long long  temp_a, temp_b;
    //long long answer_a = 0;
    //long long  answer_b = 0;
    //temp_a = a;
    //temp_b = b;

    //for (int i = 1; i <=  a ; i++)
    //{
    //  if (temp_b%temp_a == 1)
    //  {
    //    answer_a = (temp_b / temp_a);
    //    answer_b = temp_b / b;
    //    answer_a *= -1;
    //    break;
    //  }
    //  temp_b += b;

    //}
    //temp_a = a;
    //temp_b = b;


    //if((answer_a == 0 && answer_b == 0)) // 못찾았을때
    //  for (int i = 1; i <= b; i++)
    //  {
    //    if (temp_a%temp_b == 1)
    //    {
    //      answer_b = (temp_a / temp_b) ;
    //      answer_a = temp_a / a;
    //      answer_b *= -1;

    //      break;
    //    }
    //    temp_a += a;

    //  }




  }
}