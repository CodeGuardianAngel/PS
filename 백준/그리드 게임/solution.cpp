#include <iostream>
#include <queue>

using namespace std;

struct Pos
{
	int x, y;
};

const int MAX = 2000 * 2;

bool visit[MAX][MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M;

    Pos start = { 2000,2000 };
	queue<Pos> q;

	char ch;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> ch;
			Pos p = { start.x + x, y + start.y };

			if (ch == 'o')
			{
				visit[p.y][p.x] = 1;
				q.push(p);
			}
		}
	}

	cin >> K;

	const int dir[4][2] = {
		{+1,+0}, {-1,+0},
		{+0,+1}, {+0,-1},
	};

	int ret = 0;
	while (K--)
	{
		int count = q.size();
		ret += count;

		while (count--)
		{
			Pos cur = q.front();
			q.pop();

			for (int d = 0; d < 4; d++)
			{
				Pos next = { cur.x + dir[d][1], cur.y + dir[d][0] };
				if (visit[next.y][next.x] == 0) {
					visit[next.y][next.x] = 1;
					q.push(next);
				}
			}
		}
	}

	ret += q.size();
	cout << ret;
}
