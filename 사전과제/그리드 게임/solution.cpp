#include <stdio.h>
#include <queue>

using namespace std;

struct Pos
{
	int y, x;
};

int N, M;

const int MAX = 5000;

int map[MAX][MAX];

int main()
{
	// N, M 입력
	scanf("%d %d", &N, &M);

	queue<Pos> q;
	// K = 0초일때,	queue 넣어서 초기상태를 만든다.
	for (int i = 0; i < N; i++)
	{
		char str[255];
		scanf("%s", &str);
		for (int j = 0; j < M; j++)
		{
			if (str[j] == 'o')
			{
				map[i + 2000][j + 2000] = 1;
				q.push({i + 2000, j + 2000 });
			}
		}
	}
	int K;
	scanf("%d", &K);

	int dx[4] = {+1,-1,+0,+0};
	int dy[4] = {+0,+0,+1,-1};

	int total_live = 0;
	while (K)
	{
		int count = q.size();
		total_live += count;

		while (count)
		{
			Pos cur = q.front();
			q.pop();

			for (int d = 0; d < 4; d++)
			{
				Pos next = { cur.y + dy[d], cur.x + dx[d] };
				if (map[next.y][next.x] == 0)
				{
					map[next.y][next.x] = 1;
					q.push(next);
				}
			}
			count--;
		}
		K--;
	}

	total_live += q.size();
	printf("%d", total_live);
}
