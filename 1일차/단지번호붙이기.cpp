#define _CRT_SECURE_NO_WARNINGS

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int MAX = 100'000;

int origin[MAX];
int arr1[MAX];
int arr2[MAX];	// 4 * 100'000 byte = 390.625 Kbyte = 0.38 MByte

void selection_sort(int arr[], int size)
{
	// Big(N * N) = O(N^2) => 100'000 * 100'000 = 100억 -> (10억 1초)
	// N개
	for (int i = 0; i < size; i++)
	{
		// 5개
		int min_val = arr[i];
		int min_idx = i;

		// N - 1 => N
		for (int j = i + 1; j < MAX; j++)
		{
			// 4개
			if (min_val > arr[j])
			{
				min_val = arr[j];
				min_idx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

int temp_arr[MAX];
// O(N Log N) => 100'000 * 17 = 1,700,000
void merge(int arr[], int left, int right)
{
	int mid = (left + right) / 2;
	int k = left;
	int i = left, j = mid + 1;
	int e1 = mid;
	int e2 = right;

	while (i <= e1 && j <= e2)
	{
		if (arr[i] > arr[j])
		{
			temp_arr[k] = arr[j];
			j++;
		}
		else
		{
			temp_arr[k] = arr[i];
			i++;
		}
		k++;
	}

	while (i <= e1)
	{
		temp_arr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e2)
	{
		temp_arr[k] = arr[j];
		j++;
		k++;
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = temp_arr[i];
	}
}

void divide(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		divide(arr, left, mid);
		divide(arr, mid + 1, right);
		merge(arr, left, right);
	}
}

void merge_sort(int arr[], int size)
{
	divide(arr, 0, size - 1);
}


int main()
{
	for (int i = 0; i < MAX; i++)
	{
		origin[i] = rand() % 100;
		arr1[i] = arr2[i] = origin[i];
		// printf("%d ", origin[i]);
	}
	printf("\n");

	time_t pre, end;
	printf("=== selection sort ===\n");
	pre = clock();
	// selection_sort(arr1, MAX);
	end = clock() - pre;
	printf("%d\n", end);



	printf("%d", sizeof(arr1));

	//for (int i = 0; i < MAX; i++)
	//{
	//	printf("%d ", arr1[i]);
	//}

	printf("\n");
	printf("=== merge sort ===\n");
	pre = clock();
	merge_sort(arr2, MAX);
	end = clock() - pre;
	printf("%d\n", end);
	/*for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr2[i]);
	}*/
}
#endif

#if 0
#include <stdio.h>

/*
	n = 1 -> 1
	sum[n] = sum[n - 1] + n;

	sum[n] = sum[n + 1] + n;
*/
int sum_func(int n)
{
	if (n == 1)
		return 1;
	return sum_func(n - 1) + n;
}

int sum_func2(int n, int N)
{
	if (n == N)
		return n;
	return sum_func2(n + 1, N) + n;
}

/*
	n! = 1 x ... x n

	fact[n] = fact[n - 1] * n

	n == 1 -> 1
*/
int factorial(int n)
{
	if (n == 1)
		return 1;
	return factorial(n - 1) * n;
}

/*
	a^N % 1'000'000'007를 구하라
	제약 조건 : a는 1~100, N은 1~100억
	1초 이내 동작

	pow[N] = pow[N - 1] * a
	N == 1 => a

	100억 => 10억 1초 => 10초
*/
const int MOD = 1e9 + 7;
int pow(int a, int n)
{
	if (n == 1)
		return a;
	return (pow(a, n - 1) * a) % MOD;
}

/*
	N 짝수
		- a^N = (a*a)^(N/2)

	N 홀수
		- a^N = (a*a)^(N/2) * a

	정수 / 정수 = 정수
	11 / 2 = 10
*/
int pow2(int a, int n)
{
	if (n == 1)
		return a;

	int b = a * a % MOD;
	if (n % 2 == 0)
	{
		return (pow2(b, n / 2)) % MOD;
	}
	else
	{
		return (pow2(b, n / 2) * a) % MOD;
	}
}

int pow3(int a, int n)
{
	int ret = 1;

	while (n)
	{
		if (n % 2 == 1)
		{
			ret = ret * a;
		}
		a = a * a;
		n /= 2;
	}
	return ret;
}

int main()
{
#if 0
	int N = 100;
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		sum += i;
	}

	/*
		int -> 4byte = 32 bit 2^32 => (-2^31 ~ 2^31 - 1)
	*/

	printf("%d %d %d", sum, sum_func(N), sum_func2(1, N));

	int fac = 1;
	N = 10;
	for (int i = 1; i <= N; i++)
	{
		fac = fac * i;
	}

	printf("%d %d", fac, factorial(N));
#endif

	printf("%d", pow3(2, 10));
}
#endif

#if 0
#include <stdio.h>

const int MAX = 100000;
int seive[MAX];

/*
	유클리드 호제법
	- gcd(a,b) = gcd(b, r) r은 a를 b로 나눈 나머지
	r == 0 -> b
*/
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{
#if 0
	int N = 100;
	for (int i = 2; i <= N; i++)
	{
		if (seive[i])
			continue;

		for (int j = i * i; j <= N; j += i)
		{
			seive[j] = 1;
		}
	}

	for (int i = 2; i <= N; i++)
	{
		if (seive[i])
			continue;

		printf("%d ", i);
	}
#endif
	printf("%d\n", gcd(3, 6));
	printf("%d\n", gcd(8, 12));

}
#endif

#if 0
/*
 강사님 const int MAX = 100;
 define MAX(100) 의 차이가 뭔가요 ?
*/
#define MAX (100)
// const int MAX = 100;

int array[MAX];
// int array[(100)];

int main()
{
	// MAX = MAX + 1;
}
#endif

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