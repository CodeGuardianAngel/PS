#include <stdio.h>
#include <vector>
#include <algorithm>	// utill, sort, max, min 등
#include <queue>

using namespace std;

int MAX(int a, int b)
{
	return a > b ? a : b;
}

struct Pos
{
	int y, x;
};

vector<Pos> blank;

int N, M;	// 3~8
int map[8][8];

int dx[] = {1,-1, 0,0};
int dy[] = {0,0,1,-1};
void speard_dfs(int m[8][8], int y, int x)
{
	m[y][x] = 3;

	for (int d = 0; d < 4; d++)
	{
		Pos next = {y + dy[d], x + dx[d]};

		if (next.y < 0 || next.x < 0)
			continue;

		if (next.y >= N || next.x >= M)
			continue;

		if (m[next.y][next.x] == 0) {
			speard_dfs(m, next.y, next.x);
		}
	}
}

void spear_bfs(int m[8][8])
{
	queue<Pos> q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// search virus
			if (m[i][j] == 2)
			{
				q.push({ i, j });
				m[i][j] = 3;
			}
		}
	}

	while (q.size())
	{
		Pos cur = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			Pos next = { cur.y + dy[d], cur.x + dx[d] };

			if (next.y < 0 || next.x < 0)
				continue;
			if (next.y >= N || next.x >= M)
				continue;

			if (m[next.y][next.x] == 0)
			{
				m[next.y][next.x] = 3;
				q.push(next);
			}
		}
	}
}

int simulate()
{
	int m[8][8];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			m[i][j] = map[i][j];
		}
	}

#if 0
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// search virus
			if (m[i][j] == 2)
			{
				// speard
				speard_dfs(m, i, j);
			}
		}
	}
#endif
	spear_bfs(m);
	
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (m[i][j] == 0)
			{
				count++;
			}
		}
	}
	return count;

}

int dfs(int n, int idx)
{
	if (n == 3)
	{
		return simulate();
	}

	int ret = 0;
	for (int i = idx; i < blank.size(); ++i)
	{
		Pos p = blank[i];
		map[p.y][p.x] = 1;
		ret = max(ret, dfs(n + 1, i + 1));
		map[p.y][p.x] = 0;
	}	
	return ret;
}

int dfs2(int n, int y, int x)
{
	if (n == 3)
	{
		return simulate();
	}

	/*
		0011
	    1111
	*/
	int ret = 0;
	for (int j = x; j < M; j++)
	{
		if (map[y][j] == 0)
		{
			map[y][j] = 1;
			ret = max(ret, dfs2(n + 1, y, j + 1));
			map[y][j] = 0;
		}
	}

	for (int i = y + 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				ret = max(ret, dfs2(n + 1, i, j + 1));
				map[i][j] = 0;
			}
		}
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
			//if (map[i][j] == 0)
			//{
			//	// blank.push_back({i, j});
			//}
		}
	}
	/// 

	int result = dfs2(0, 0, 0);
	printf("%d", result);
}