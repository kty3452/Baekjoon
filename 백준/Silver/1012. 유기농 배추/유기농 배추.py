# 유기농 배추

import sys
from collections import deque

T = int(sys.stdin.readline().strip())
dxy = [(0, 1), (0, -1), (1, 0), (-1, 0)]

for i in range(T):    
    M, N, K = map(int, sys.stdin.readline().strip().split())
    visited = [[0] * (M + 2) for _ in range(N + 2)]
    graph = [[0] * (M + 2) for _ in range(N + 2)]
    count = 0
    for j in range(K):
        x, y = map(int, sys.stdin.readline().strip().split())
        graph[y + 1][x + 1] = 1

    for y in range(1, N + 1):
        for x in range(1, M + 1):
            if graph[y][x] and not visited[y][x]:
                visited[y][x] = 1
                queue = deque([(y, x)])
                count += 1
                while queue:    
                    cy, cx = queue.popleft() 
                    for dy, dx in dxy:
                        ny, nx = cy + dy, cx + dx
                        if  graph[ny][nx] and not visited[ny][nx]:
                            visited[ny][nx] = 1
                            queue.append((ny, nx))
    print(count)