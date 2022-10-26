def isMatch():
    for i in range(N):

        # Strike 체크
        Strike = 0
        for j in range(3):
            if check_num[j] == match[i][0][j]:
                Strike = Strike + 1

        if Strike != match[i][1]:
            return False

        # Ball 체크
        Ball = 0
        if check_num[0] == match[i][0][1] or check_num[0] == match[i][0][2]:
            Ball = Ball + 1

        if check_num[1] == match[i][0][2] or check_num[1] == match[i][0][0]:
            Ball = Ball + 1

        if check_num[2] == match[i][0][0] or check_num[2] == match[i][0][1]:
            Ball = Ball + 1

        if Ball != match[i][2]:
            return False

    return True


def dfs(n):
    if n == 3:
        if isMatch() == True:
            return 1
        return 0

    ret = 0
    for i in range(1, 10):
        if selected[i] == 1:
            continue

        selected[i] = 1
        check_num[n] = i
        ret = ret + dfs(n + 1)
        selected[i] = 0

    return ret

N = int(input())

match = []

for i in range(N):
    num, strike, ball = map(int, input().split())
    n = [0,0,0]
    for j in range(3):
        n[2 - j] = int(num % 10)
        num = int(num/10)
    match.append([n, strike, ball])

selected = []
for i in range(10):
    selected.append(0)

check_num = [0, 0, 0]

print(dfs(0))