#include <iostream>
#define N 4

using namespace std;

typedef struct {

  int strike;

  int ball;

} Result;
extern Result query(int guess[]);

int itRange(int d) {
  if (d > 9)
    return (d - 10);
  else if (d < 0)
    return (d + 10);
  else
    return d;
}
void setGuess(int guess[], int num0, int num1, int num2, int num3) {

  guess[0] = num0;
  guess[1] = num1;
  guess[2] = num2;
  guess[3] = num3;

  
}

bool findAnswer(int anum ,int bnum,int cnum,int dnum,int guess[]) {

  guess[0] = anum;
  guess[1] = bnum;
  guess[2] = cnum;
  guess[3] = dnum;

  Result temp = query(guess);

  if (temp.strike == 4)
    return true;
  else
    return false;
}



// API






void doUserImplementation(int guess[]) {

  // The array of guess[] is a return array that
  int answerDigit[10]; // if -1 ? 0 no 1 yes
  int aNum = 0; // found digit 
  int fNum[10];
  Result temp;

  // is your guess for what digits[] would be.



  // first filter by 4 size 

  // init 0 1 2 3 
  for (int i = 0; i < 10; i++)
  {
    setGuess(guess, itRange(i), itRange(i + 1), itRange(i + 2), itRange(i + 3));
    temp = query(guess);
    fNum[i] = temp.ball + temp.strike;
  }

  for (int i = 0; i < 10; i++)
  {
    answerDigit[i] = -1;
  }

  { // start value scope 
    int i = 0;
    int value = 0;
    while (aNum != 4)
    {
      i = itRange(i); // 범위 안으로 계속 찾기 
      value = fNum[i] - fNum[itRange(i - 1)];

      if (value == 0) { // start 유지

        if (answerDigit[itRange(i - 1)] != -1) {// 나간 숫자가 답인지 노답인지 알고 있을때

          if (answerDigit[itRange(i - 1)] == 1) { // 나간 숫자 답        
            if (answerDigit[itRange(i + 3)] != 1) {
              answerDigit[itRange(i + 3)] = 1;
              aNum++;
            }

          }  // end 답케이스 
          else if (answerDigit[itRange(i - 1)] == 0) { // 나간 숫자 노답 
            answerDigit[itRange(i + 3)] = 0;

          } // end 노답케이스



        } // end 나간케이스 아는경우
        else if (answerDigit[itRange(i + 3)] != -1) { // 들어온 숫자가 답인지 노답인지 알고 있을때

          if (answerDigit[itRange(i + 3)] != -1) {// 들어온 숫자가 답인지 노답인지 알고 있을때

            if (answerDigit[itRange(i + 3)] == 1) { // 들어온 숫자 답        
              if (answerDigit[itRange(i - 1)] != 1) {
                answerDigit[itRange(i - 1)] = 1;
                aNum++;
              }

            }  // end 답케이스 
            else if (answerDigit[itRange(i + 3)] == 0) { // 들어온 숫자 노답 
              answerDigit[itRange(i - 1)] = 0;

            } // end 노답케이스


          } // end 들어온케이스 아는경우 

        }

      } // end if 유지
      else if (value > 0) { // 증가 

        if (answerDigit[itRange(i + 3)] != 1)
        {
          answerDigit[itRange(i + 3)] = 1;
          aNum++;
        }

        answerDigit[itRange(i - 1)] = 0;


      }
      else if (value < 0) { // 감소 

        if (answerDigit[itRange(i - 1)] != 1)
        {
          answerDigit[itRange(i - 1)] = 1; // 나간 숫자 답
          aNum++;
        }

        answerDigit[itRange(i + 3)] = 0; // 들어온 숫자 노답
      }// end if 감소케이스



      i++;

      if (aNum == 4)
        break;

    } //while 종료 

  }  // end value scope

  // 모든 query
  int answer[4];
  int cursor = 0;
  for (int i = 0; i < 10; i++)
  {
    if (answerDigit[i] == 1) {
      answer[cursor] =i;
      cursor++;
   }

  }

  if (findAnswer(answer[0], answer[1], answer[2], answer[3],guess))
    return;
  if (findAnswer(answer[0], answer[1], answer[3], answer[2], guess))
    return;
  if (findAnswer(answer[0], answer[2], answer[1], answer[3], guess))
    return;
  if (findAnswer(answer[0], answer[2], answer[3], answer[1], guess))
    return;
  if (findAnswer(answer[0], answer[3], answer[2], answer[1], guess))
    return;
  if (findAnswer(answer[0], answer[3], answer[1], answer[2], guess))
    return;
  if (findAnswer(answer[1], answer[0], answer[2], answer[3], guess))
    return;
  if (findAnswer(answer[1], answer[0], answer[3], answer[2], guess))
    return;
  if (findAnswer(answer[1], answer[2], answer[0], answer[3], guess))
    return;
  if (findAnswer(answer[1], answer[2], answer[3], answer[0], guess))
    return;
  if (findAnswer(answer[1], answer[3], answer[0], answer[2], guess))
    return;
  if (findAnswer(answer[1], answer[3], answer[2], answer[0], guess))
    return;
  if (findAnswer(answer[2], answer[0], answer[1], answer[3], guess))
    return;
  if (findAnswer(answer[2], answer[0], answer[3], answer[1], guess))
    return;
  if (findAnswer(answer[2], answer[1], answer[0], answer[3], guess))
    return;
  if (findAnswer(answer[2], answer[1], answer[3], answer[0], guess))
    return;
  if (findAnswer(answer[2], answer[3], answer[0], answer[1], guess))
    return;
  if (findAnswer(answer[2], answer[3], answer[1], answer[0], guess))
    return;
  if (findAnswer(answer[3], answer[0], answer[1], answer[2], guess))
    return;
  if (findAnswer(answer[3], answer[0], answer[2], answer[1], guess))
    return;
  if (findAnswer(answer[3], answer[1], answer[0], answer[2], guess))
    return;
  if (findAnswer(answer[3], answer[1], answer[2], answer[0], guess))
    return;
  if (findAnswer(answer[3], answer[2], answer[0], answer[1], guess))
    return;
  if (findAnswer(answer[3], answer[2], answer[1], answer[0], guess))
    return;


  } // end function