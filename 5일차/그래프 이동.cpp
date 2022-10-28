#include <stdio.h>
#include <queue>

using namespace std;

const int MAX = 21;

// N : 노드의 수, K : 경로의 수
int N, K;
int mat[MAX][MAX];	// 인접 배열
int visit[MAX];		// 방문에 대한 체크 : 1 -> 2, 2 -> 1 X

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; i++)
	{
		int to, from;
		scanf("%d %d", &from, &to);

		// from → to
		// to -> from
		mat[to][from] = 1;	// 1인경우 가는 경우
		mat[from][to] = 1;
	}

	// 1 번의 거리를 구한다.
	queue<int> q;
	q.push(1);

	visit[1] = 1;

	while (q.size())
	{
		int cur = q.front();
		q.pop();

		// 다음 탐색 경로를 검색합니다.
		for (int next = 1; next <= N; next++)
		{
			// cur -> next로 갈수 있고 && 방문을 안한 노드라면,
			if (mat[cur][next] == 1 && visit[next] == 0) {
				// 다음 거리 = 현재 거리 + 1
				visit[next] = visit[cur] + 1;	// 방문했다. (= 더 이상 방문하지마)
				q.push(next);
			}
		}
	}
}
