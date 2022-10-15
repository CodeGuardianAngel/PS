#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
	int y, x;
};

const int MAX = 1600 * 2;
char visit[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, K;

	cin >> N >> M;

	Pos start = { 1600, 1600 };
	queue<Pos> q;

	char ch;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> ch;
			
			if (ch == 'o')
			{
				Pos p = { y + start.y, x + start.x };
                visit[p.y][p.x] = 1;
				q.push(p);
			}
		}
	}

	// 마지막 줄에는 K (1 ≤ K ≤ 1500)가 주어진다.
	cin >> K;

	const int dir[4][2] = {
		{+1,+0}, {-1,+0},
		{+0,+1}, {+0,-1},
	};

	int ret = 0;
	while (K--)
	{
		int count = q.size()+1;
		ret += count-1;
		while(--count)
		{
			Pos cur = q.front();
			q.pop();
			
			Pos next = { cur.y + dir[0][0], cur.x + dir[0][1] };
			if (visit[next.y][next.x] == 0) {
				visit[next.y][next.x] = 1;
				q.push(next);
			}

			next = { cur.y + dir[1][0], cur.x + dir[1][1] };
			if (visit[next.y][next.x] == 0) {
				visit[next.y][next.x] = 1;
				q.push(next);
			}

			next = { cur.y + dir[2][0], cur.x + dir[2][1] };
			if (visit[next.y][next.x] == 0) {
				visit[next.y][next.x] = 1;
				q.push(next);
			}

			next = { cur.y + dir[3][0], cur.x + dir[3][1] };
			if (visit[next.y][next.x] == 0) {
				visit[next.y][next.x] = 1;
				q.push(next);
			}
		}
	}

	ret += q.size();
	cout << ret << "\n";
}
