#define _CRT_SECURE_NO_WARNINGS

#if 1
#include <stdio.h>		// 입출력 용
#include <vector>		// array list
#include <queue>		// BFS
#include <algorithm>	// 유틸적인 함수(sort, max, min)

using namespace std;	// standard

const int MAX = 25;

int N;
int map[MAX][MAX];

/*
	2가지
	1) 현재 위치에서 해야될 일 ->
	2) 기저 사례 -> 무한 호출이 안되기 위해 필요
*/
int dx[] = { +1, -1, +0, +0 };
int dy[] = { +0, +0, +1, -1 };

int dfs(int y, int x)
{
	int sum = 1;

	// 이미 서치한 것을 표시
	map[y][x] = 2;

	
	for (int d = 0; d < 4; d++)
	{
		int next_y = y + dy[d];
		int next_x = x + dx[d];

		// 범위 체크
		if (next_y < 0 || next_x < 0)
			continue;
		
		if (next_y >= N || next_x >= N)
			continue;

		// 1인 경우 집인 경우체크
		if(map[next_y][next_x] == 1)
		{
			sum += dfs(next_y, next_x);
		}
	}
	return sum;
}

struct Pos
{
	int y, x;
};

int bfs(int y, int x)
{
	int sum = 1;
	
	queue<Pos> q;
	q.push({y, x});
	map[y][x] = 2;

	// while (q.empty())
	while (q.size())
	{
		Pos cur = q.front();
		q.pop();

		for (int d = 0; d < 4; d++)
		{
			int next_y = cur.y + dy[d];
			int next_x = cur.x + dx[d];

			// 범위 체크
			if (next_y < 0 || next_x < 0)
				continue;

			if (next_y >= N || next_x >= N)
				continue;

			// 1인 경우 집인 경우체크
			if (map[next_y][next_x] == 1)
			{
				map[next_y][next_x] = 2;
				q.push({next_y, next_x});
				sum++;
			}
		}
	}
	return sum;
}

int main()
{
	// N 입력 받는다.
	scanf("%d", &N);

	// map 입력을 받는다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	// 전체 탐색을 한다.
	// array list => 배열로 구현 
	// linke list => Node pointer
	vector<int> ret;
	// int ret[MAX * MAX];
	// int ridx = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 집이 있는 경우
			if(map[i][j] == 1)
			{
				// 같은 그룹으로 묶여 있는 집들을 찾는다.
				// int result = dfs(i, j);
				int result = bfs(i, j);
				// 결과에 그룹의 수를 추가한다.
				ret.push_back(result);
				// ret[ridx++] = result;
			}
		}
	}

	// 오름차순으로 정렬한다.
	sort(ret.begin(), ret.end());
	// sort(&ret[0] , &ret[ridx]);
	/*
	출력부분에 대한 질문이 있는데 c 같은 경우는 그냥 printf 해서 출력 하는데    
	c++은  ret.size 라고 해서 사이즈를 출력(?) 하는 부분이 있는데 
	그러고  for 문돌려서 출력을 해야하는건가요?
	*/
	// 출력
	printf("%d\n", ret.size());
	// printf("%d\n", ridx);
	for (int i = 0; i < ret.size(); i++)
	{
		printf("%d\n", ret[i]);
	}
}
#endif
