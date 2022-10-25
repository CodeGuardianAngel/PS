#include <stdio.h>

// 5개
int map[5];
/*
	n번째 탐색하는 경우
	- 기저 사례(Base Case) -> 무한 탐색
	-
*/
int cnt = 0;
void dfs(int n, int idx)
{
	if (n == 3) {
		cnt++;
		printf("%d 번째 : ", cnt);
		for (int i = 0; i < 5; i++)
			printf("%d ", map[i]);
		printf("\n");
		return;
	}
	
	for (int i = idx; i < 5; i++)
	{
		map[i] = 1;
		dfs(n + 1, i + 1);
		map[i] = 0;
	}
}

/*
	- 기저 사례 : 더이상 쪼개지지 않는 사례(케이스)
	 -> 무한 탐색 방지
	 - n은 n번째 탐색을 의미
	 - idx는 탐색의 시작 위치
*/
void dfs2(int n, int idx)
{
	if (n == 4) {
		
		return;
	}

	for (int i = idx; i < 5; i++)
	{
		map[i] = 1;
		dfs2(n + 1, i + 1);
		map[i] = 0;
	}
}


int map2[2][2];
int cnt2 = 0;
void dfs3(int n, int y, int x)
{
	if (n == 2)
	{
		cnt2++;
		printf("[%d 번째]\n", cnt2);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%d ", map2[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}

	for (int j = x; j < 2; j++)
	{
		if (map2[y][j] == 0) {
			map2[y][j] = 1;
			dfs3(n + 1, y, j);
			map2[y][j] = 0;
		}
	}	
	for (int i = y + 1; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			map2[i][j] = 1;
			dfs3(n + 1, i, j);
			map2[i][j] = 0;
		}
	}	
}

struct Pos
{
	int y, x;
};

#include <vector>
using namespace std;

vector<Pos> arr;
int map3[2][2];
int arr2[2 * 2];

int cnt3;
void dfs4(int n, int idx)
{
	if (n == 2)
	{
		cnt3++;
		printf("[%d 번째]\n", cnt3);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%d ", map3[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}

	for (int i = idx; i < arr.size(); i++)
	{
		arr2[i] = 1;
		Pos pos = arr[i];
		map3[pos.y][pos.x] = 1;

		dfs4(n + 1, i + 1);

		map3[pos.y][pos.x] = 0;
		arr2[i] = 0;
	}
}

int main()
{
	// dfs(0, 0);
	// dfs2(0, 0);
	// dfs3(0, 0, 0);

	// 2차원 -> 1차원
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			arr.push_back({ i, j });
		}
	}
	dfs4(0, 0);
}