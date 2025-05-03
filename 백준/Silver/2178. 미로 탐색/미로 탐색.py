# 미로 찾기
from collections import deque
import sys

temp = sys.stdin.readline().strip().split(' ')
N = int(temp[0])
M = int(temp[1])
visited = [[0] * (M + 2) for _ in range(N + 2)]
grape = [[0] * (M + 2) for _ in range(N + 2)]

for i in range(1, N + 1):
    # 공백이 없을 때는 split을 빼고 strip만 작성
    grape[i][1:M+1] = list(map(int, sys.stdin.readline().strip()))

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

if(grape[1][1] == 1):
    queue = deque()
    queue.append((1, 1))
    visited[1][1] = 1
    while queue:
        cy, cx = queue.popleft()
        for k in range(4):
            ny, nx = cy + dy[k], cx + dx[k]
            if visited[ny][nx] == 0 and grape[ny][nx] == 1:
                queue.append((ny, nx))
                visited[ny][nx] = visited[cy][cx] + 1


print(visited[N][M])
