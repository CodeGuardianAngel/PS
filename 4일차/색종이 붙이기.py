paper = []
for i in range(10):
    paper.append(list(map(int, input().split())))

have = []
for i in range(5):
    have.append(5)

coverCount = 0
for i in range(10):
    for j in range(10):
        if paper[i][j] == 1:
            coverCount = coverCount + 1

def canCover(n, y, x):
    if have[n] == 0:
        return False

    n = n + 1

    if y + n > 10 or x + n > 10:
        return False

    for i in range(n):
        for j in range(n):
            if paper[i + y][j + x] == 0:
                return False
    return True

def find():
    for i in range(10):
        for j in range(10):
            if paper[i][j] == 1:
                return i, j
    return -1, -1

def cover(n, y, x, data):
    n = n + 1
    for i in range(n):
        for j in range(n):
            paper[i + y][j + x] = data

    return n * n

result = 100
def dfs(count):
    global result, coverCount
    if coverCount == 0:
        result = min(count, result)
        return

    if count > result:
        return

    y, x = find()

    if y == -1:
        return

    for i in range(5):
        if canCover(4 - i, y, x) == True:
            coverCount = coverCount - cover(4 - i, y, x, 0)
            have[4 - i] = have[4 - i] - 1
            dfs(count + 1)
            have[4 - i] = have[4 - i] + 1
            coverCount = coverCount + cover(4 - i, y, x, 1)


dfs(0)

if result == 100:
    print(-1)
else:
    print(result)