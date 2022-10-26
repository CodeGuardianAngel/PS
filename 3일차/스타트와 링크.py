team = []
mat = []

N = int(input())
for i in range(N):
    mat.append(list(map(int, input().split())))
    team.append(0)

def caculate():
    total = [0,0]
    for i in range(N):
        for j in range(i + 1, N):
            if team[i] == team[j]:
                total[team[i]] = total[team[i]] + mat[i][j] + mat[j][i]

    return abs(total[0] - total[1])

def dfs(n, idx):
    if(n == N / 2):
        return caculate()

    ret = 987654321
    for i in range(idx, N):
        team[i] = 1
        ret = min(ret, dfs(n + 1, i + 1))
        team[i] = 0
    return ret

print(dfs(0, 0))
