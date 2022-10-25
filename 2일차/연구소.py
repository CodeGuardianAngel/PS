N, M = map(int, input().split())

m = []

dx = [1,-1,0,0]
dy = [0,0,1,-1]

def dfs(m2, y, x):
    m2[y][x] = 1

    for d in range(4):
        next = [y + dy[d], x + dx[d]]

        if next[0] < 0 or next[1] < 0:
            continue
        if next[0] >= N or next[1] >= M:
            continue

        if m2[next[0]][next[1]] == 0:
            dfs(m2, next[0], next[1])

def simulate():
    m2 = [[0] * M for i in range(N)]

    for i in range(N):
        for j in range(M):
            m2[i][j] = m[i][j]

    for i in range(N):
        for j in range(M):
            if m2[i][j] == 2:
                dfs(m2, i, j)

    cnt = 0
    for i in range(N):
        for j in range(M):
            if m2[i][j] == 0:
                cnt = cnt + 1

    return cnt


def search(n, y, x):
    if n == 3:
        return simulate()

    ret = 0
    for j in range(x, M):
        if m[y][j] == 0:
            m[y][j] = 1
            ret = max(ret, search(n + 1, y, j))
            m[y][j] = 0

    for i in range(y + 1, N):
        for j in range(M):
            if m[i][j] == 0:
                m[i][j] = 1
                ret = max(ret, search(n + 1, y, j))
                m[i][j] = 0

    return ret

for i in range(N):
    m.append(list(map(int, input().split())))

print(search(0, 0, 0))


