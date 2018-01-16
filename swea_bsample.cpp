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
      i = itRange(i); // ���� ������ ��� ã�� 
      value = fNum[i] - fNum[itRange(i - 1)];

      if (value == 0) { // start ����

        if (answerDigit[itRange(i - 1)] != -1) {// ���� ���ڰ� ������ ������� �˰� ������

          if (answerDigit[itRange(i - 1)] == 1) { // ���� ���� ��        
            if (answerDigit[itRange(i + 3)] != 1) {
              answerDigit[itRange(i + 3)] = 1;
              aNum++;
            }

          }  // end �����̽� 
          else if (answerDigit[itRange(i - 1)] == 0) { // ���� ���� ��� 
            answerDigit[itRange(i + 3)] = 0;

          } // end ������̽�



        } // end �������̽� �ƴ°��
        else if (answerDigit[itRange(i + 3)] != -1) { // ���� ���ڰ� ������ ������� �˰� ������

          if (answerDigit[itRange(i + 3)] != -1) {// ���� ���ڰ� ������ ������� �˰� ������

            if (answerDigit[itRange(i + 3)] == 1) { // ���� ���� ��        
              if (answerDigit[itRange(i - 1)] != 1) {
                answerDigit[itRange(i - 1)] = 1;
                aNum++;
              }

            }  // end �����̽� 
            else if (answerDigit[itRange(i + 3)] == 0) { // ���� ���� ��� 
              answerDigit[itRange(i - 1)] = 0;

            } // end ������̽�


          } // end �������̽� �ƴ°�� 

        }

      } // end if ����
      else if (value > 0) { // ���� 

        if (answerDigit[itRange(i + 3)] != 1)
        {
          answerDigit[itRange(i + 3)] = 1;
          aNum++;
        }

        answerDigit[itRange(i - 1)] = 0;


      }
      else if (value < 0) { // ���� 

        if (answerDigit[itRange(i - 1)] != 1)
        {
          answerDigit[itRange(i - 1)] = 1; // ���� ���� ��
          aNum++;
        }

        answerDigit[itRange(i + 3)] = 0; // ���� ���� ���
      }// end if �������̽�



      i++;

      if (aNum == 4)
        break;

    } //while ���� 

  }  // end value scope

  // ��� query
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