from collections import deque

N, K = map(int, input().split())

# 인접 배열
mat = [[0] * (N+1) for i in range(N + 1)]

# 방문 정보
visit = []
for i in range(N + 1):
    visit.append(0)

for i in range(K):
    a, b = map(int, input().split())
    mat[b][a] = mat[a][b] = 1

# BFS
q = deque()
q.append(1)
visit[1] = 1

while len(q):
    cur = q.popleft()

    # 다음 이동경로 탐색
    for next in range(N + 1):
        # 현재에서 다음으로 이동 가능한 경로 이고, 방문한적이 없으면
        if mat[cur][next] == 1 and visit[next] == 0:
            # 거리를 추가로 더해주고, 다음 거리 = 현재 거리 + 1
            visit[next] = visit[cur] + 1
            q.append(next)

# 전체 거리 출력
for i in range (1, N + 1):
    print(visit[i] - 1)
