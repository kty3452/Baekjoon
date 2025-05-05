# 토마토(3차원)

from collections import deque
import sys

M, N, H = map(int, sys.stdin.readline().strip().split())
grape = [[[-1] * (M + 2) for _ in range(N + 2)] for _ in range(H + 2)]
dy = [0, 0, 1, -1, 0, 0]
dx = [1, -1, 0, 0, 0, 0]
dz = [0, 0, 0, 0, 1, -1]
ny, nx = 0, 0
max_count = 0
start_is_one = []

for i in range(1, H + 1):
    for j in range(1, N + 1):
        grape[i][j][1:M+1] = list(map(int, sys.stdin.readline().strip().split()))
        start_is_one.extend((i, j, k) for k, val in enumerate(grape[i][j][1:M+1], start=1) if val == 1)

queue = deque(start_is_one)
while queue:
    cz, cy, cx = queue.popleft()
    for k in range(6):
        nz, ny, nx = cz + dz[k], cy + dy[k], cx + dx[k]
        if grape[nz][ny][nx] == 0:
            grape[nz][ny][nx] = grape[cz][cy][cx] + 1
            max_count = max(max_count, grape[nz][ny][nx] - 1)
            queue.append((nz, ny, nx))

    
for i in range(1, H + 1):
    for j in range(1, N + 1):
        if 0 in grape[i][j][1:M+1]:
            print(-1)    
            exit()
print(max_count)