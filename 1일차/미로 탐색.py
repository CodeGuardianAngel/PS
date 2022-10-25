from collections import deque

N, M = map(int, input().split())

m = []
visit = [[0] * M for i in range(N)]

for i in range(N):
    str = input()
    line = []
    for j in range(M):
        line.append(int(str[j]))
    m.append(line)

q = deque()

q.append([0, 0])

visit[0][0] = 1

dx = [1,-1,0,0,]
dy = [0,0,1,-1]

while len(q):
    cur = q.popleft()

    for d in range(4):
        next = [cur[0] + dy[d], cur[1] + dx[d]]

        if next[0] < 0 or next[1] < 0:
            continue

        if next[0] >= N or next[1] >= M:
            continue

        if m[next[0]][next[1]] == 1 and visit[next[0]][next[1]] == 0:
            visit[next[0]][next[1]] = visit[cur[0]][cur[1]] + 1
            q.append(next)

print(visit[N - 1][M - 1])




