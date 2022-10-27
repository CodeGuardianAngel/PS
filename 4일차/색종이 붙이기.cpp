#include <stdio.h>
#include <algorithm>

using namespace std;

struct Pos
{
	int y, x;
};

const int INF = 987654321;
const int MAX = 10;
int paper[MAX][MAX];

int have[5] = { 5,5,5,5,5 };

bool isComplete()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (paper[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

Pos find()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (paper[i][j] == 1) {
				return {i, j};
			}
		}
	}
	return { -1, -1 };
}

bool canCover(int n, int y, int x)
{
	if (have[n] == 0)
		return false;

	n++;	// 0~4 -> 1~5

	// 9 + 1 = 10
	if (y + n > MAX || x + n > MAX)
		return false;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (paper[i + y][j + x] == 0) {
				return false;
			}
		}
	}

	return true;
}

int cover(int n, int y, int x, int data)
{
	n++;	// 0~4 -> 1~5

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			paper[i + y][j + x] = data;
		}
	}

	//1x1 => 1, 2x2 = 4, 3x3 = 9 ...
	return n * n ;

}

int dfs(int n, int count)
{
	// 1. (기저 사례1) 종이에 붙여야 할 곳이 없다.
	if (isComplete() == true)
	{
		return count;
	}

	// 2. 색종이를 붙여야할 좌표를 탐색한다.
	Pos p = find();

	// 3. (기저 사례2)그 좌표가 존재하면, 탐색을 한다.
	if (p.y == -1)
		return INF;

	int ret = INF;
	// 4. 5가지 종류에 대해서 색종이 붙이는 시도를 한다
	// 4 3 2 1 0
	for (int i = 4; i >= 0; --i)
	{
		// 4-1. i 번째 (i x i) 종이를 붙일 수 있는가?
		if (canCover(i, p.y, p.x) == true)
		{
			// 4-2. 붙일 수 있다면, 덮는다.
			cover(i, p.y, p.x, 0);
			have[i]--;
			
			// 4 - 3. 다음 추가적으로 탐색을 한다.
			ret = min(ret, dfs(n + 1, count + 1));

			// 4-4. 복구를 한다.    
			have[i]++;
			cover(i, p.y, p.x, 1);
		}
	}

	return ret;
}

int main()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			scanf("%d", &paper[i][j]);
		}
	}

	int result = dfs(0, 0);
	printf("%d", result == INF ? -1 : result);
}