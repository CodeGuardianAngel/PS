#include <stdio.h>
#include <queue>

using namespace std;

struct Pos
{
	int y, x, dist;
};

const int MAX = 100;
int N, M;

int map[MAX][MAX];
int visit[MAX][MAX];

int main()
{
	/*
	(1,1) -> (N,M)

	4 6

	  012345
	0 101111
	1 101010
	2 101011
	3 111111

	4 6
	101111
	101010
	101011
	111111
	*/

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	// BFS
	queue<Pos> q;
	q.push({ 0,0, 1});
	visit[0][0] = 1;

	int dx[4] = { 1,-1,0,0 };
	int dy[4] = { 0,0,1,-1 };

	int result;

	while (q.size())
	{
		Pos cur = q.front();
		q.pop();

		//
		if (cur.y == N - 1 && cur.x == M - 1) {
			//result = cur.dist;
			break;
		}

		for (int d = 0; d < 4; d++)
		{
			Pos next = { cur.y + dy[d], cur.x + dx[d] };

			// 범위 체크
			if (next.y < 0 || next.x < 0)
				continue;

			if (next.y >= N || next.x >= M)
				continue;

			if (visit[next.y][next.x] == 0 && map[next.y][next.x] == 1)
			{
				visit[next.y][next.x] = visit[cur.y][cur.x] + 1;
				// visit[next.y][next.x] = 1;
				next.dist = cur.dist + 1;
				q.push(next);
			}
		}
	}

	// 경단 경로
	printf("%d", visit[N - 1][M - 1]);
	// printf("%d", result);
}
