#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAX = 20;

int N;
int S[MAX][MAX];

int team[MAX];
void print()
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", team[i]);
	}
	printf("\n");
}

int caculate()
{
	// 0번 사람이랑 같은 팀의 계산
	// int sum[2] = {0, 0};
	int team1 = 0;
	int team2 = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			// 같은 팀인지 체크
			if (team[i] == team[j]) {

				// team의 번호 체크
				if (team[i] == 0)
				{
					team1 += S[i][j] + S[j][i];
				}
				else // team[i] == 1
				{
					team2 += S[i][j] + S[j][i];
				}
			}
		}
	}

	// 차이를 리턴
	return abs(team1 - team2);
}

int dfs(int n, int start)
{
	if (n == N / 2)
	{
		// print();
		return caculate();
	}
	// S : 1~100 (100 * 2) * 10  = 
	// int ret = 987654321;
	int ret = 0x7fff'ffff;	// int에서 가장 큰 양수값
	for (int i = start; i < N; i++)
	{
		team[i] = 1;
		ret = min(ret, dfs(n + 1, i + 1));
		team[i] = 0;
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &S[i][j]);
		}
	}
	int result = dfs(0, 0);
	printf("%d", result);
}