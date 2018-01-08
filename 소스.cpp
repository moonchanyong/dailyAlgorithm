#include <iostream>
#include <queue>
#include <string>
#include <deque>
using namespace std;

bool map[200][200];

struct node {
	int x, y;
	int xx, yy;
	int size ;

	int cal_size() {
		
		return (xx - x + 1 ) * (yy - y +1);

	}

};
bool check(const node& a, const node& b) {

	if ( ( a.yy < b.y ) || (a.xx < b.x )  ||  (b.yy < a.x ) || (b.xx < a.x)  )
		return 1;
	else
		return 0;

}

struct cmp {
	bool operator()(const node a , const node b  ) {

		return  a.size < b.size ;
	};

};

priority_queue<node, vector<node>, cmp> pq;


int main()
{

	int answer = -1;

	//입력 

	int m, n;

//	cin >> m >> n;
	m = 200;
	n = 200;

	string s;
	s = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
	for (int i = 0; i < m; i++)
	{

//		cin >> s;


		for (int j = 0; j < n; j++)
		{
			if (s[j] == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
			
		}

	}
	// 입력 완료 



	node temp;



	// 영역 중 모든 조각으로 쪼개기 
	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (!map[i][j])
			{
				temp.x = i;
				temp.y = j; 
				int temp_n = n;

				for (int ii = i; ii < m; ii++)
				{
					if (map[ii][j] ) // 아래로 갈때 1 이면 멈춤 
					{
						temp.xx = ii-1;
						temp.yy = j;
						temp.size = temp.cal_size();
						pq.push(temp);
						break;
					}
					else if (ii = m-1)
					{
						temp.xx = ii;
						temp.yy = j;
						temp.size = temp.cal_size();
						pq.push(temp);
					}



					for (int jj = j	; jj < temp_n; jj++)
					{
						if (map[ii][jj]) // 오른쪽으로 갈때 1이면 멈춤 
						{
							temp.xx = ii;
							temp.yy = jj-1;
							temp.size = temp.cal_size();
							pq.push(temp);
							temp_n = jj;
							break;							

						}
						else if (jj = n - 1)
						{

							temp.xx = ii;
							temp.yy = jj;
							temp.size = temp.cal_size();
							pq.push(temp);
							temp_n = n;

						}


						// pq에 조각 넣기 
												

					}




				}

					


			}
			
		}

	}
	// 	모든 사각형조각 삽입 완료 


	deque<node> temp_d;

	

	// 우선순위 큐에서 제일 큰거 꺼내기 	
	while (!pq.empty())
	{		
		temp = pq.top();
		pq.pop();
				
		if (pq.top().size + temp.size <= answer)  // 절대 큰거 없을때
		{
			break;
		}



		// 빼기  
		while(!pq.empty())
		{
			
			

			if (check(temp, pq.top())) // 찾음 
			{





				if (answer < temp.size + pq.top().size)
				{
					answer = temp.size + pq.top().size;
				} 


				break;

				
			}
			else
			{
				temp_d.push_back(pq.top());
				pq.pop();			



			}
			
		}

		// 넣기 


		while (!temp_d.empty())
		{			
			pq.push(temp_d.back());
			temp_d.pop_back();
		}




	}

	
	
	
	cout << answer << endl;
	
	return 0;

}