#include <stdio.h>
#include <vector>

using namespace std;

struct BaseBall
{
	int number[3];
	int strike;
	int ball;
};

int N;
vector<BaseBall> db;

int select[10];
int number[3];
int cnt = 0;

bool isMatch()
{
	/*
	4
	123 1 1
	356 1 0
	327 2 0
	489 0 1
	*/
	for (int i = 0; i < db.size(); i++)
	{
#if 0
		// strike
		// 같은 자릿수 && 같은 숫자 =>
		int strike = 0;
		if (number[0] == db[i].number[0])
			strike++;
		if (number[1] == db[i].number[1])
			strike++;
		if (number[2] == db[i].number[2])
			strike++;

		if (strike != db[i].strike)
			return false;

		// Ball
		// 같은 자릿수가 아닌데 같은 숫자
		int ball = 0;
		if (number[0] == db[i].number[1] || number[0] == db[i].number[2])
			ball++;
		if (number[1] == db[i].number[0] || number[1] == db[i].number[2])
			ball++;
		if (number[2] == db[i].number[0] || number[2] == db[i].number[1])
			ball++;

		if (ball != db[i].ball)
			return false;
#endif
		// strike
		// 같은 자릿수 && 같은 숫자 =>		
		// Ball
		// 같은 자릿수가 아닌데 같은 숫자
		int strike = 0;
		int ball = 0;

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (j == k) {
					if (number[j] == db[i].number[k])
						strike++;
				}
				else
				{
					if (number[j] == db[i].number[k])
						ball++;
				}
			}
		}

		if (strike != db[i].strike || ball != db[i].ball)
			return false;
	}

	return true;
}

int dfs(int n)
{
	if (n == 3)
	{
		if (isMatch() == true) {
			cnt++;
			return 1;
		}
		return 0;
	}
	
	int ret = 0;
	for (int i = 1; i <= 9; i++)
	{
		if (select[i] == 0) {
			select[i] = 1;
			number[n] = i;
			ret += dfs(n + 1);
			select[i] = 0;
		}
	}
	return ret;
}

/*
	0~9

	012
	013
	019
	...
	102
	...
	201
	...
	...
	987

*/

int dfs2(int n)
{
	if (n == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			printf("%d ", number[i]);
		}
		printf("\n");		
		return 0;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (select[i] == 0) {
			select[i] = 1;
			number[n] = i;
			dfs2(n + 1);

			select[i] = 0;
		}
	}

	return 0;
}




int main()
{
	
	//dfs2(0);

	//return 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		BaseBall data;
		int num;
		/*
		scanf("%d %d %d", &num, &data.strike, &data.ball);

		// 123 % 10 = 3
		// num /= 10 => 12 % 10 =2
		for (int j = 2; j >=0 ; --j)
		{
			data.number[j] = num % 10;
			num /= 10;
		}
		*/
		scanf("%1d%1d%1d %d %d", &data.number[0], &data.number[1], &data.number[2], &data.strike, &data.ball);

		db.push_back(data);
	}
	/*

	*/
	int result = dfs(0);
	// printf("%d", cnt);
	printf("%d", result);
}