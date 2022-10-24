from collections import deque

# 입력을 받는다
N = int(input())

m = []

# dfs
dx = [1,-1,0,0]
dy = [0,0,1,-1]

def dfs(i, j):
    sum = 1
    m[i][j] = 2

    for d in range(4):
        next = [i + dy[d], j + dx[d]]
        if next[0] < 0 or next[1] < 0:
            continue

        if next[0] >= N or next[1] >= N:
            continue

        if m[next[0]][next[1]] == 1:
           sum = sum + dfs(next[0], next[1])

    return sum

# bfs
def bfs(i, j):
    sum = 1
    q = deque()
    q.append([i, j])
    m[i][j] = 2

    while len(q):
        cur = q.popleft()

        for d in range(4):
            next = [cur[0] + dy[d], cur[1] + dx[d]]

            if next[0] < 0 or next[1] < 0:
                continue

            if next[0] >= N or next[1] >= N:
                continue

            if m[next[0]][next[1]] == 1:
                sum = sum + 1
                q.append(next)
                m[next[0]][next[1]] = 2
    return sum

# map 입력을 받는다
for i in range(N):
    str = input()
    line = []
    for j in range(len(str)):
        line.append(int(str[j]))
    m.append(line)


# 전체 탐색을 한다.
ret = []
for i in range(N):
    for j in range(N):
        # 집이 있는 경우
        if m[i][j] == 1:
            # result = dfs(i, j)
            result = bfs(i, j)
            ret.append(result)

# 정렬을 한다
ret.sort()
size = len(ret)

# 결과 출력
print(size)
for i in range(size):
    print(ret[i])