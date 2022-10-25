# 사이즈 5개짜리 배열
map = []
for i in range(5):
    map.append(0)

# 2x2 배열
map2 = []
arr = []
for i in range(2):
    line = []
    for j in range(2):
        line.append(0)
        arr.append([i, j])
    map2.append(line)

cnt = 0
# 탐색
def dfs(n, idx):
    if n == 3:
        print(map)
        return

    for i in range(idx, 5):
        map[i] = 1
        dfs(n + 1, i + 1)
        map[i] = 0

def dfs2(n, idx):
    if n == 2:
        print(map2)
        return

    for i in range(idx, 4):
        map[i] = 1
        pos = arr[i]
        map2[pos[0]][pos[1]] = 1

        dfs2(n + 1, i + 1)

        map2[pos[0]][pos[1]] = 0
        map[i] = 0

# dfs(0, 0)
dfs2(0, 0)
