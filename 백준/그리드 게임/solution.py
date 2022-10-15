from collections import deque
import sys

visit = [[0] * 4000 for i in range(4000)]

N, M = map(int,input().split())

queue = deque()
for y in range(0,N):
    str = input()
    for x in range(0,M):
        if str[x] == 'o':
            queue.append([y + 2000, x + 2000])
            visit[y + 2000][x + 2000] = 1
            
K = int(input())

dx = [1,-1,0,0]
dy = [0,0,1,-1]

ret = 0
while K > 0:
    
    count = len(queue)
    ret += count
    
    while count > 0:
        cur = queue.popleft()
        for d in range(0,4):
            next = [cur[0] + dy[d], cur[1] + dx[d]]
            if visit[next[0]][next[1]] == 0:
                visit[next[0]][next[1]] = 1
                queue.append(next)
        
        count = count - 1
    K = K - 1

ret += len(queue)
print(ret)
